#include "buffer.h"

Buffer::Buffer(int initBuffSize): buffer_(initBuffSize), readPos_(0), writePos_(0) 
{
    assert(ReadableBytes() == 0);
    assert(WritableBytes() == initBuffSize);
    assert(PrependableBytes() == 0);
}

size_t Buffer::WritableBytes() const
{
    return buffer_.size() - writePos_;
}

size_t Buffer::ReadableBytes() const
{
    return writePos_ - readPos_;
}

size_t Buffer::PrependableBytes() const
{
    return readPos_;
}

const char *Buffer::Peek() const
{
    return BeginPtr_() + readPos_;
}

void Buffer::EnsureWriteable(size_t len)
{
    if(WritableBytes() < len)
    {
        MakeSpace_(len);
    }
    assert(WritableBytes() >= len);
}

void Buffer::HasWritten(size_t len)
{
    writePos_ += len;
}

void Buffer::Retrieve(size_t len)
{
    assert(len <= ReadableBytes());
    readPos_ += len;
    // writePos_ -= len;
}

void Buffer::RetrieveUntil(const char *end)
{
    assert(Peek() <= end);
    Retrieve(end - Peek());
}

void Buffer::RetrieveAll()
{
    bzero(&buffer_[0], buffer_.size());
    readPos_ = 0;
    writePos_ = 0;   
}

std::string Buffer::RetrieveAllToStr()
{
    std::string str(Peek(), ReadableBytes());
    RetrieveAll();
    return str;
}
//  常量调用，只可读，不可写
const char *Buffer::BeginWriteConst() const 
{
    return BeginPtr_() + writePos_;
}
// 变量调用，可写
char *Buffer::BeginWrite() 
{
    return BeginPtr_() + writePos_;
}
// 向缓冲区添加字符串
void Buffer::Append(const std::string &str)
{
    Append(str.data(), str.length());
}
// 向缓冲区添加len个字符
void Buffer::Append(const char *str, size_t len)
{
    assert(str);
    EnsureWriteable(len);
    std::copy(str, str+len, BeginWrite());
    HasWritten(len);
}
// 向缓冲区添加len个数据（需指定数据的类型）
void Buffer::Append(const void *data, size_t len)
{
    assert(data);
    Append(static_cast<const char*>(data), len);
}
// 向缓冲区中添加buff缓冲区的内容
void Buffer::Append(const Buffer &buff)
{
    Append(buff.Peek(), buff.ReadableBytes());
}
// 将文件读入缓冲区
ssize_t Buffer::ReadFd(int fd, int *Errno)
{
    char buff[65535];
    struct iovec iov[2];
    const size_t writeable = WritableBytes();
    // 分散读文件，将文件读入两个iov数组中，保证数据能全部读完
    iov[0].iov_base = BeginPtr_() + writePos_;
    iov[0].iov_len = writeable;
    iov[1].iov_base = buff;
    iov[1].iov_len = sizeof(buff);
    const ssize_t len = readv(fd, iov, 2);
    if(len < 0)
    {
        *Errno = errno;
    }
    else if(static_cast<size_t>(len) <= writeable)
    {
        writePos_ += len;
    }
    else
    {
        writePos_ = buffer_.size();
        Append(buff, len - writeable);
    }
    return len;
}
// 将缓冲区的数据写入文件中
ssize_t Buffer::WriteFd(int fd, int *Errno)
{
    size_t readSize = ReadableBytes();
    ssize_t len = write(fd, Peek(), readSize);
    if(len < 0)
    {
        *Errno = errno;
        return 0;
    }
    readPos_ += len;
    return len;
}

char *Buffer::BeginPtr_()
{
    return &*buffer_.begin();
}

const char *Buffer::BeginPtr_() const
{
    return &*buffer_.begin();
}

// buffer的自动增长在这里体现
void Buffer::MakeSpace_(size_t len)
{
    // 剩余空间不足len, 则直接扩大buffer的大小
    if(WritableBytes() + PrependableBytes() < len)
    {
        buffer_.resize(writePos_ + len + 1);
    }
    // 剩余空间大于len,移动可读数据到最前面
    else
    {
        size_t readable = ReadableBytes();
        std::copy(BeginPtr_() + readPos_, BeginPtr_() + writePos_, BeginPtr_());
        readPos_ = 0;
        writePos_ = readPos_ + readable;
        assert(readable == ReadableBytes());
    }
}

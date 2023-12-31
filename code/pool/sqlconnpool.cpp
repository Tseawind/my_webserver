#include "sqlconnpool.h"
using namespace std;

SqlConnPool *SqlConnPool::Instance()
{
    static SqlConnPool connPool;
    return &connPool;
}

MYSQL *SqlConnPool::GetConn()
{
    MYSQL *sql = nullptr;
    if(connQue_.empty())
    {
        LOG_WARN("sqlconnpool busy!");
        return nullptr;
    }
    sem_wait(&semId_);
    lock_guard<mutex> locker(mtx_);
    sql = connQue_.front();
    connQue_.pop();
    return sql;
}

void SqlConnPool::FreeConn(MYSQL *conn)
{
    assert(conn);
    lock_guard<mutex> locker(mtx_);
    connQue_.push(conn);
    sem_post(&semId_);
}

int SqlConnPool::GetFreeConnCount()
{
    lock_guard<mutex> locker(mtx_); // 加锁的目的是防止读过程中写入
    return connQue_.size();
}

void SqlConnPool::Init(const char *host, int port, const char *user, 
        const char *pwd, const char *dbName, int connSize = 10)
{
    assert(connSize > 0);
    for(int i = 0; i < connSize; i++)
    {
        MYSQL *sql = nullptr;
        sql = mysql_init(sql);
        if(!sql)
        {
            LOG_ERROR("mysql init error!")
            assert(sql);
        }
        sql = mysql_real_connect(sql, host, user, pwd, dbName, port, nullptr, 0);
        if(!sql)
        {
            LOG_ERROR("mysql connect error!")
        }
        MAX_CONN_ = connSize;
        sem_init(&semId_, 0, MAX_CONN_);
    }
}

void SqlConnPool::ClosePool()
{
    lock_guard<mutex> locker(mtx_);
    while(!connQue_.empty())
    {
        auto item = connQue_.front();
        connQue_.pop();
        mysql_close(item);
    }
    mysql_library_end();
}

SqlConnPool::SqlConnPool()
{
    useCount_ = 0;
    freeCount_ = 0;
}

SqlConnPool::~SqlConnPool()
{
    ClosePool();
}

#ifndef THREADPOOL_H
#define THREADPOOL_H
#include <bits/stdc++.h> // 万能头文件
#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>
#include <functional>
class ThreadPool {
public:
    // explicit关键字，必须显示调用，不能隐式调用
    explicit ThreadPool(size_t threadCount);

    ThreadPool() = default;  //默认构造函数

    ThreadPool(ThreadPool&&) = default; // 拷贝构造函数

    ThreadPool& operator = (const ThreadPool& other) = delete;
    
    ~ThreadPool();

    template<class F>
    void AddTask(F&& task);

private:
    struct Pool {
        std::mutex mtx;
        std::condition_variable cond;
        bool isClosed;
        std::queue<std::function<void()>> tasks;
    };
    std::shared_ptr<Pool> pool_;  // 类比于Pool* pool_ 使用智能指针可以更有效的管理内存资源
};

ThreadPool::ThreadPool(size_t threadCount = 8):pool_(std::make_shared<Pool>())
{
    assert(threadCount > 0);
    for(size_t i = 0; i < threadCount; i++)
    {
        // 每个进程池的处理逻辑
        std::thread([pool = pool_]
        {
            std::unique_lock<std::mutex> locker(pool->mtx);
            while(true)
            {
                if(!pool->tasks.empty())
                {
                    auto task = std::move(pool->tasks.front());
                    pool->tasks.pop();
                    locker.unlock();
                    task();
                    locker.lock();
                }
                else if(pool->isClosed) break;
                else pool->cond.wait(locker);
            }
        }).detach();
    }
}

ThreadPool::~ThreadPool()
{
    if(static_cast<bool>(pool_))
    {
        {
            std::lock_guard<std::mutex> locker(pool_->mtx);
            pool_->isClosed = true;
        }
        pool_->cond.notify_all();
    }
}

template <class F>
inline void ThreadPool::AddTask(F &&task)
{
    {
        std::lock_guard<std::mutex> locker(pool_->mtx);
        pool_->tasks.emplace(std::forward<F>(task));
    }
    pool_->cond.notify_one();
}
#endif //THREADPOOL_H

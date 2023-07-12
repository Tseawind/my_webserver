// 获取数据库池中的一个数据库
// CSDN->MyWebserver采用的是shared_ptr来实现RALL机制
// RALL机制：对象在创建时调用构造函数，在离开作用域时调用析构函数
#ifndef SQLCONNRALL_H
#define SQLCONNRALL_H
#include "sqlconnpool.h"

class sqlconnRAll
{
public:
    sqlconnRAll(MYSQL** sql, SqlConnPool *connpool)
    {
        assert(connpool);
        *sql = connpool->GetConn();
        sql_ = *sql;
        connpool_ = connpool;
    }

    ~sqlconnRAll()
    {
        if(sql_)
        {
            connpool_->FreeConn(sql_);
        }
    }

private:
    MYSQL* sql_;
    SqlConnPool* connpool_;
};

#endif
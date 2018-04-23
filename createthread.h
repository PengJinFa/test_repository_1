#ifndef CREATETHREAD_H
#define CREATETHREAD_H
#include <future>
#include<thread>
#include<QDebug>
#include<utility>
#include<functional>
#include<chrono>
#include"global.h"

class CreateThread
{
public:
    CreateThread();
    ~CreateThread();
    void go();
private:
    std::thread _thread;
   // static void ThreadFun(CreateThread* this,std::promise<bool> &promiseObj);
    static void ThreadFun(std::promise<int> &promiseObj);
public:
    static void ThreadFun1();
};

#endif // CREATETHREAD_H

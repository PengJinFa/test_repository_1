#include "createthread.h"


CreateThread::CreateThread()
{
    //global_variable=100;
    qDebug()<<"global variable="<<global_variable;
    qDebug()<<"global variable2="<<global_variable2;
}

CreateThread::~CreateThread()
{
    _thread.join();
}


void CreateThread::go()
{
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future();

    _thread = std::thread(ThreadFun, std::ref(promiseObj));


    std::chrono::milliseconds span(100);
    while (futureObj.wait_for(span)==std::future_status::timeout)
    {
         qDebug()<<"*";
    }
    int sum=futureObj.get();
    qDebug()<<"sum="<<sum;
   // _thread=std::thread(ThreadFun1);

}

void CreateThread::ThreadFun(std::promise<int> &promiseObj)
{
    int sum=0;
    for(int i=0;i<111111;i++)
    {
        sum+=i;
        qDebug()<<i;
    }
    promiseObj.set_value(sum);
}

void CreateThread::ThreadFun1()
{

    for(int i=0;i<1111111;i++)
    {
       qDebug()<<i;
    }
}

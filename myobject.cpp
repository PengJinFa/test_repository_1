#include "myobject.h"
#include<QThread>
#include<QDebug>
#include"mainwindow.h"
#include"createthread.h"

MyObject::MyObject()
{

}

MyObject::~MyObject()
{

}

void MyObject::on_btn_click()
{
    qDebug()<<"Thread t2 id:"<<this->thread()->currentThreadId();
    CreateThread::ThreadFun1();
    //MainWindow::TestMyObject();
//    MainWindow mw;
//    mw.TestMyObject();
}


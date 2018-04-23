#include "mainwindow.h"
#include "ui_mainwindow.h"

#include"createthread.h"
#include"myobject.h"
#include<QThread>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"Main thread id:"<<this->thread()->currentThreadId();
    QThread * t2=new QThread();
    t2->start();

    MyObject * obj1=new MyObject();
    //把对象移动到新线程
    obj1->moveToThread(t2);

    //连接到对象
    QObject::connect(this->ui->pushButton_4,SIGNAL(clicked()),obj1,SLOT(on_btn_click()));
}

MainWindow::~MainWindow()
{
    _myThread.join();
    delete ui;
}

void MainWindow::TestThread(MainWindow* mw,std::promise<int>& prom)
{
    int sum=0;
    mw->ui->textEdit->append("start");
    for(int i=0;i<111111;i++)
    {
        qDebug()<<"mainwindow::TestThread"<<i;
        sum+=i;

        //ui->textEdit->append(QString::number(i));
    }
    mw->ui->textEdit->append("end");
    prom.set_value(sum);
}

void MainWindow::TestThread1(MainWindow *mw)
{
    int sum=0;
    mw->ui->textEdit->append("start");
    for(int i=0;i<111111;i++)
    {
        qDebug()<<"mainwindow"<<i;
        sum+=i;
    }
    mw->ui->textEdit->append("end");

}

void MainWindow::TestMyObject()
{
   ui->textEdit->append("test");

}


void MainWindow::on_pushButton_clicked()
{
    global_variable=11;
    global_variable2=true;
    CreateThread ct;
    ct.go();
}

void MainWindow::on_pushButton_2_clicked()
{
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future();
    _myThread=std::thread(TestThread,this,std::ref(promiseObj));

   std::chrono::milliseconds span(100);
   while (futureObj.wait_for(span)==std::future_status::timeout)
   {
        ui->textEdit->append("*");
   }
   int sum=futureObj.get();
   ui->textEdit->append(QString::number(sum));

}

void MainWindow::on_pushButton_3_clicked()
{
     _myThread=std::thread(TestThread1,this);
}





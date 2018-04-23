#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <future>
#include<thread>
#include<QDebug>
#include<utility>
#include<functional>
#include<chrono>
#include"global.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static void TestThread(MainWindow* mw,std::promise<int>& prom);
    static void TestThread1(MainWindow* mw);
    void TestMyObject();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


private:
    Ui::MainWindow *ui;
    std::thread _myThread;
};

#endif // MAINWINDOW_H

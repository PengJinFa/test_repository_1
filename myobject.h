#ifndef MYOBJECT_H
#define MYOBJECT_H

#include<QObject>

class MyObject:public QObject
{
    Q_OBJECT
public:
    MyObject();
    ~MyObject();
 public slots:
    void on_btn_click();
};
#endif // MYOBJECT_H

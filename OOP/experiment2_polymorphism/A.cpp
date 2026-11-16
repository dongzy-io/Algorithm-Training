#include <iostream>
using namespace std;

class B {
public:
    virtual void f1(double x)
    {
        cout<<"B::f1(double)"<<x<<'\n';
    }
    void f2(double x)
    {
        cout<<"B::f2(double)"<<2*x<<'\n';
    }
    void f3(double x)
    {
        cout<<"B::f3(double)"<<3*x<<'\n';
    }
};

class D : public B{
public:
    virtual void f1(double x)
    {
        cout<<"D::f1(double)"<<x<<'\n';
    }
    void f2(int x)
    {
        cout<<"D::f2(int)"<<2*x<<'\n';
    }
    void f3(double x)
    {
        cout<<"D::f3(double)"<<3*x<<'\n';
    }
};

int main()
{
    D d;
    B* pb=&d;
    D* pd=&d;
    pb->f1(1.23);   // 派生类中的f1函数
    pd->f1(1.23);   // 派生类中的f1函数
    pb->f2(1.23);   // 基类中的f2函数
    pb->f3(1.23);   // 基类中的f3函数 
    pd->f3(3.14);   // 派生类中的f3函数
    return 0;
}

/*
D::f1(double)1.23
D::f1(double)1.23
B::f2(double)2.46
B::f3(double)3.69
D::f3(double)9.42
*/
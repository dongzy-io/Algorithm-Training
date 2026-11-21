#include <iostream>
using namespace std;

const double PI=3.14159265358979;

class container 
{                           
    protected:
        double radius;

    public:
        container(double r) : radius(r) {}
        virtual double surface_area()=0;      
        virtual double volume()=0;            
        virtual ~container() {}                 
};

class cube : public container
{             
    public:
        cube(double a);
        double surface_area() override { 
            return 6.0*radius*radius; 
        }
        double volume()override {
            return radius*radius*radius; 
        }
};

cube::cube(double a): container(a) {}

class sphere : public container 
{           
    public:
        sphere(double r) : container(r) {}
        double surface_area() override{ 
            return 4*PI*radius*radius; 
        }
        double volume() override{ 
            return 4.0/3*PI*radius*radius*radius; 
        }
};

class cylinder : public container 
{        
    private:
        double height;
    public:
        cylinder(double r, double h) : container(r), height(h) {}
        double surface_area() override{
            return 2*PI*radius*(radius+height); 
        }
        double volume() override{ 
            return PI*radius*radius*height; 
        }
};

int main()
{
    container* p;
    cube c(6.0);
    sphere s(5.0);
    cylinder cy(5.0, 6.0);
    p=&c;
    cout<<"正方体：表面积="<<p->surface_area()<<"，体积="<<p->volume()<<'\n';
    p = &s;
    cout<<"球体：表面积="<<p->surface_area()<<"，体积="<<p->volume()<<'\n';
    p=&cy;
    cout<<"圆柱体：表面积="<<p->surface_area()<<"，体积="<<p->volume()<<'\n';
    return 0;
}
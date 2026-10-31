#include<bits/stdc++.h>
using namespace std;

class Coordinate
{
    private:
        int x,y;
    public:
        explicit Coordinate(int x1, int y1){
            x=x1;
            y=y1;
            cout<<"Constructor is called.\n";
        }

        Coordinate(Coordinate &p);
        ~Coordinate(){
            cout<<"Destructor is called.\n";
        }

        int getx(){
            return x;
        }

        int gety(){
            return y;
        }
};

Coordinate::Coordinate(Coordinate &p){
    x=p.x;
    y=p.y;
    cout<<"Copy-initialization constructor is called.\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Coordinate p1(3,4);
    Coordinate p2(p1);
    Coordinate p3=p2;//copy initialization
    cout<<"p3=("<<p3.getx()<<","<<p3.gety()<<")\n";
    Coordinate p4;
    Coordinate p5(2);//lack arg? or rvalue unmatched
    return 0;
}

/*
Copy-initialization constructor is called
Copy-initialization constructor is called
p3=(3,4)
Destructor is called
Destructor is called
Destructor is called
*/

/*
Constructor is called.
Copy-initialization constructor is called.
Copy-initialization constructor is called.
p3=(3,4)
Destructor is called.
Destructor is called.
Destructor is called.
*/

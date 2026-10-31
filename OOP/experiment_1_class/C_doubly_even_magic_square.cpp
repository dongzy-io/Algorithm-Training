#include<bits/stdc++.h>
using namespace std;

class magic
{
    public:
        void getdata();          
        void setfirstmagic();   
        void generatemagic();   
        void printmagic();     
    private:
        int m[4][4];
        int step;        
        int first;            
        int sum;               
};

void magic::getdata()
{
    cin>>first>>step;
}

void magic::setfirstmagic()
{
    int v=first;
    for(int i=0; i<4; i++)
        for(int j=0; j<4;j++){
            m[i][j]=v;
            v+=step;
        }
}

void magic::generatemagic()
{
    sum=m[0][0]+m[3][3];   
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i==j)
                m[i][j]=sum-m[i][j]; 
            if(i+j==3)               
                m[i][j]=sum-m[i][j];
        }         
    }
}

void magic::printmagic()
{
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            cout<<setw(4)<<m[i][j];
        cout<<"\n";
    }
}

int main()
{
    magic a;
    a.getdata();
    a.setfirstmagic();
    a.generatemagic();
    a.printmagic();
    return 0;
}
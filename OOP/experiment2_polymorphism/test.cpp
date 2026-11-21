#include<bits/stdc++.h>
using namespace std;

class B{
    public:
        int func1(){
            return 3;
        }
};

class D: public B{
    public:
        double func1(){
            return 3.1;
        }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    D ob;
    cout<<ob.func1();
    return 0;
}
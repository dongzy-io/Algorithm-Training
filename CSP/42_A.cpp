#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> normal;
    vector<int> banker;
    while(n--){
        int x,y; 
        double num;
        cin>>num;
        int integer=floor(num);
        double decimal_part=num-integer;
        if(decimal_part<0.5){
            x=y=integer;
        }else if(decimal_part>0.5){
            x=y=integer+1;
        }else{
            x=integer+1;
            if(integer&1)
                y=integer+1;
            else
                y=integer;
        }
        normal.emplace_back(x);
        banker.emplace_back(y);
    }
    for(auto x: normal){
        cout<<x<<" ";
    }
    cout<<'\n';
    for(auto x: banker){
        cout<<x<<" ";
    }
    return 0;
}
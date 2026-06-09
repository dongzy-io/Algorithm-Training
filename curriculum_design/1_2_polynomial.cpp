#include<bits/stdc++.h>
using namespace std;

map<int,int> sum;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    bool isB=false;
    int coef, exp;
    char comon;
    while(true){
        cin>>coef>>exp;
        if(!coef){
            if(isB){
                break;
            }
            isB=true;
            continue;
        }   
        cin>>comon;     
        sum[exp]+=coef;
    }
    for(auto t:sum){
        if(!t.second)
            continue;
        cout<<" "<<t.second<<" "<<t.first<<",";
    }
    return 0;
}
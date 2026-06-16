#include<bits/stdc++.h>
using namespace std;

int op[3]={1,-1,2};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin>>a>>b;
    queue<pair<int,int>> path; //pos steps
    path.emplace(a,0);
    while(!path.empty()){
        auto p=path.front();
        path.pop();
        int pos=p.first;
        int steps=p.second;
        if(pos==b){
            cout<<steps;
            break;
        }
        for(int i=0;i<3;i++){
            int temp;
            if(i!=2){
                temp=pos+op[i];
            }else{
                temp=pos*2;
            }
            path.emplace(temp,steps+1);
        }
    }
    return 0;
}
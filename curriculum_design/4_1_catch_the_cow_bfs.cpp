#include<bits/stdc++.h>
using namespace std;

int op[3]={1,-1,2};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin>>a>>b;
    int ans=numeric_limits<int>::max();
    queue<pair<int,int>> path; //pos steps
    path.emplace(a,0);
    while(!path.empty()){
        auto p=path.front();
        path.pop();
        int pos=p.first;
        int steps=p.second;
        if(pos==b){
            ans=min(ans,steps);
            continue;
        }
        if(p.second>=ans){
            continue;
        }
        for(int i=0;i<3;i++){
            if(i!=2){
                path.emplace(pos+op[i],steps+1);
            }else   
                path.emplace(pos*2,steps+1);
        }
    }
    cout<<ans;
    return 0;
}
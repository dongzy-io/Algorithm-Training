#include<bits/stdc++.h>
using namespace std;

int op[3]={1,-1,2};
bool isVisited[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin>>a>>b;
    memset(isVisited,0,sizeof(isVisited));
    isVisited[a]=true;
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
            int temp;
            if(i!=2){
                temp=pos+op[i];
            }else{
                temp=pos*2;
            }
            if(!isVisited[temp]){
                isVisited[temp]=true;
                path.emplace(temp,steps+1);
            }
        }
    }
    cout<<ans;
    return 0;
}
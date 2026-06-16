#include<bits/stdc++.h>
using namespace std;

vector<string> models;
vector<bool> isVisited;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //dist index
int ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    models.resize(n);
    isVisited.assign(n,false);
    pq.emplace(0,0);
    for(int i=0;i<n;i++){
        if(i==n-1)
            cin>>models[i];
        else
            getline(cin>>ws,models[i],',');
        models[i]=models[i].substr(0,7);
    }
    while(!pq.empty()){
        auto m=pq.top();
        pq.pop();
        int dist=m.first;
        int index=m.second;
        if(isVisited[index]){
            continue;
        }
        isVisited[index]=true;
        ans+=dist;
        for(int i=0;i<n;i++){   
            if(!isVisited[i]){
                int cnt=0;
                for(int j=0;j<7;j++){
                    if(models[index][j]!=models[i][j])
                        cnt++;
                }
                pq.emplace(cnt,i);
            }
        }
    }
    cout<<ans;
    return 0;
}
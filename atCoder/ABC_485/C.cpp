#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> dist;
    bool isFirst=true;
    int curr=0,prev;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(isFirst){
            isFirst=false;
            curr++;
            prev=x;
            continue;
        }
        if(x==prev)
            curr++;
        else{
            dist.emplace_back(curr);
            curr=1;
            prev=x;
        }
    }   
    dist.emplace_back(curr);
    int m=dist.size();
    for(int i=0;i<m;i++){
        if(!i){
            for(int j=0;j<dist[i];j++)
                cout<<dist[i]-j<<" ";
        }else if(i==m-1){
            for(int j=0;j<dist[i];j++)
                cout<<j+1<<" ";
        }else{
            for(int j=0;j<dist[i]/2;j++)
                cout<<j+1<<" ";
            for(int j=dist[i]/2;j<dist[i];j++)
                cout<<dist[i]-j<<" ";
        }
    }          
    return 0;
}
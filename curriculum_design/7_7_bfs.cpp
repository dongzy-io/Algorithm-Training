//   --version 1.0
// naive born to be the shortest path
#include<bits/stdc++.h>
using namespace std;

bool isFinished;
int N,M;
int dest_x,dest_y;
int wall_cnt;
vector<vector<bool>> isVisited;
vector<vector<bool>> isBlocked;
queue<pair<int,int>> q; 
stack<pair<int,int>> path;
vector<vector<pair<int,int>>> preGrid;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    cin>>dest_x>>dest_y;
    isVisited.assign(N,vector<bool>(M,false));
    isBlocked.assign(N,vector<bool>(M,false));
    preGrid.assign(N,vector<pair<int,int>>(M,{-1,-1}));
    cin>>wall_cnt;
    for(int i=0;i<wall_cnt;i++){
        int x,y;
        cin>>x>>y;
        isBlocked[x][y]=true;
    }
    isVisited[0][0]=true;
    q.emplace(0,0);    
    while(!q.empty()){
        auto curr=q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int x=curr.first+dx[i];
            int y=curr.second+dy[i];
            if(x<0||x>=N||y<0||y>=M||isVisited[x][y]||isBlocked[x][y]){
                continue;
            }
            isVisited[x][y]=true;
            q.emplace(x,y);
            preGrid[x][y]=curr;
            if(x==dest_x&&y==dest_y){
                isFinished=true;
                break;
            }
        } 
        if(isFinished){
            break;
        }
    }
    if(isFinished){
        cout<<"reachable"<<'\n';
        auto curr=make_pair(dest_x,dest_y);
        while(curr != pair<int,int>{-1,-1}){
            path.emplace(curr);
            curr=preGrid[curr.first][curr.second];
        }
        while(!path.empty()){
            cout<<path.top().first<<" "<<path.top().second<<'\n';
            path.pop();
        }
    }else{
        cout<<"beyond reach";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

bool isFinished;
int N,M;
int dest_x,dest_y;
int wall_cnt;
vector<vector<bool>> isBlocked;
vector<vector<bool>> isVisited;
deque<pair<int,int>> path;
int dx[]={0,0,1,1,1,-1,-1,-1};
int dy[]={1,-1,1,0,-1,1,0,-1};

void dfs(int x,int y)
{
    if(x<0||x>=N||y<0||y>=M||isVisited[x][y]||isBlocked[x][y]){
        return ;
    }   
    path.emplace_back(x,y);
    isVisited[x][y]=true;
    if(x==dest_x&&y==dest_y){
        isFinished=true;
        return ;
    }
    for(int i=0;i<8;i++){
        dfs(x+dx[i],y+dy[i]);
        if(isFinished)
            return ;
    }
    path.pop_back();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    dest_x=N-1;
    dest_y=M-1;
    cin>>wall_cnt;
    isBlocked.assign(N,vector<bool>(M,false));
    isVisited.assign(N,vector<bool>(M,false));
    for(int i=0;i<wall_cnt;i++){
        int x,y;
        cin>>x>>y;
        isBlocked[x][y]=true;
    }
    dfs(0,0);
    if(!isFinished){
        cout<<"unreachable";
    }else{
        cout<<"available"<<'\n';
        while(!path.empty()){
            cout<<path.front().first<<" "<<path.front().second<<"\n";
            path.pop_front();
        }
    }
    return 0;
}
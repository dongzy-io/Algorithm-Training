// Note that a mouse departing from (0,0) 
// memoization 
// When it comes to connectivity, dfs and bfs share the same efficiency 
#include<bits/stdc++.h>
using namespace std;

int N,M;
int wall_num;
int dest_x, dest_y;
bool isFinished;
deque<pair<int,int>> path;
vector<vector<bool>> isBlocked;
vector<vector<bool>> isVisited; 
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void dfs(int x, int y)
{
    if(x<0||x>=N||y<0||y>=M||isBlocked[x][y]||isVisited[x][y]){
        return ;
    }
    isVisited[x][y]=true;
    path.emplace_back(x,y);
    if(x==dest_x&&y==dest_y){
        isFinished=true;
        return ;
    }
    for(int i=0;i<4;i++){
        int next_x=x+dx[i];
        int next_y=y+dy[i];
        dfs(next_x, next_y);
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
    isBlocked.assign(N,vector<bool>(M,false));
    isVisited.assign(N,vector<bool>(M,false));
    cin>>wall_num;
    for(int i=0;i<wall_num;i++){
        int x,y;
        cin>>x>>y;
        isBlocked[x][y]=true;
    }
    cin>>dest_x>>dest_y;
    dfs(0,0);
    if(isFinished){
        cout<<"reachable";
        while(!path.empty()){
            cout<<path.front().first<<" "<<path.front().second<<'\n';
            path.pop_front();
        }
    }else{
        cout<<"unavailable";
    }
    return 0; 
}
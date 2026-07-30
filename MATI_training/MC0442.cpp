#include<bits/stdc++.h>
using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int cnt=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<bool>> isBlocked(n,vector<bool>(m,false));
    vector<vector<bool>> Available(n,vector<bool>(m,false));
    //vector<vector<bool>> isVisited(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            if(c=='#')
                isBlocked[i][j]=true;
        }
    }
    queue<pair<int,int>> flood;
    for(int i=0;i<m;i++){
        if(!isBlocked[0][i]&&!Available[0][i]){
            flood.emplace(0,i);
            Available[0][i]=true;
            cnt++;
        }
    }
    for(int i=0;i<m;i++){
        if(!isBlocked[n-1][i]&&!Available[n-1][i]){
            flood.emplace(n-1,i);
            Available[n-1][i]=true;
            cnt++;
        }
    }
    for(int i=0;i<n;i++){
        if(!isBlocked[i][0]&&!Available[i][0]){
            flood.emplace(i,0);
            Available[i][0]=true;
            cnt++;
        }
    }
    for(int i=0;i<n;i++){
        if(!isBlocked[i][m-1]&&!Available[i][m-1]){
            flood.emplace(i,m-1);
            Available[i][m-1]=true;
            cnt++;
        }
    }
    while(!flood.empty()){
        int curr_x=flood.front().first;
        int curr_y=flood.front().second;
        flood.pop();
        for(int i=0;i<4;i++){
            int x=curr_x+dx[i];
            int y=curr_y+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m&&!isBlocked[x][y]&&!Available[x][y]){
                Available[x][y]=true;
                flood.emplace(x,y);
                cnt++;
            }
        }
    }
    while(q--){
        queue<pair<int,int>> flood;
        bool on_the_edge=false;
        int target_x,target_y;
        cin>>target_x>>target_y;
        target_x--; target_y--;
        if(!isBlocked[target_x][target_y]){
            cout<<cnt<<'\n';;
            continue;
        }
        isBlocked[target_x][target_y]=false;
        if(target_x==0||target_x==n-1||target_y==0||target_y==m-1){
            on_the_edge=true;
            goto next;
        }
        for(int i=0;i<4;i++){
            int x=target_x+dx[i];
            int y=target_y+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m&&Available[x][y]){
                on_the_edge=true;
                break;
            }
        }
        next:
        if(on_the_edge){
            Available[target_x][target_y]=true;
            cnt++;
            flood.emplace(target_x,target_y);
            while(!flood.empty()){
                int curr_x=flood.front().first;
                int curr_y=flood.front().second;
                flood.pop();
                for(int i=0;i<4;i++){
                    int x=curr_x+dx[i];
                    int y=curr_y+dy[i];
                    if(x>=0&&x<n&&y>=0&&y<m&&!isBlocked[x][y]&&!Available[x][y]){
                        Available[x][y]=true;
                        flood.emplace(x,y);
                        cnt++;
                    }
                }
            }
        }
        cout<<cnt<<'\n';
    }
}
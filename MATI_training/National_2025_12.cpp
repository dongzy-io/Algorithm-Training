#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,q;
    int state=0;
    cin>>n>>m>>q;
    vector<vector<int>> grid(n,vector<int>(n,0));
    vector<vector<int>> stamp(m,vector<int>(m,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            if(c=='#')
                stamp[i][j]=1;
            else
                stamp[i][j]=0;
        }
    }
    while(q--){
        int opt;
        cin>>opt;
        if(opt==1){
            state=(state+1)%4;
        }else{
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            switch (state) {
                case 0:
                    for(int i=0;i<m;i++){
                        for(int j=0;j<m;j++){
                            grid[x+i][y+j]+=stamp[i][j];
                        }
                    }
                    break;
                case 1:
                    for(int i=0;i<m;i++){
                        for(int j=0;j<m;j++){
                            grid[x+i][y+j]+=stamp[m-j-1][i];
                        }
                    }
                    break;
                case 2:
                    for(int i=0;i<m;i++){
                        for(int j=0;j<m;j++){
                            grid[x+i][y+j]+=stamp[m-i-1][m-j-1];
                        }
                    }
                    break;
                case 3:
                    for(int i=0;i<m;i++){
                        for(int j=0;j<m;j++){
                            grid[x+i][y+j]+=stamp[j][m-i-1];
                        }
                    }
                    break;
            }
        }
    }
    for(auto r : grid){
        for(auto x: r){
            cout<<x<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
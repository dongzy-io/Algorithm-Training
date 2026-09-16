#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,q;
    cin>>n>>k>>q;
    vector<vector<char>> grid(n,vector<char>(n));
    for(auto &r: grid){
        for(auto &c: r){
            cin>>c;
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        vector<vector<char>> temp(k,vector<char>(k));
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                temp[j][k-1-i]=grid[x+i][y+j];
            }
        }
        for(int i=x;i<x+k;i++){
            for(int j=y;j<y+k;j++){
                grid[i][j]=temp[i-x][j-y];
            }
        }
    }
    for(auto r: grid){
        for(auto x: r){
            cout<<x;
        }
        cout<<'\n';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<char>> grid(n,vector<char>(m,'#'));
    while(k--){
        int a,b;
        cin>>a>>b;
        a--; b--;
        grid[a][b]='.';
    }
    for(auto row: grid){
        for(auto c: row){
            cout<<c;
        }
        cout<<'\n';
    }
    return 0;
}
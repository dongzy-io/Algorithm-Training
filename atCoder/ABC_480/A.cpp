#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> grid(2);
    cin>>grid[0]>>grid[1];
    bool isAvailable=false;
    if(grid[0][0]=='A'&&(grid[0][1]=='D'||grid[1][0]=='D'))
        isAvailable=true;
    if(grid[0][1]=='A'&&(grid[0][0]=='D'||grid[1][1]=='D'))
        isAvailable=true;
    if(grid[1][0]=='A'&&(grid[0][0]=='D'||grid[1][1]=='D'))
        isAvailable=true;
    if(grid[1][1]=='A'&&(grid[0][1]=='D'||grid[1][0]=='D'))
        isAvailable=true;
    if(isAvailable)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
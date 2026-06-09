#include<bits/stdc++.h>
using namespace std;

int level;
stack<int> path;
vector<int> tower;
int ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>level;
    tower.resize(level*(level+1)/2);
    for(auto &x: tower){
        cin>>x;
    }
    
    return 0;
}
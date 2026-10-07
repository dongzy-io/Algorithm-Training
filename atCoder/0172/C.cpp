#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,ans=0;
    cin>>n>>m;
    vector<int> height(n);
    vector<bool> isVisited(n);
    for(auto &x: height)
        cin>>x;
    while(m--){
        int i,j;
        cin>>i>>j;
        i--;
        j--;
        if(height[i]>height[j]&&!isVisited[j]){
            ans++;
            isVisited[j]=true;
        }
        if(height[j]>height[i]&&!isVisited[i]){
            ans++;
            isVisited[i]=true;
        }
    }
    cout<<ans;
    return 0;
}
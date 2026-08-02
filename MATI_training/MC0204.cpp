#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> q;
    int left=0;
    int ans=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q.emplace_back(x);
        bool hasFound=false;
        for(int j=i-1;j>=left;j--){
            if(q[j]==x){
                left=j+1;   
                ans=max(ans,i-j);
                hasFound=true;
                break;
            }
        }
        if(!hasFound)
            ans=max(ans,i-left+1);
    }
    cout<<ans;
    return 0;
}
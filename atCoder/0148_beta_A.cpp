#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,d,k;
    cin>>n>>d>>k;
    vector<int> cnt(n+1,0);
    for(int i=0;i<d;i++){
        int m;
        cin>>m;
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            cnt[x]++;
        }
    }
    bool has_found=false;
    for(int i=1;i<=n;i++){
        if(cnt[i]>=k){
            cout<<i<<" ";
            has_found=true;
        }
    }
    if(!has_found){
        cout<<-1;
    }
    return 0;
}
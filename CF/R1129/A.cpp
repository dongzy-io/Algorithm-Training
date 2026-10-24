#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,k,curr=0,ans;
        cin>>n>>k;
        vector<int> record(n+1);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            record[x]++;
        }
        int i;
        for(i=0;i<n;i++){
            curr+=record[i];
            if(curr>=k&&record[i]){
                curr-=k;
            }else{
                break;
            }
        }
        cout<<i<<'\n';
    }
    return 0;
}
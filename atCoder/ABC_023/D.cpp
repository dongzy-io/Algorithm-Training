#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;

vector<vector<ll>> record;

int main()
{
    cin>>n;
    ll ans=0;
    record.assign(n,vector<ll>(n));
    vector<bool> has_chosen(n,false);
    for(int i=0;i<n;i++){
        ll h,s;
        cin>>h>>s;
        for(int j=0;j<n;j++){
            record[j][i]=h+s*j;
        }
    }    
    for(int i=n-1;i>=0;i--){
        sort(record[i].begin(),record[i].end());
        for(int j=0;j<n;j++){
            if(!has_chosen[j]){
                ans=max(ans,record[i][j]);
                has_chosen[j]=true;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
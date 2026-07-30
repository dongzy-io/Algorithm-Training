#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<vector<int>> presum(n+1,vector<int>(26,0)); 
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            if(s[i]-'a'==j)
                presum[i+1][j]=presum[i][j]+1;
            else
                presum[i+1][j]=presum[i][j];
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int cnt=0;
        for(int i=0;i<26;i++){
            if((presum[r][i]-presum[l-1][i])&1)
                cnt++;
        }
        cout<<26-cnt<<" "<<cnt<<'\n';
    }
    return 0;
}
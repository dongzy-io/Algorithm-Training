#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int len,q;
    cin>>len>>q;
    string s;
    cin>>s;
    vector<vector<int>> pre(26,vector<int>(len+1,0));
    for(int i=0;i<len;i++){
        for(int j=0;j<26;j++){
            pre[j][i+1]=pre[j][i];
        }
        pre[s[i]-'a'][i+1]++;
    }
    while(q--){
        int l,r,odd=0,even=26;
        cin>>l>>r;
        l--;
        for(int j=0;j<26;j++){
            int cnt=pre[j][r]-pre[j][l];
            if(cnt&1){
                odd++;
                even--;
            }
        }
        cout<<even<<" "<<odd<<'\n';
    }
    return 0;
}
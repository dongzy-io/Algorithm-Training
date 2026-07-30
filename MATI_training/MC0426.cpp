#include<bits/stdc++.h>
using namespace std;

bool connected[26][26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        memset(connected,false,sizeof(connected));
        int n,q;
        cin>>n>>q;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            connected[s[0]-'a'][s[s.size()-1]-'a']=true;
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(connected[i][k]&&connected[k][j])
                        connected[i][j]=true;
                }
            }
        }
        while(q--){
            char a,b;
            cin>>a>>b;
            if(connected[a-'a'][b-'a'])
                cout<<"Yes";
            else    
                cout<<"No";
            cout<<'\n';
        }
    }
}
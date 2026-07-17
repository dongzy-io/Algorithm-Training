#include<bits/stdc++.h>
#define MAX 200002
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){ 
        int n,m;
        cin>>n>>m;
        vector<vector<int>> texts(MAX,vector<int>());
        for(int i=1;i<=n;i++){
            int id;
            cin>>id;
            texts[id].emplace_back(i);
        }
        for(int i=0;i<m;i++){
            int moment;
            cin>>moment;
            if(texts[moment].empty())
                cout<<0<<'\n';
            else{
                cout<<texts[moment].size()<<" "<<texts[moment][0]<<" "<<texts[moment].back()<<'\n';
            }
        }
    }
    return 0;
}
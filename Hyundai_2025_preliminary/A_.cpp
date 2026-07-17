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
        vector<tuple<int,int,int>> texts(MAX,{0,200002,0});//size min max
        for(int i=1;i<=n;i++){
            int id;
            cin>>id;
            get<1>(texts[id])=min(get<1>(texts[id]),i);
            get<2>(texts[id])=max(get<2>(texts[id]),i);
            get<0>(texts[id])++;
        }
        for(int i=0;i<m;i++){
            int moment;
            cin>>moment;
            if(get<0>(texts[moment])==0)
                cout<<0<<'\n';
            else{
                cout<<get<0>(texts[moment])<<" "<<get<1>(texts[moment])<<" "<<get<2>(texts[moment])<<'\n';
            }
        }
    }
    return 0;
}
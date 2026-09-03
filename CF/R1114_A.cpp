#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int a,b,c,ans;
        cin>>a>>b>>c;
        int max_num=max({a,b,c});
        int min_num=min({a,b,c});
        int medium=a+b+c-max_num-min_num;
        ans=min(max_num-medium,medium-min_num);
        cout<<ans<<'\n';
    }
    return 0;
}
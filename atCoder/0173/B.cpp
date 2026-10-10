#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w,ans=0;
    cin>>h>>w;
    vector<string> chart(h);
    for(auto &s: chart){
        cin>>s;
    }
    for(int i=0;i<w;i++){
        bool isAvailable=true;
        for(int j=0;j<h;j++){
            if(chart[j][i]=='#')
                isAvailable=false;
        }
        if(isAvailable)
            ans++;
    }
    cout<<ans;
    return 0;
}
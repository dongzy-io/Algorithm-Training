#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    ll ans=0;
    string s;
    cin>>n>>s;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    for(int i=0;i<n;i++){
        if(s[i]=='A')
            a.emplace_back(i);
        if(s[i]=='B')
            b.emplace_back(i);
        if(s[i]=='C')
            c.emplace_back(i);
    }
    if(a.empty()||b.empty()||c.empty()){
        cout<<0;
        return 0;
    }
    int l=max({a[0],b[0],c[0]});                    // 第一段结尾 i 至少为 l
    int r=min({a.back(),b.back(),c.back()});        // 第三段起点 j+1 至多为 r
    int ia=0,ib=0,ic=0;                              // 指向 i+1 之后第一个 A/B/C
    for(int i=l;i<n-1;i++){
        while(ia<(int)a.size()&&a[ia]<=i) ia++;
        while(ib<(int)b.size()&&b[ib]<=i) ib++;
        while(ic<(int)c.size()&&c[ic]<=i) ic++;
        if(ia==(int)a.size()||ib==(int)b.size()||ic==(int)c.size()) break;
        int p=max({a[ia],b[ib],c[ic]});             // 中间段最早结尾 j
        if(p>=r) break;                              // j 需 ≤ r-1，且 p 随 i 不减
        ans+=r-p;                                    // j 取 p..r-1
    }
    cout<<ans;
    return 0;
}
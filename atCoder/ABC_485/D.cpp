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
    vector<int> A;
    vector<int> B;
    vector<int> C;
    for(int i=0;i<n;i++){
        if(s[i]=='A')
            A.emplace_back(i);
        if(s[i]=='B')
            B.emplace_back(i);
        if(s[i]=='C')
            C.emplace_back(i);
    }
    int l=max({A[0],B[0],C[0]});
    int r=min({A[A.size()-1],B[B.size()-1],C[C.size()-1]});
    int i=distance(lower_bound(A.begin(),A.begin(),l),A.begin());
    int j=distance(lower_bound(B.begin(),B.begin(),l),B.begin());
    int k=distance(lower_bound(C.begin(),C.begin(),l),C.begin());
    int p=min({A[i],B[j],C[k]});
    for(int i=l+1;i<r-3;i++){
        ans+=r-p;
        if(s[i]='A'){
            p=max(p,A[++i]);
        }
        if(s[i]='B'){
            p=max(p,B[++j]);
        }
        if(s[i]='C'){
            p=max(p,B[++k]);
        }
        if(p>=r)
            break;
    }
    cout<<ans;
    return 0;
}
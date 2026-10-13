#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,curr=1e9+1;
    cin>>n>>q;
    vector<int> L(n);
    vector<int> R(n);
    vector<int> L_postmin(n);
    vector<int> R_premin(n);
    for(int i=1;i<n;i++)
        cin>>L[i];
    L[0]=1e9+1;
    for(int i=0;i<n-1;i++)
        cin>>R[i];
    curr=R[n-1]=1e9+1;
    for(int i=1;i<n;i++){
        curr=min(curr,R[i-1]);
        R_premin[i]=curr;
    }
    curr=1e9+1;
    for(int i=n-2;i>=0;i--){
        curr=min(curr,L[i+1]);
        L_postmin[i]=curr;
    }
    while(q--){
        int s,t;
        cin>>s>>t;
        s--;
        t--;
        if(s<t)
            cout<<min(R[s],L[s]+R_premin[s]);
        else
            cout<<min(L[s],R[s]+L_postmin[s]);
        cout<<'\n';
    }
    return 0;
}
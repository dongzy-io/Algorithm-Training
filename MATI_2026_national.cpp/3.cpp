#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>> idx(n);
    vector<pair<int,int>> idy(n);
    for(int i=0;i<n;i++){
        cin>>idx[i].first>>idy[i].first;
        cin>>idx[i].second>>idy[i].second;
    }
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            bool x=false;
            bool y=false;
            if(idx[i].first<=idx[j].second&&idx[j].first<=idx[i].second)
                x=true;
            if(idy[i].first<=idy[j].second&&idy[j].first<=idy[i].second)
                y=true;
            if(x&&y)
                cnt++;
        }
        cnt--;
        cout<<cnt<<" ";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        map<ll,ll> cnt;
        vector<ll> nums(n);
        for(auto &x: nums){
            cin>>x;
            cnt[x]++;
        }
        if(cnt.size()==1&&cnt[0]!=0){
            for(int i=0;i<n;i++){
                cout<<1<<" ";
            }
            cout<<'\n';
            continue;
        }
        if(cnt[0]==0){
            cout<<-1<<'\n';
            continue;
        }
        unordered_map<ll,ll> match;
        ll sum=0,blank=0,total;
        ld last=-1;
        bool available=true;
        for(auto p: cnt){
            if(blank!=0){
                total=p.first;
                ld res=(ld)(total-sum)/blank*1.0;
                if(res-(ll)res>0||res<=last){
                    available=false;
                    break;
                }
                match[sum]=(ll)res;
                blank=p.second;
                sum=total;
                last=res;
            }else{
                blank=p.second;
                continue;
            }
        }
        match[total]=last+1;
        if(available){
            for(auto x: nums){
                cout<<match[x]<<" ";
            }
        }else{
            cout<<-1;
        }
        cout<<'\n';
    }
    return 0;
}
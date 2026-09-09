#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct item{
    int num;
    int len;
    int l;
    int r;
    bool operator< (const item& other) const{
        return len<other.len;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        ll ans=0;
        int n;
        cin>>n;
        vector<int> nums(2*n);
        vector<bool> isMatched(n+1,true);
        vector<bool> isDeleted(n+1,false);
        vector<item> record(n+1);
        priority_queue<item> pq;
        for(int i=0;i<2*n;i++){
            cin>>nums[i];   
            if(isMatched[nums[i]]){
                isMatched[nums[i]]=false;
                record[nums[i]].l=i;
                record[nums[i]].num=nums[i];
            }else{
                isMatched[nums[i]]=true;
                record[nums[i]].r=i;
                record[nums[i]].len=record[nums[i]].r-record[nums[i]].l+1;
                pq.emplace(record[nums[i]]);
            }
        }
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int l=p.l;
            int r=p.r;
            if(!isMatched[p.num])
                continue;
            ans+=(ll)p.len*p.len;
            for(int i=p.l+1;i<p.r;i++){
                if(isMatched[nums[i]])
                    isMatched[nums[i]]=false;
                else
                    isDeleted[nums[i]]=true;
            }
        }
        for(int i=1;i<=n;i++){
            if(!isDeleted[i]&&!isMatched[i])
                ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
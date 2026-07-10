#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        ll n,m,max_num=0;
        ll ans;
        cin>>n>>m;
        vector<ll> nums(n);
        for(auto &x: nums){
            cin>>x;
            max_num=max(max_num,x);
        }
        ll lo=1,hi=max_num+1;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long sum = 0;
            for (int i = 0; i < n; i++) {
                sum += nums[i] / mid;
                if (sum > m) break; // 提前剪枝，避免大数据下无谓浪费
            }
            if (sum <= m) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        cout<<lo<<'\n';
    }
    return 0;
}
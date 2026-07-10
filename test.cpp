#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> L;
    int count = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0 && a[i] != a[i-1]) {
            L.push_back(count);
            count = 1;
        } else if (i > 0) {
            count++;
        }
    }
    L.push_back(count);

    // 预处理前缀和以便快速计算 sum(L_i > D)
    sort(L.begin(), L.end());
    int m = L.size();
    vector<long long> pref(m + 1, 0);
    for(int i=0; i<m; ++i) pref[i+1] = pref[i] + L[i];

    long long ans = 0;
    // 枚举删除次数 D
    for (int D = 0; D < n; ++D) {
        auto it = upper_bound(L.begin(), L.end(), D);
        int idx = distance(L.begin(), it);
        int cnt = m - idx; // 存活的块数量
        if (cnt == 0) break;

        long long current_sum = (pref[m] - pref[idx]);
        long long remaining_len = current_sum - (long long)cnt * D;
        
        // k = remaining_len + cnt * A  => A = (k - remaining_len) / cnt
        if (k >= remaining_len && (k - remaining_len) % cnt == 0) {
            ans++; 
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
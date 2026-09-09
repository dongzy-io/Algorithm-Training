#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int m = 2 * n;
        vector<int> a(m);
        for (auto &x : a) scanf("%d", &x);
        vector<int> firstOcc(n + 1, -1);
        vector<int> lp(m, -1); // lp[i] = a[i] 第一次出现的下标（若之前出现过）
        for (int i = 0; i < m; ++i) {
            if (firstOcc[a[i]] != -1) {
                lp[i] = firstOcc[a[i]];
            } else {
                firstOcc[a[i]] = i;
            }
        }
        vector<long long> dp(m + 1, 0);
        dp[0] = 0;
        for (int i = 0; i < m; ++i) { // a[i] 是 0-indexed，对应第 i+1 个位置
            dp[i + 1] = dp[i] + 1;                 // 把 a[i] 当作单独一块
            if (lp[i] != -1) {
                long long len = i - lp[i] + 1;
                dp[i + 1] = max(dp[i + 1], dp[lp[i]] + len * len); // 与之前的配对合并成一整块
            }
        }
        printf("%lld\n", dp[m]);
    }
    return 0;
}
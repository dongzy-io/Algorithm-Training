#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const int MOD = 998244353;
static const int MAXN = 200005;

long long inv[MAXN];

void precompute() {
    inv[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    // 计算 (n-1)! % MOD
    long long fact_n_minus_1 = 1;
    for (int i = 1; i <= n - 1; ++i) {
        fact_n_minus_1 = (fact_n_minus_1 * i) % MOD;
    }

    long long total_sum = 0;
    long long prefix_inv_sum = 0; // 维护 sum_{j=1}^{i-1} (1 / (n - j))

    for (int i = 1; i <= n; ++i) {
        long long b_i = a[i - 1] % MOD;

        long long coeff = prefix_inv_sum;
        if (i < n) {
            coeff = (coeff - 1 + MOD) % MOD;
        }

        long long term = (b_i * coeff) % MOD;
        total_sum = (total_sum + term) % MOD;

        int k = n - i;
        if (k > 0) {
            prefix_inv_sum = (prefix_inv_sum + inv[k]) % MOD;
        }
    }

    long long ans = (total_sum * fact_n_minus_1) % MOD;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
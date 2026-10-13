#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    ll w;
    if (!(cin >> n >> w)) return 0;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int total_states = 1 << n; 
    vector<ll> dp_weight(total_states, 0);
    vector<ll> dp_value(total_states, 0);
    ll max_deliciousness = 0;
    for (int mask = 0; mask < total_states; mask++) {
        if (mask > 0) {
            int i = __builtin_ctz(mask);
            int prev_mask = mask ^ (1 << i); 
            dp_weight[mask] = dp_weight[prev_mask] + b[i];
            dp_value[mask] = dp_value[prev_mask] + a[i];
        }
        if (dp_weight[mask] <= w) {
            max_deliciousness = max(max_deliciousness, dp_value[mask]);
        }
    }
    cout << max_deliciousness << "\n";
    return 0;
}
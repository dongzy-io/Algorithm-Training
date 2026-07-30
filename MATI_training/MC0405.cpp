#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    long long max_power = 0;
    
    for (int i = 1; i <= n; ++i) {
        long long a;
        cin >> a;
        if (i >= 2 && a > 0) {
            max_power += a;
        }
    }
    cout << max_power << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
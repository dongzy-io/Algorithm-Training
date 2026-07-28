#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<char> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    ll ans = 0, sum1 = 0;
    for(int j = 1; j <= n; j++){
        if(a[j] == '1'){
            sum1 += j;  // 记录1的位置之和
        } else {
            // a[j]==0，贡献为 (n-j+1) * sum1
            ans=(ans+(ll)(n - j + 1) * sum1%MOD)%MOD;
        }
    }
    
    cout << ans << '\n';
    return 0;
}
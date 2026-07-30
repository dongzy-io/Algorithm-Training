#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> s(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s[i] = a[i]; // 拷贝一份用于排序
    }
    
    // 将目标序列从大到小排序
    // greater<int>() 让排序方式变为降序
    sort(s.begin(), s.end(), greater<int>());
    
    // 双指针匹配
    int j = 0; // j 指向目标降序序列 s
    for (int i = 0; i < n; ++i) { // i 指向原序列 a
        if (a[i] == s[j]) {
            j++; // 匹配成功，继续找降序序列的下一个元素
        }
    }
    
    // 剩下的 (n - j) 个元素就是必须移动的元素
    cout << n - j << "\n";
}

int main() {
    // 优化 I/O 速度，应对极限数据
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
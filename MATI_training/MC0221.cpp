#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int l, r;
    // 按左端点从小到大排序
    bool operator<(const Interval& other) const {
        return l < other.l;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Interval> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
    }

    sort(a.begin(), a.end());

    int max_occupied = 0, max_empty = 0;

    // 当前合并后的大区间 [cur_l, cur_r]
    int cur_l = a[0].l;
    int cur_r = a[0].r;

    for (int i = 1; i < n; i++) {
        if (a[i].l <= cur_r) {
            // 有重叠或相连，扩展右端点
            cur_r = max(cur_r, a[i].r);
        } else {
            // 出现了断层（空闲时间）
            max_occupied = max(max_occupied, cur_r - cur_l);
            max_empty = max(max_empty, a[i].l - cur_r);
            
            // 开启新区间
            cur_l = a[i].l;
            cur_r = a[i].r;
        }
    }

    // 别忘了更新最后一段有人的时间
    max_occupied = max(max_occupied, cur_r - cur_l);

    cout << max_occupied << " " << max_empty << "\n";

    return 0;
}
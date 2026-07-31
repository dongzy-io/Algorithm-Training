#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

const int INF = 1e9;
// 方向映射：0:上(U), 1:右(R), 2:下(D), 3:左(L)
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

// 计算两个方向之间旋转的最小次数 (相差为 3 时代表顺/逆时针转了 1 次 90 度)
inline int get_dist(int a, int b) {
    int d = (a - b) & 3; // 等价于 (a - b + 4) % 4，用位运算最高效
    return d == 3 ? 1 : d;
}

// 字符方向转数字
inline int get_dir(char c) {
    if (c == 'U') return 0;
    if (c == 'R') return 1;
    if (c == 'D') return 2;
    return 3;
}

// 封装状态节点，用于优先队列
struct Node {
    int d, r, c, p;
    // 小根堆重载大于号
    bool operator>(const Node& other) const {
        return d > other.d;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    
    // dist 数组大小为 n * m * 4 (每个格子4个可能的管道朝向)
    int total_states = n * m * 4;
    vector<int> dist(total_states, INF);
    
    // 标准库小根堆
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    
    // 初始化起点状态
    int start_p = get_dir(grid[0][0]);
    int start_state = start_p; // 等同于 (0 * m + 0) * 4 + start_p
    dist[start_state] = 0;
    pq.push({0, 0, 0, start_p});
    
    while (!pq.empty()) {
        auto [d_u, r, c, p] = pq.top(); // C++17 结构化绑定
        pq.pop();
        
        // 一维化坐标，极致化内存读取效率
        int u = (r * m + c) * 4 + p;
        if (d_u > dist[u]) continue;
        
        // 首次弹出的终点即为全局最优解
        if (r == n - 1 && c == m - 1) {
            cout << d_u << "\n";
            return;
        }
        
        for (int nd = 0; nd < 4; ++nd) {
            int nr = r + dr[nd];
            int nc = c + dc[nd];
            
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                int next_d0 = get_dir(grid[nr][nc]);
                int np = (nd + 2) & 3; // 目标格子必须指向反方向来接球
                
                // 总代价 = 离开当前格子的旋转代价 + 进入目标格子的旋转代价
                int cost = get_dist(p, nd) + get_dist(next_d0, np);
                
                int nv = (nr * m + nc) * 4 + np;
                
                if (dist[nv] > d_u + cost) {
                    dist[nv] = d_u + cost;
                    pq.push({dist[nv], nr, nc, np});
                }
            }
        }
    }
}

int main() {
    // 关闭输入输出同步，极大提速 cin/cout，必备优化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
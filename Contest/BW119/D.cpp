/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.14.2023 02:16:19
*********************************************/

using i64 = long long;

constexpr int N = 11, inf = 1e9 + 5;
int d[N][N];
int dense[N][N];

void Init(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            d[i][j] = dense[i][j];
        }
    }
}

class Solution {
public:
    int numberOfSets(int n, int dis, vector<vector<int>>& edges) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dense[i][j] = inf;
            }
        }
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dense[u][v] = dense[v][u] = (dense[u][v] == inf ? w : min(dense[u][v], w));
        }
        int ans = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> a;
            int m = 0;
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) {
                    a.push_back(i);
                    m++;
                }
            }
            Init(n);
            for (int k = 0; k < m; k++) {
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        int x = a[i], y = a[j], z = a[k];
                        d[x][y] = min(d[x][y], d[x][z] + d[z][y]);
                    }
                }
            }
            int md = 0;
            for (int i = 0; i < m; i++) {
                for (int j = i + 1; j < m; j++) {
                    int x = a[i], y = a[j];
                    md = max(md, d[x][y]);
                }
            }
            if (md <= dis) {
                ans++;
            }
        }
        return ans;
    }
};

// ~ JustJie
#include "bits/stdc++.h"

using namespace std;

using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define mp make_pair
#define ins insert
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(a) int(a.size())

template <typename T> bool ckmax(T &a, T b) { return a < b ? a = b, true : false; }
template <typename T> bool ckmin(T &a, T b) { return a > b ? a = b, true : false; }

constexpr int N = 55;
bool exist[N][N];

int check(int n) {
    int best = 3;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!exist[i][j]) continue;
            for (int k = 0; k < n; k++) {
                if (!exist[j][k]) continue;
                if (exist[k][i])
                    best = 0;
                else
                    ckmin(best, 1);
            }
            ckmin(best, 2);
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        exist[u][v] = exist[v][u] = 1;
    }
    cout << check(n) << "\n";
}
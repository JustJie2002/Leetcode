/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.06.2024 23:41:02
*********************************************/

using i64 = long long;
using Coordinate = pair<int, int>;
using Info = pair<Coordinate, int>;

#define f   first
#define s   second

const char PERSON = '@';
const char WALL = '#';
const char EMPTY = '.';

constexpr int N = 30, K = 6, INF = 1e9 + 5;
bool vis[N][N][1 << K];

constexpr int dir[] = {0, 1, 0, -1, 0};

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size();

        Coordinate me;
        int keys = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < (1 << K); k++) {
                    vis[i][j][k] = false;
                }
                if (grid[i][j] == PERSON) {
                    me = pair(i, j);
                    grid[i][j] = EMPTY;
                } else if (islower(grid[i][j])) {
                    keys++;
                }
            }
        }

        queue<Info> q;
        int d = 0;

        auto add = [&](const Coordinate& pos, int key_mask) -> void {
            if (!vis[pos.f][pos.s][key_mask]) {
                vis[pos.f][pos.s][key_mask] = true;
                q.push({pos, key_mask});
            }
        };
        auto good = [&](int i, int j) {
            if (i < 0 || i >= n) {
                return false;
            }
            if (j < 0 || j >= m) {
                return false;
            }
            return grid[i][j] != WALL;
        };

        add(me, 0);
        while (!q.empty()) {
            int Q = q.size();
            for (; Q--; ) {
                auto [pos, key_mask] = q.front();
                q.pop();

                if (key_mask == (1 << keys) - 1) {
                    return d;
                }

                for (int k = 0; k < 4; k++) {
                    int new_i = pos.f + dir[k];
                    int new_j = pos.s + dir[k + 1];
                    if (!good(new_i, new_j)) {
                        continue;
                    }
                    const auto& nex = grid[new_i][new_j];
                    if (nex == EMPTY) {
                        add(pair(new_i, new_j), key_mask);
                    } else if (isupper(nex)) {
                        int o = nex - 'A';
                        if (key_mask >> o & 1) {
                            add(pair(new_i, new_j), key_mask);
                        }
                    } else {
                        assert(islower(nex));
                        int o = nex - 'a';
                        add(pair(new_i, new_j), key_mask | (1 << o));
                    }
                }
            }
            d++;
        }

        return -1;
    }
};

// ~ JustJie
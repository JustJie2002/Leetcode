/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.27.2024 03:14:24
*********************************************/

using i64 = long long;
using Pos = array<int, 2>;

constexpr int inf = 1e9 + 5;

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& special_roads) {
        if (start == target) {
            return 0;
        }
        auto dis = [&](const Pos& from, const Pos& to) -> int {
            return abs(from[0] - to[0]) + abs(from[1] - to[1]);
        };

        int n = 2;
        vector<Pos> a(n);
        a[0] = {start[0], start[1]};
        a[1] = {target[0], target[1]};
        map<Pos, int> compression;
        compression[a[0]] = 0;
        compression[a[1]] = 1;

        auto put = [&](const Pos& pos) -> void {
            if (!compression.contains(pos)) {
                compression[pos] = n++;
                a.push_back(pos);
            }
        };

        int m = special_roads.size();
        vector d(2 * m + 2, vector<int>(2 * m + 2, inf));
        for (const auto& road : special_roads) {
            const Pos& from = {road[0], road[1]};
            const Pos& to = {road[2], road[3]};
            put(from);
            put(to);
            d[compression[from]][compression[to]] = min(d[compression[from]][compression[to]], road[4]);
        }

        for (int i = 0; i < n; i++) {
            d[i][i] = 0;
            for (int j = 0; j < n; j++) if (i != j) {
                d[i][j] = min(d[i][j], dis(a[i], a[j]));
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }

        return d[0][1];
    }
};

// ~ JustJie
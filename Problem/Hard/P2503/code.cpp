/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.20.2024 22:32:22
*********************************************/

using i64 = long long;
using Query = array<int, 2>;
using Info = array<int, 3>;

constexpr int di[] {0, -1, 0, 1};
constexpr int dj[] {-1, 0, 1, 0};

constexpr int inf = 1e9 + 5;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& aa, vector<int>& queries) {
        int n = aa.size(), m = aa[0].size(), Q = queries.size();

        vector<Query> qord(Q);
        for (int q = 0; q < Q; q++) {
            qord[q] = {queries[q], q};
        }

        sort(qord.begin(), qord.end());

        vector vis(n, vector<int>(m));
        vector<int> ans(Q);
        priority_queue<Info, vector<Info>, greater<Info>> pq;
        int res = 0;

        auto flood = [&](int req) -> void {
            while (!pq.empty() && pq.top()[0] < req) {
                auto [_, i, j] = pq.top();
                pq.pop();
                res++;

                for (int d = 0; d < 4; d++) {
                    int ni = i + di[d];
                    int nj = j + dj[d];

                    if (0 <= ni && ni < n && 0 <= nj && nj < m && !vis[ni][nj]) {
                        pq.push({aa[ni][nj], ni, nj});
                        vis[ni][nj] = 1;
                    }
                }
            }
        };

        pq.push({aa[0][0], 0, 0});
        vis[0][0] = 1;
        for (const auto& [x, q] : qord) {
            flood(x);
            ans[q] = res;
        }

        return ans;
    }
};

// ~ JustJie
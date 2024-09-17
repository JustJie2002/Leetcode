/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.06.2024 01:41:12
*********************************************/

using i64 = long long;

constexpr int N = 101;
using BS = bitset<N>;

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        BS init;
        init.set(0);
        vector<BS> dp;
        dp.insert(init);

        for (auto& a : grid) {
            ranges::sort(a);
            a.erase(unique(a.begin(), a.end()), a.end());
            vector<BS> ndp;
            for (int x : a) {
                for (auto bs : dp) {
                    if (!bs[x]) {
                        bs.set(x);
                        ndp.push_back(bs);
                    }
                }
            }
            swap(dp, ndp);
        }

        int ans = 0;
        for (const auto& bs : dp) {
            int sum = 0;
            for (int i = 0; i < N; i++) {
                if (bs[i]) {
                    sum += i;
                }
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};

// ~ JustJie
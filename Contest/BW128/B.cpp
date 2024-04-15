/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.13.2024 11:55:53
*********************************************/

using i64 = long long;

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& ps, int w) {
        vector<int> xs;
        for (const auto& p : ps) {
            xs.push_back(p[0]);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        int lst = xs[0];
        int ans = 1;
        for (int x : xs) {
            if (x - lst > w) {
                ans++;
                lst = x;
            }
        }
        return ans;
    }
};

// ~ JustJie
/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.09.2024 20:13:06
*********************************************/

using i64 = long long;

constexpr int inf = 1e9 + 5;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
        int n = p.size();

        sort(p.begin(), p.end(), 
            [&](auto&& a, auto&& b) {
                if (a[0] != b[0]) {
                    return a[0] < b[0];
                }
                return a[1] > b[1];
            });
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int mx = -inf, py = p[i][1];
            for (int j = i + 1; j < n; j++) {
                int y = p[j][1];
                if (y > py) {
                    continue;
                }
                if (mx < y) {
                    ans++;
                    mx = y;
                }
            }
        }
        return ans;
    }
};

// ~ JustJie
/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.08.2024 01:04:33
*********************************************/

using i64 = long long;

class Solution {
public:
    int longestEqualSubarray(vector<int>& a, int k) {
        int n = a.size();

        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) {
            pos[a[i]].push_back(i);
        }

        int ans = 1;
        for (const auto& [_, v] : pos) {
            int m = v.size();
            int L = 0;
            for (int R = 1; R < m; R++) {
                while (v[R] - v[L] + 1 - (R - L + 1) > k) {
                    L++;
                }
                ans = max(ans, R - L + 1);
            }
        }
        return ans;
    }
};

// ~ JustJie
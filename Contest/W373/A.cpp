/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.06.2024 18:09:53
*********************************************/

using i64 = long long;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();

        for (int i = 0; i < n; i++) {
            const auto& cur = mat[i];
            auto nxt = cur;
            k %= m;
            if (i & 1) {
                rotate(nxt.begin(), nxt.begin() + k, nxt.end());
            } else {
                rotate(nxt.rbegin(), nxt.rbegin() + k, nxt.rend());
            }
            if (cur != nxt) {
                return false;
            }
        }

        return true;
    }
};

// ~ JustJie
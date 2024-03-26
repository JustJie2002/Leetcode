/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.25.2024 23:02:10
*********************************************/

using i64 = long long;

constexpr int inf = 1e9 + 5;

class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n = a.size();

        for (auto& x : a) {
            if (x <= 0) {
                x = inf;
            }
        }

        for (int i = 0; i < n; i++) {
            int x = abs(a[i]);
            if (x <= n) {
                int id = x - 1;
                if (a[id] > 0) {
                    a[id] = -a[id];
                }
            }
        }

        int mex = 1;
        while (mex <= n && a[mex - 1] < 0) {
            mex++;
        }

        return mex;
    }
};

// ~ JustJie
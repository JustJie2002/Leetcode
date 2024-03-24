/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.20.2024 23:24:21
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        int Q = queries.size();

        auto get_depth = [&](int x) -> int {
            return 31 - __builtin_clz(x);
        };

        auto answer = [&](int a, int b) -> int {
            int adep = get_depth(a);
            int bdep = get_depth(b);

            if (adep > bdep) {
                swap(a, b);
                swap(adep, bdep);
            }

            int res = adep + bdep + 1;
            while (bdep > adep) {
                b >>= 1;
                bdep--;
            }

            while (a != b) {
                a >>= 1;
                b >>= 1;
            }

            res -= 2 * get_depth(a);
            return res;
        };

        vector<int> ans(Q);
        for (int q = 0; q < Q; q++) {
            int a = queries[q][0], b = queries[q][1];
            ans[q] = answer(a, b);

        }
        return ans;
    }
};

// ~ JustJie
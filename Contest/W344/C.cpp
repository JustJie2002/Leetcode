/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 08.17.2024 00:54:24
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int Q = queries.size();

        vector<int> c(n);
        vector<int> ans(Q);
        int res = 0;

        const auto update = [&](int i, int x) -> void {
            if (c[i] == x) {
                return;
            }
            if (c[i]) {
                if (i - 1 >= 0 && c[i - 1] == c[i]) {
                    res--;
                }
                if (i + 1 < n && c[i] == c[i + 1]) {
                    res--;
                }
            }
            c[i] = x;
            if (i - 1 >= 0 && c[i - 1] == c[i]) {
                res++;
            }
            if (i + 1 < n && c[i] == c[i + 1]) {
                res++;
            }
        };

        for (int q = 0; q < Q; q++) {
            int i = queries[q][0];
            int x = queries[q][1];

            update(i, x);
            ans[q] = res;
        }

        return ans;
    }
};

// ~ JustJie
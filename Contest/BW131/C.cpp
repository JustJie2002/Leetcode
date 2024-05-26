/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.25.2024 12:26:10
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> queryResults(int n, vector<vector<int>>& queries) {
        int Q = queries.size();
        vector<int> ans(Q);
        unordered_map<int, int> occs, c;
        for (int q = 0; q < Q; q++) {
            int pos = queries[q][0], x = queries[q][1];
            if (c[pos] == x) {
                ans[q] = occs.size();
                continue;
            }
            if (c[pos]) {
                if (--occs[c[pos]] == 0) {
                    occs.erase(c[pos]);
                }
            }
            c[pos] = x;
            occs[x]++;
            ans[q] = occs.size();
        }
        return ans;
    }
};

// ~ JustJie
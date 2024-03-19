/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.17.2024 17:18:09
*********************************************/

using i64 = long long;
using Info = pair<int, int>;

class Solution {
public:
    vector<i64> unmarkedSumArray(vector<int>& a, vector<vector<int>>& queries) {
        int n = a.size(), Q = queries.size();

        set<Info> unmarked;
        i64 tot = 0;
        for (int i = 0; i < n; i++) {
            tot += a[i];
            unmarked.emplace(a[i], i);
        }

        vector<i64> ans(Q);
        for (int q = 0; q < Q; q++) {
            int i = queries[q][0];
            int k = queries[q][1];
            if (unmarked.contains({a[i], i})) {
                tot -= a[i];
                unmarked.erase({a[i], i});
            }

            while (!unmarked.empty() && k--) {
                auto it = unmarked.begin();
                tot -= it->first;
                unmarked.erase(it);
            }
            ans[q] = tot;
        }

        return ans;
    }
};

// ~ JustJie
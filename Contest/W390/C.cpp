/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.23.2024 22:43:26
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<i64> mostFrequentIDs(vector<int>& a, vector<int>& freq) {
        int n = a.size();

        vector<i64> ans(n);
        map<int, i64> occ;
        multiset<i64> ms;
        for (int i = 0; i < n; i++) {
            auto& p = occ[a[i]];
            if (ms.find(p) != ms.end()) {
                ms.erase(ms.find(p));
            }
            p += freq[i];
            ms.insert(p);
            ans[i] = *ms.rbegin();
        }

        return ans;
    }
};

// ~ JustJie
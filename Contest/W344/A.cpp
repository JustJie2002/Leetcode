/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 08.17.2024 00:50:40
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& a) {
        int n = a.size();

        set<int> s;
        vector<int> suf(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            s.insert(a[i]);
            suf[i] = s.size();
        }

        s.clear();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            s.insert(a[i]);
            ans[i] = int(s.size()) - suf[i + 1];
        }
        return ans;
    }
};

// ~ JustJie
/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.19.2024 03:49:14
*********************************************/

using i64 = long long;

class Solution {
public:
    int minimumDeletions(string s, int k) {
        int n = s.length();

        array<int, 26> freq {};
        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<int> occ;
        for (int f : freq) {
            if (f) {
                occ.push_back(f);
            }
        }

        sort(occ.begin(), occ.end());
        int m = occ.size();

        vector<int> pre(m + 1);
        for (int i = 0; i < m; i++) {
            pre[i + 1] = pre[i] + occ[i];
        }

        int r = 0;
        int ans = n;
        for (int l = 0; l < m; l++) {
            while (r < m && occ[r] - occ[l] <= k) {
                r++;
            }
            int res = pre[l] + (pre.back() - pre[r]) - (m - r) * (occ[l] + k);
            ans = min(ans, res);
        }

        return ans;
    }
};

// ~ JustJie
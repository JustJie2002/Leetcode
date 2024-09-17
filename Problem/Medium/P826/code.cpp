/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.18.2024 16:15:12
*********************************************/

using i64 = long long;

class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        int n = d.size();

        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), 
            [&](int i, int j) {
                return d[i] < d[j];
            });
        sort(w.begin(), w.end());

        int ans = 0, res = 0;
        for (int i = 0; int x : w) {
            while (i < n && d[ord[i]] <= x) {
                res = max(res, p[ord[i]]);
                i++;
            }
            ans += res;
        }
        return ans;
    }
};

// ~ JustJie
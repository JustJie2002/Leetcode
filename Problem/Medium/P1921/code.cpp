/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.15.2024 20:27:22
*********************************************/

using i64 = long long;

class Solution {
public:
    int eliminateMaximum(vector<int>& d, vector<int>& s) {
        int n = d.size();

        vector<int> t(n);
        for (int i = 0; i < n; i++) {
            t[i] = (d[i] + s[i] - 1) / s[i];
        }

        sort(t.begin(), t.end());

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (t[i] > i) {
                ans++;
            } else {
                break;
            }
        }
        return ans;
    }
};

// ~ JustJie
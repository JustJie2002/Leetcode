/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.15.2024 20:23:40
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& a) {
        int n = a.size();

        vector<int> freq(n + 1);
        for (int x : a) {
            freq[x]++;
        }

        vector<int> ans(2);
        for (int i = 1; i <= n; i++) {
            if (freq[i] == 2) {
                ans[0] = i;
            } else if (freq[i] == 0) {
                ans[1] = i;
            }
        }
        return ans;
    }
};

// ~ JustJie
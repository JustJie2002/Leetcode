/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 08.15.2024 17:26:18
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();

        vector<int> ans(n);
        vector<int> stk;
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && temp[i] >= temp[stk.back()]) {
                stk.pop_back();
            }
            if (!stk.empty()) {
                ans[i] = stk.back() - i;
            }
            stk.push_back(i);
        }
        return ans;
    }
};

// ~ JustJie
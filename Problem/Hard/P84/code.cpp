/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.28.2024 13:05:48
*********************************************/

using i64 = long long;

class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();

        vector<int> lesser_left(n, -1);
        vector<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && a[stk.top()] >= a[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                lesser_left[i] = stk.top();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            stk.pop();
        }
        vector<int> lesser_right(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && a[stk.top()] >= a[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                lesser_right[i] = stk.top();
            }
            stk.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, (lesser_right[i] - lesser_left[i] - 1) * a[i]);
        }
        return ans;
    }
};

// ~ JustJie
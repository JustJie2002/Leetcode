/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.12.2024 22:32:59
*********************************************/

using i64 = long long;

class Solution {
public:
    int validSubarraySize(vector<int>& a, int threshold) {
        int n = a.size();

        vector<int> min_k(n);
        for (int i = 0; i < n; i++) {
            min_k[i] = threshold / a[i] + 1;
        }

        stack<int> stk;
        vector<int> L(n), R(n);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && min_k[i] >= min_k[stk.top()]) {
                stk.pop();
            }
            L[i] = (stk.empty() ? 0 : stk.top() + 1);
            stk.push(i);
        }
        while (!stk.empty()) {
            stk.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && min_k[i] >= min_k[stk.top()]) {
                stk.pop();
            }
            R[i] = (stk.empty() ? n - 1 : stk.top() - 1);
            stk.push(i);
        }

        for (int i = 0; i < n; i++) {
            int siz = R[i] - L[i] + 1;
            if (siz >= min_k[i]) {
                return siz;
            }
        }

        return -1;
    }
};

// ~ JustJie
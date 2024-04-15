/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.12.2024 21:25:19
*********************************************/

using i64 = long long;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector expand(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                expand[i][j] = mat[i][j] - '0';
                if (i > 0 && expand[i][j]) {
                    expand[i][j] += expand[i - 1][j];
                }
            }
        }

        auto work = [&](const auto& seg) -> int {
            int res = 0;
            stack<int> stk;
            for (int i = 0; i < m; i++) {
                while (!stk.empty() && seg[stk.top()] >= seg[i]) {
                    int height = seg[stk.top()]; stk.pop();
                    int width = (!stk.empty() ? i - stk.top() - 1 : i);
                    res = max(res, height * width);
                }
                stk.push(i);
            }
            while (!stk.empty()) {
                int height = seg[stk.top()]; stk.pop();
                int width = (!stk.empty() ? m - stk.top() - 1 : m);
                res = max(res, height * width);
            }
            return res;
        };

        int ans = 0;
        for (const auto& seg : expand) {
            ans = max(ans, work(seg));
        }

        return ans;
    }
};

// ~ JustJie
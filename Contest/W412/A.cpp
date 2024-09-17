/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 08.24.2024 22:58:59
*********************************************/

using i64 = long long;
using Info = array<int, 2>;

class Solution {
public:
    vector<int> getFinalState(vector<int>& a, int k, int multiplier) {
        int n = a.size();

        priority_queue<Info, vector<Info>, greater<Info>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({a[i], i});
        }

        while (k--) {
            auto [x, i] = pq.top();
            pq.pop();
            x *= multiplier;
            pq.push({x, i});
        }

        while (!pq.empty()) {
            auto [x, i] = pq.top();
            pq.pop();
            a[i] = x;
        }

        return a;
    }
};

// ~ JustJie
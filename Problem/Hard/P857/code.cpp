/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.08.2024 22:57:38
*********************************************/

using i64 = long long;
using Info = pair<double, int>;

constexpr double inf = 1e18 + 10;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
        int n = q.size();

        vector<Info> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = pair(1. * w[i] / q[i], q[i]);
        }

        sort(p.begin(), p.end());

        double ans = inf, cur = 0;
        priority_queue<int> pq;
        for (const auto& [a, b] : p) {
            cur += b;
            pq.push(b);
            if (pq.size() > k) {
                cur -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                ans = min(ans, cur * a);
            }
        }
        return ans;
    }
};

// ~ JustJie
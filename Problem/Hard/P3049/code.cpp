/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.24.2024 21:58:09
*********************************************/

using i64 = long long;
using Pair = pair<int, int>;

#define dequeue(pq)     pq.top(); pq.pop()

class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& a, vector<int>& c) {
        int n = a.size(), m = c.size();

        for (int &x : c) {
            x--;
        }

        auto good = [&](int t) -> bool {
            int free = 0;
            vector<bool> use(t), marked(n);
            for (int i = 0; i < t; i++) {
                int j = c[i];
                if (!marked[j] && a[j]) {
                    marked[j] = true;
                    use[i] = true;
                } else {
                    free++;
                }
            }

            int open = 0;
            priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
            for (int i = t - 1; i >= 0; i--) {
                int j = c[i];
                if (use[i]) {
                    pq.emplace(a[j], i);
                    open--;
                } else {
                    open++;
                }

                if (open < 0) {
                    auto [_, idx] = dequeue(pq);
                    use[idx] = false;
                    marked[c[idx]] = false;
                    open += 2;
                    free++;
                }
            }

            free -= n;
            for (int i = 0; i < n; i++) {
                if (!marked[i]) {
                    free -= a[i];
                    if (free < 0) {
                        break;
                    }
                }
            }

            return free >= 0;
        };

        if (!good(m)) {
            return -1;
        }

        int lo = 1, hi = m, mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (good(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return hi;
    }
};

// ~ JustJie
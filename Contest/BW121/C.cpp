/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.06.2024 13:25:47
*********************************************/

using i64 = long long;

constexpr int N = int(2e4), inf = 1e9 + 5;
bool seen[N];

class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if (y >= x) {
            return y - x;
        }

        memset(seen, false, sizeof(seen));
        queue<int> q;

        auto enqueue = [&](int u) {
            if (u < 0 || u >= N) return;
            if (!seen[u]) {
                q.push(u);
                seen[u] = true;
            }
        };

        enqueue(x);
        for (int s = 0; ; s++) {
            int Q = q.size();
            while (Q--) {
                int u = q.front();
                q.pop();
                if (u == y) return s;
                if (u % 11 == 0) {
                    enqueue(u / 11);
                }
                if (u % 5 == 0) {
                    enqueue(u / 5);
                }
                enqueue(u + 1);
                enqueue(u - 1);
            }
        }

        assert(false);
    }

};

// ~ JustJie
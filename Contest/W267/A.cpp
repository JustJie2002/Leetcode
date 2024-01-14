/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.10.2024 23:47:01
*********************************************/

using i64 = long long;
using Pair = pair<int, int>;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& a, int k) {
        int n = a.size();

        deque<Pair> dq;
        for (int i = 0; i < n; i++) {
            dq.emplace_back(i, a[i]);
        }

        for (int t = 1; ; t++) {
            auto [cur, rem] = dq.front();
            dq.pop_front();
            rem--;
            if (rem > 0) {
                dq.emplace_back(cur, rem);
            } else if (cur == k) {
                return t;
            }
        }

        assert(false);
    }
};

// ~ JustJie
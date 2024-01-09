/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.06.2024 18:21:25
*********************************************/

using i64 = long long;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        auto work = [&](auto& a) {
            sort(a.begin(), a.end());

            int streak = 2, res = 2;
            int now = a[0];
            for (int nxt : a) {
                if (nxt == now + 1) {
                    streak++;
                } else {
                    streak = 2;
                }
                res = max(res, streak);
                now = nxt;
            }
            return res;
        };

        int side = min(work(h), work(v));
        return side * side;
    }
};

// ~ JustJie
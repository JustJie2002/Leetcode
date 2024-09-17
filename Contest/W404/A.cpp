/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.29.2024 22:57:18
*********************************************/

using i64 = long long;

class Solution {
public:
    int maxHeightOfTriangle(int a, int b) {

        auto work = [&](int x, int y) -> int {
            for (int i = 1; ; i++) {
                if (i & 1) {
                    x -= i;
                } else {
                    y -= i;
                }
                if (min(x, y) < 0) {
                    return i - 1;
                }
            }
        };
        return min(work(a, b), work(b, a));
    }
};

// ~ JustJie
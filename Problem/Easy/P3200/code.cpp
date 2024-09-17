/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.30.2024 17:52:07
*********************************************/

using i64 = long long;

class Solution {
public:
    int maxHeightOfTriangle(int a, int b) {
        const auto work = [&](int a, int b) -> int {
            int x = int(sqrt(a));
            int y = (-1 + int(sqrt(1 + 4 * b))) / 2;
            if (x > y) {
                return 2 * y + 1;
            } else {
                return 2 * x;
            }
        };

        return max(work(a, b), work(b, a));
    }
};

// ~ JustJie
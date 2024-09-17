/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.23.2024 23:40:26
*********************************************/

using i64 = long long;

class Solution {
public:
    string losingPlayer(int x, int y) {
        return (min(x, y / 4) % 2 == 1 ? "Alice" : "Bob");
    }
};

// ~ JustJie
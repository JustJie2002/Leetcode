/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.20.2024 10:47:45
*********************************************/

using i64 = long long;

class Solution {
public:
    string losingPlayer(int x, int y) {
        bool a = false;
        while (x && y >= 4) {
            x--;
            y -= 4;
            a = !a;
        }
        return (a ? "Alice" : "Bob");
    }
};

// ~ JustJie
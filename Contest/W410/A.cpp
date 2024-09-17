/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 08.13.2024 03:50:05
*********************************************/

using i64 = long long;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& ops) {
        int i = 0, j = 0;
        for (const auto& op : ops) {
            if (op == "RIGHT") {
                j++;
            } else if (op == "LEFT") {
                j--;
            } else if (op == "UP") {
                i--;
            } else {
                i++;
            }
        }
        return i * n + j;
    }
};

// ~ JustJie
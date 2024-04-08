/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.07.2024 02:06:06
*********************************************/

using i64 = long long;

class Solution {
public:
    bool checkValidString(string s) {
        int must = 0, can = 0;
        for (char c : s) {
            if (c == '(') {
                can++;
                must++;
            } else if (c == ')') {
                can--;
                must = max(must - 1, 0);
            } else {
                can++;
                must = max(must - 1, 0);
            }

            if (can < 0) {
                return false;
            }
        }

        return must == 0;
    }
};

// ~ JustJie
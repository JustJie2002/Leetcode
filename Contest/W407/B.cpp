/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.21.2024 17:53:17
*********************************************/

using i64 = long long;

const string V = "aeiou";

class Solution {
public:
    bool doesAliceWin(string s) {
        for (char c : s) {
            if (V.find(c) != string::npos) {
                return true;
            }
        }
        return false;
    }
};

// ~ JustJie
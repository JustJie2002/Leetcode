/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.04.2024 20:28:15
*********************************************/

using i64 = long long;

class Solution {
public:
    string makeGood(string s) {
        string t;
        for (char c : s) {
            if (t.empty()) {
                t += c;
            } else {
                if (isupper(c) && tolower(c) == t.back()) {
                    t.pop_back();
                } else if (islower(c) && toupper(c) == t.back()) {
                    t.pop_back();
                } else {
                    t += c;
                }
            }
        }

        return t;
    }
};

// ~ JustJie
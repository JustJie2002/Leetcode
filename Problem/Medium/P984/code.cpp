/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 05.27.2024 19:03:14
*********************************************/

using i64 = long long;

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string s;
        while (a || b) {
            if (a > b) {
                int t = min(2, a);
                s += string(t, 'a');
                a -= t;
                if (b) {
                    s += "b";
                    b--;
                }
            } else if (a < b) {
                int t = min(2, b);
                s += string(t, 'b');
                b -= t;
                if (a) {
                    s += "a";
                    a--;
                }
            } else {
                s += "ab";
                a--;
                b--;
            }
        }

        return s;
    }
};

// ~ JustJie
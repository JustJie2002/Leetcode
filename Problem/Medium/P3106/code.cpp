/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.07.2024 22:52:53
*********************************************/

using i64 = long long;

class Solution {
public:
    string getSmallestString(string s, int k) {
        auto ord = [&](char c) {
            return c - 'a';
        };

        auto dis = [&](char from, char to) {
            int a = ord(from);
            int b = ord(to);
            assert(a >= b);
            return min(a - b, b + 26 - a);
        };

        string t;
        for (char from : s) {
            for (char to = 'a'; to <= from; to++) {
                int d = dis(from, to);
                if (d <= k) {
                    t += to;
                    k -= d;
                    break;
                }
            }
        }

        return t;
    }
};

// ~ JustJie
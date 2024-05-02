/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.30.2024 20:35:03
*********************************************/

using i64 = long long;

class Solution {
public:
    string reversePrefix(string s, char c) {
        auto it = find(s.begin(), s.end(), c);
        if (it == s.end()) {
            return s;
        }
        reverse(s.begin(), it + 1);
        return s;
    }
};

// ~ JustJie
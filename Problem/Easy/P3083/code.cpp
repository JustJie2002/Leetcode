/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.19.2024 03:44:09
*********************************************/

using i64 = long long;

class Solution {
public:
    bool isSubstringPresent(string s) {
        int n = s.length();

        unordered_set<string> distinct;
        for (int i = 0; i < n - 1; i++) {
            auto t = s.substr(i, 2);
            distinct.insert(t);
            reverse(t.begin(), t.end());
            distinct.insert(t);
        }

        return distinct.size() < 2 * (n - 1);
    }
};

// ~ JustJie
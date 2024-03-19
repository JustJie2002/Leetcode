/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.16.2024 22:30:13
*********************************************/

using i64 = long long;

class Solution {
public:
    bool isSubstringPresent(string s) {
        int n = s.length();

        unordered_set<string> rev;
        for (int i = 0; i < n - 1; i++) {
            string t;
            t += s[i + 1];
            t += s[i];
            rev.insert(t);
        }
        for (int i = 0; i < n - 1; i++) {
            if (rev.contains(s.substr(i, 2))) {
                return true;
            }
        }

        return false;
    }
};

// ~ JustJie
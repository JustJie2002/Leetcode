/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.11.2024 15:46:38
*********************************************/

using i64 = long long;

class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.length();

        string sb;
        for (int i = 0; i < n; i++) {
            while (!sb.empty() && k && sb.back() > s[i]) {
                sb.pop_back();
                k--;
            }
            if (sb.empty() && s[i] == '0') {
                continue;
            }
            sb += s[i];
        }

        while (!sb.empty() && k--) {
            sb.pop_back();
        }

        if (sb.empty()) {
            sb = "0";
        }
        return sb;
    }
};

// ~ JustJie
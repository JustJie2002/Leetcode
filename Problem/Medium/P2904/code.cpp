/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.03.2024 18:43:14
*********************************************/

using i64 = long long;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans;
        for (int i = 0; i < n; i++) {
            string sb;
            int o = 0;
            for (int j = i; j < n; j++) {
                sb += s[j];
                o += (s[j] == '1');
                if (o == k) {
                    if (ans.empty() || (sb.length() < ans.length()) || (sb.length() == ans.length() && sb < ans)) {
                        ans = sb;
                    }
                } else if (o > k) {
                    break;
                }
            }
        }
        return ans;
    }
};

// ~ JustJie
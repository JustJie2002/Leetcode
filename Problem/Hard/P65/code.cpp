/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.03.2024 20:13:07
*********************************************/

using i64 = long long;

class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();

        bool post_dec = false;
        bool post_expo = false;
        bool digit_seen = false;

        auto good_dec_position = [&](int pos) -> bool {
            if (post_dec || post_expo) {
                return false;
            }
            if (pos > 0 && isdigit(s[pos - 1])) {
                return true;
            }
            if (pos < n - 1 && isdigit(s[pos + 1])) {
                return true;
            }
            return false;
        };
        auto good_sign_position = [&](int pos) -> bool {
            if (pos == n - 1) {
                return false;
            }
            if (pos == 0 || tolower(s[pos - 1]) == 'e') {
                return true;
            }
            return false;
        };

        for (int i = 0; i < n; i++) {
            auto c = s[i];
            if (c == '+' || c == '-') {
                if (!good_sign_position(i)) {
                    return false;
                }
            } else if (c == '.') {
                if (!good_dec_position(i)) {
                    return false;
                }
                post_dec = true;
            } else if (tolower(c) == 'e') {
                if (!digit_seen || post_expo || i == n - 1) {
                    return false;
                }
                post_expo = true;
            } else if (isalpha(c)) {
                return false;
            } else {
                digit_seen = true;
            }
        }

        return true;
    }
};

// ~ JustJie
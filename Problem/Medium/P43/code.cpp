/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.13.2024 19:50:27
*********************************************/

using i64 = long long;

class Solution {
public:
    string multiply(string a, string b) {
        int n = a.size(), m = b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        if (a == "0" || b == "0") return "0";

        auto divmod = [&](int num, int den) -> pair<int, int> {
            return {num / den, num % den};
        };

        auto ord = [&](char c) -> int { return c - '0'; };
        auto chr = [&](int d) -> char { return d + '0'; };

        auto op = [&](int d, int p) -> string {
            int carry = 0;
            auto prod = string(p, '0');
            for (int i = 0; i < n; i++) {
                auto cur = d * ord(a[i]) + carry;
                auto [nex, add] = divmod(cur, 10);
                carry = nex;
                prod += chr(add);
            }

            if (carry > 0) {
                prod += to_string(carry);
            }

            return prod;
        };

        vector<string> comp;
        int max_len = 0;
        for (int i = 0; i < m; i++) {
            auto res = op(ord(b[i]), i);
            comp.push_back(res);
            max_len = max<int>(max_len, size(res));
        }

        for (int i = 0; i < m; i++) {
            int sz = size(comp[i]);
            comp[i] += string(max_len - sz, '0');
        }

        string ans = "";
        int carry = 0;
        for (int j = 0; j < max_len; j++) {
            auto sum = carry;
            for (int i = 0; i < m; i++) {
                sum += ord(comp[i][j]);
            }

            auto [nex, add] = divmod(sum, 10);
            ans += chr(add);
            carry = nex;
        }

        if (carry > 0) {
            ans += to_string(carry);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// ~ JustJie
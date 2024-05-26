/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.22.2024 18:17:23
*********************************************/

using i64 = long long;

constexpr i64 inf = 1e18;

class Solution {
public:
    i64 toI64(const string& val) {
        i64 res = 0;
        for (auto c : val) {
            res *= 10LL;
            res += (c - '0');
        }
        return res;
    }

    string nearestPalindromic(string s) {
        int n = s.length();
        i64 a = toI64(s);

        if (n == 1) {
            a--;
            return to_string(a);
        }

        vector<i64> cands;
        string first_half = s.substr(0, n / 2);
        i64 b = toI64(first_half);
        for (int d = -1; d <= 1; d++) {
            i64 nb = b + d;
            auto t = to_string(nb);
            if (t.length() != first_half.length()) {
                continue;
            }
            auto rt = t;
            reverse(rt.begin(), rt.end());
            if ((n & 1) && nb != 0) {
                for (char m = '0'; m <= '9'; m++) {
                    auto res = t + m + rt;
                    i64 c = toI64(res);
                    cands.push_back(c);
                }
            } else {
                auto res = t + rt;
                i64 c = toI64(res);
                cands.push_back(c);
            }
        }

        cands.push_back(pow(10, n) + 1);
        cands.push_back(toI64(string(n - 1, '9')));

        sort(cands.begin(), cands.end());

        i64 ans = -1;
        i64 dif = inf;
        for (i64 x : cands) {
            i64 cur_dif = abs(x - a);
            if (cur_dif == 0) {
                continue;
            }
            if (cur_dif < dif) {
                dif = cur_dif;
                ans = x;
            }
        }

        return to_string(ans);
    }
};

// ~ JustJie
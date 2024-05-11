/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.04.2024 22:36:56
*********************************************/

using i64 = long long;
using Tracker = array<int, 26>

const Tracker EMPTY {};

class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.length();

        auto ord = [&](char c) {
            return c - 'a';
        };

        auto issoke = [&](int siz) {
            Tracker base {};
            for (int i = 0; i < siz; i++) {
                base[ord(s[i])]++;
            }
            Tracker freq {};
            bool add = true;
            for (int i = 0; i < n; i += siz, add = !add) {
                for (int j = 0; j < siz; j++) {
                    freq[ord(s[i + j])] += (add ? +1 : -1);
                }
                if (add && freq != base) {
                    return false;
                }
                if (!add && freq != EMPTY) {
                    return false;
                }
            }
            return true;
        };

        int ans = n;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (issoke(i)) {
                    return i;
                }
                if (issoke(n / i)) {
                    ans = n / i;
                }
            }
        }

        return ans;
    }
};

// ~ JustJie
/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.06.2024 22:37:55
*********************************************/

using i64 = long long;

constexpr int A = 26;

class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.length();
        string t;
        auto dis = [&](int o, int a) -> int {
            if (o == a) {
                return 0;
            } else if (o < a) {
                return min(a - o, A - o + a);
            } else {
                return min(o - a, a + (A - o));
            }
            assert(false);
        };
        for (int i = 0; i < n; i++) {
            int o = s[i] - 'a';
            int mi = A;
            for (int a = 0; a < A; a++) {
                if (dis(o, a) <= k) {
                    mi = min(mi, a);
                    break;
                }
            }
            k -= dis(o, mi);
            t += mi + 'a';
        }
        return t;
    }
};

// ~ JustJie
/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.17.2024 21:30:16
*********************************************/

using i64 = long long;

constexpr int A = 26;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();

        // good(a, b),  a is both prefix and suffix of b
        auto good = [&](const auto& a, const auto& b) {
            int al = a.length(), bl = b.length();

            if (al > bl) {
                return false;
            }

            // check prefix
            if (b.substr(0, al) != a) {
                return false;
            }
            // check suffix
            if (b.substr(bl - al) != a) {
                return false
            }
            return true;
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (good(words[i], words[j])) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

// ~ JustJie
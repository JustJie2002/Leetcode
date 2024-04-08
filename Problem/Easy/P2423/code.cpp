/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.27.2024 02:46:40
*********************************************/

using i64 = long long;

constexpr int A = 26;

class Solution {
public:
    bool equalFrequency(string word) {
        int n = word.length();

        array<int, A> freq {};
        for (char c : word) {
            int o = c - 'a';
            freq[o]++;
        }

        auto check = [&]() -> bool {
            int cnt = -1;
            for (int a = 0; a < A; a++) {
                if (freq[a]) {
                    if (cnt == -1) {
                        cnt = freq[a];
                    } else if (freq[a] != cnt) {
                        return false;
                    }
                }
            }
            return true;
        };

        bool good = false;
        for (int a = 0; a < A; a++) {
            if (freq[a]) {
                freq[a]--;
                good |= check();
                freq[a]++;
            }
        }

        return good;
    }
};

// ~ JustJie
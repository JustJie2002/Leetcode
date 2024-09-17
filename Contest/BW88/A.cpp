/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.17.2024 23:16:57
*********************************************/

using i64 = long long;

constexpr int A = 26;

class Solution {
public:
    bool equalFrequency(string s) {
        array<int, 26> freq {};
        for (char c : s) {
            freq[c - 'a']++;
        }

        for (int a = 0; a < A; a++) {
            if (freq[a]) {
                freq[a]--;
                int p = -1;
                bool ok = true;
                for (int b = 0; b < A; b++) {
                    if (freq[b]) {
                        if (p == -1 || p == freq[b]) {
                            p = freq[b];
                        } else {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok) {
                    return true;
                }
                freq[a]++;
            }
        }

        return false;
    }
};

// ~ JustJie
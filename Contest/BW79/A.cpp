/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.02.2024 22:26:40
*********************************************/

using i64 = long long;

class Solution {
public:
    bool digitCount(string s) {
        array<int, 10> freq {};
        for (char c : s) {
            int o = c - '0';
            freq[o]++;
        }
        for (int i = 0; i < s.length(); i++) {
            int o = s[i] - '0';
            if (freq[i] != o) {
                return false;
            }
        }
        return true;
    }
};

// ~ JustJie
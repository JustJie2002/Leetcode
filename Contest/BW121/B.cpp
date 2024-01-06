/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.06.2024 13:24:00
*********************************************/

using i64 = long long;

constexpr int B = 31;

class Solution {
public:
    int minOperations(vector<int>& a, int k) {
        int Xor = k;
        for (int x : a) {
            Xor ^= x;
        }

        auto bit = [&](int mask, int nth) {
            return mask >> nth & 1;
        };

        int ans = 0;
        for (int b = 0; b < B; b++) {
            ans += bit(Xor, b);
        }

        return ans;
    }
};

// ~ JustJie
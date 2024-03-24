/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.24.2024 02:44:40
*********************************************/

using i64 = long long;

constexpr int MOD = 1'000'000'007;

class Solution {
public:
    i64 summation(i64 s, i64 e) {
        i64 n = e - s + 1;
        return n * (s + e) / 2;
    }

    int minimumPossibleSum(int n, int t) {
        i64 sum = 0;
        int m = t / 2;
        if (n <= m) {
            sum += summation(1, n);
        } else {
            sum += summation(1, m);
            int rem = n - m;
            sum += summation(t, t + rem - 1);
        }
        sum %= MOD;
        return sum;
    }
};

// ~ JustJie
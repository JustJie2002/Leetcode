/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.14.2024 02:09:20
*********************************************/

using i64 = long long;

class Solution {
public:
    int maximumPrimeDifference(vector<int>& a) {
        int n = a.size();

        auto is_prime = [&](int x) {
            if (x == 1) {
                return false;
            }
            for (int f = 2; f * f <= x; f++) {
                if (x % f == 0) {
                    return false;
                }
            }
            return true;
        };

        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (is_prime(a[i])) {
                pos.push_back(i);
            }
        }

        return pos.back() - pos[0];
    }
};

// ~ JustJie
/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.17.2024 17:30:11
*********************************************/

using i64 = long long;

class Solution {
public:
    int sumOfEncryptedInt(vector<int>& a) {
        int n = a.size();

        auto f = [&](int x) -> int {
            auto s = to_string(x);
            int mx = *max_element(s.begin(), s.end()) - '0';
            int res = 0;
            for (char c : s) {
                res *= 10;
                res += mx;
            }
            return res;
        };

        int ans = 0;
        for (int x : a) {
            ans += f(x);
        }
        return ans;
    }
};

// ~ JustJie
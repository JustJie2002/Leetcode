/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.01.2024 10:07:19
*********************************************/

using i64 = long long;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();

        vector<int> dif(n + 1);
        for (const auto& info : shifts) {
            int del = (info[2] == 0 ? -1 : +1);
            dif[info[0]] += del;
            dif[info[1] + 1] -= del;
        }

        auto norm = [&](int o) -> int {
            o %= 26;
            if (o < 0) o += 26;
            return o;
        };

        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += dif[i];
            int o = norm(s[i] - 'a' + cur);
            s[i] = char(o + 'a');
        }

        return s;
    }
};

// ~ JustJie
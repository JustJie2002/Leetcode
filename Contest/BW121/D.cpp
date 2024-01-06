/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.06.2024 13:31:18
*********************************************/

using i64 = long long;

constexpr int N = 20;
int lim;
string suf, str;
bool good;
int n, m;
i64 dp[N][2][2];

i64 f(int idx, bool tight, bool leading) {
    if (idx == n - m) {
        return tight ? int(good) : 1;
    }
    auto& res = dp[idx][tight][leading];
    if (res != -1) {
        return res;
    }
    res = 0;
    int cur_dig = str[idx] - '0';
    for (int d = 0; d <= lim; d++) {
        bool is_tight = tight && (cur_dig == d);
        bool is_leading = leading && (d == 0);
        res += f(idx + 1, is_tight, is_leading);
        if (tight && cur_dig == d) {
            break;
        }
    }
    return res;
}

bool is_good(i64 x, bool eq = false) {
    str = to_string(x);
    n = str.size();
    return n >= m && stoll(str.substr(n - m)) >= stoll(suf);
}

i64 solve(i64 x) {
    good = is_good(x);
    memset(dp, -1, sizeof(dp));
    return (n < m ? 0 : f(0, true, true));
}

class Solution {
public:
    i64 numberOfPowerfulInt(i64 start, i64 finish, int limit, string s) {
        lim = limit;
        suf = s;
        m = suf.length();
        return solve(finish) - solve(start - 1);
    }
};

// ~ JustJie
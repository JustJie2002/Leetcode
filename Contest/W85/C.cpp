/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.06.2024 22:03:04
*********************************************/

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cout << " " << to_string(H);
    debug_out(T...);
}

// #define BROKEN_CODE

#ifdef BROKEN_CODE
    #define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #define dbp(...) cout << __VA_ARGS__ << "\n";
#else
    #define dbg(...) 10082002
    #define dbp(...) "Gimme Internship"
#endif

using i64 = long long;

class Solution {
public:
    double new21Game(int n, int k, int most) {
        vector<double> dp(n + 1);
        dp[0] = 1.0;
        if (n > 0) dp[1] = -1.0;
        double res = 0;
        for (int i = 0; i < k; i++) {
            res += dp[i];
            if (i + 1 <= n) {
                dp[i + 1] += res / most;
            }
            if (i + most + 1 <= n) {
                dp[i + most + 1] -= res / most;
            }
        }

        double ans = 0;
        for (int i = k; i <= n; i++) {
            ans += res += dp[i];
        }
        return ans;
    }
};

// ~ JustJie
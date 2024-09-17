/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.14.2024 22:47:03
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

#define BROKEN_CODE

#ifdef BROKEN_CODE
    #define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #define dbp(...) cout << __VA_ARGS__ << "\n";
#else
    #define dbg(...) 10082002
    #define dbp(...) "Gimme Internship"
#endif

using i64 = long long;

constexpr int N = 4;
constexpr i64 inf = i64(1e13) + 10;

class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();

        vector<i64> dp(N + 1, -inf);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = N; j > 0; j--) {
                dp[j] = max(dp[j], dp[j - 1] + 1LL * a[j - 1] * b[i]);
            }
        }

        return dp[N];
    }
};

// ~ JustJie
/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.09.2024 21:30:40
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
using Segment = pair<int, int>;
using Info = pair<i64, Segment>;

constexpr i64 inf = 1e15;

/*
dp[i][j] - from [0, i], we want to choose j disjointed subarray that maximize the strength

I know how to write the solution for the "in order" disjointed subarray O(NK) dp but here's the thing
> You need to select k disjoint subarrays from nums, such that their strength is maximum.
It never specified whether those disjointed subarrays chosen have to be in order or not, the samples are complete trash since it doesn't explain anything
Lack of information
If one of the examples was like [1, -2, 9], k = 3, then it'll tell us that the disjointed subarrays chosen are "in order" or not
*/

class Solution {
public:
    i64 maximumStrength(vector<int>& a, int k) {
        a.push_back(0);
        int n = a.size();

        vector<i64> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + a[i];
        }

        vector dp(n + 1, vector<i64>(k + 1, -inf));
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= min(i + 1, k); j++) {
                
            }
        }

        return 0;
    }
};

// ~ JustJie
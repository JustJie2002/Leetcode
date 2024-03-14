/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.12.2024 22:16:56
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

class Solution {
public:
    long long minSumSquareDiff(vector<int>& a, vector<int>& b, int k1, int k2) {
        int n = a.size();

        map<int, int> freq;

        for (int i = 0; i < n; i++) {
            int dif = abs(a[i] - b[i]);
            freq[dif]++;
        }

        int tk = k1 + k2;
        vector<pair<int, int>> p = {{0, 0}};
        for (const auto& [k, v] : freq) {
            p.emplace_back(k, v);
        }

        int m = p.size();

        auto divmod = [&](int x, int mod) {
            return make_pair(x / mod, x % mod);
        };

        while (m > 1 && tk > 0) {
            int w = p[m - 2].first;
            auto [k, v] = p[m - 1];
            p.pop_back();
            m--;
            int d = k - w;
            int need = d * v;
            if (tk >= need) {
                tk -= need;
                p[m - 1].second += v;
            } else {
                auto [l, rem] = divmod(tk, v);
                p.emplace_back(k - l, v - rem);
                p.emplace_back(k - l - 1, rem);
                tk = 0;
            }
        }

        i64 ans = 0;
        for (const auto& [k, v] : p) {
            i64 sq = 1LL * k * k;
            ans += sq * v;
        }

        return ans;
    }
};

// ~ JustJie
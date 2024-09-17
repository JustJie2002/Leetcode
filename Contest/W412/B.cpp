/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 08.24.2024 23:04:26
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
    int countPairs(vector<int>& a) {
        int n = a.size();

        vector<string> str(n);
        vector<string> sor(n);
        int sz = 0;
        for (int i = 0; i < n; i++) {
            str[i] = to_string(a[i]);
            sor[i] = str[i];
            ranges::sort(sor[i]);
            sz = max<int>(sz, str[i].size());
        }

        for (int i = 0; i < n; i++) {
            int m = str[i].size();
            int need_zero = sz - m;
            str[i] = string(need_zero, '0') + str[i];
            sor[i] = string(need_zero, '0') + sor[i];
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (sor[i] != sor[j]) {
                    continue;
                }
                int d = 0;
                for (int k = 0; k < sz; k++) {
                    d += int(str[i][k] != str[j][k]);
                }
                if (d <= 2) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

// ~ JustJie
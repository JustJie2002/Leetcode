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

constexpr int N = 8;

int pw[N];

void Init() {
    if (pw[0] == 1) {
        return;
    }
    pw[0] = 1;
    for (int i = 1; i < N; i++) {
        pw[i] = pw[i - 1] * 10;
    }
}

const auto Init = [&]() {
    pw[0] = 1;
    for (int i = 1; i < N; i++) {
        pw[i] = pw[i - 1] * 10;
    }
}();

class Solution {
public:
    int countPairs(vector<int>& a) {
        Init();
        int n = a.size();

        ranges::sort(a);

        vector<string> str(n);
        vector<string> sor(n);
        int sz = 0;
        for (int i = 0; i < n; i++) {
            str[i] = to_string(a[i]);
            sor[i] = str[i];
            ranges::sort(sor[i]);
            sz = max<int>(sz, str[i].size());
            ranges::sort(str[i]);
            ranges::sort(sor[i]);
        }

        for (int i = 0; i < n; i++) {
            int m = str[i].size();
            int need_zero = sz - m;
            str[i] += string(need_zero, '0');
            sor[i] += string(need_zero, '0');
        }

        vector pre(n, vector<int>(m + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pre[i][j + 1] = pre[i][j] + (str[i][j] - '0') * pw[j];
            }
        }

        const auto my_swap = [&](int i, int j, int k) {
            
        };

        const auto my_swap1 = [&](int i, int j, int k, int j1) {
            
        };
        
        const auto my_swap2 = [&](int i, int j, int k, int j1, int k1) {
            
        };
        

        int ans = 0;
        unordered_map<string, int> occs;
        for (int i = 0; i < n; i++) {
            ans += occs[str[i]];

            for (int j = 0; j < sz; j++) {
                for (int k = j + 1; k < sz; k++) {
                    if (str[i][j] !+ str[i][k]) {
                        my_swap(i, j, k);
                        for (int j1 = k + 1; j1 < sz; j1++) {
                            my_swap1(i, j, k, j1);
                            for (int k1 = j1 + 1; k1 < sz; k1++) {
                                my_swap2(i, j, k, j1, k2);
                            }
                        }
                    }
                }
            }

            occs[str[i]]++;
        }
        return ans;
    }
};

// ~ JustJie
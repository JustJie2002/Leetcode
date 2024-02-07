/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.20.2024 21:35:12
*********************************************/

using i64 = long long;

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

class Solution {
public:
    vector<i64> countOfPairs(int n, int x, int y) {
        vector<i64> ans(n);
        int m = n - 1;
        if (x > y) swap(x, y);
        if (x == y || x + 1 == y) {
            int cur = 2 * m;
            for (int i = 0; i < n; i++) {
                ans[i] = cur;
                cur -= 2;
            }
            return ans;
        }
        x--, y--;

        // vector<int> freq(n + 2);
        map<int, int> freq;
        auto add = [&](int i, int v) {
            cout << i << " " << v << "\n";
            freq[i] += v;
        };


        int inside = y - x + 1;
        int L = x, R = n - y - 1;
        dbp("GOOD");
        for (int i = 0; i < x; i++) {
            if (i) {
                add(i - 1, 1);
            }
            int dis = x - i;
            int l = (inside + 1) / 2;
            add(dis + l - 1, 1);
            int r = inside - l;
            add(dis + r, 1);
            add(dis, -1);
            add(dis + R + 1, 1);
            add(dis + 1, -1);
        }
        for (int i = x; i <= y; i++) {
            int pos = i - x + 1;
            if (inside % 2 == 1 && pos == (inside + 1) / 2) {
                // cout << "CENTER:\n";
                // add(i, 1);
                // add(n - i - 1, 1);
                continue;
            }
            if (pos <= (inside + 1) / 2) {
                cout << "LEFT:\n";
                add(i, 1);
                int a = pos - 1;
                int bb = pos;
                int l = i + bb;
                int rem = y - l;
                int ll = rem / 2;
                int rr = rem - ll;
                add(bb + ll, 1);
                add(rr, 1);
                add(rr - 1, -1);
                add(R + a + 1, 1);
                add(a, -1);
            } else {
                // cout << "RIGHT\n";
                add(n - i - 1, 1);
                int b = inside - pos;
                int aa = b + 1;
                int r = i - aa;
                int rem = r - x - 1;
                int ll = (rem + 1) / 2;
                int rr = rem - ll;
                add(aa + rr, 1);
                add(ll, 1);
                add(ll - 1, -1);
                add(L + b + 1, 1);
                add(b, -1);
            }
        }
        // cout << "RIGHT SIDE:\n";
        for (int i = y + 1; i < n; i++) {
            int rem = n - i - 1;
            if (rem) {
                // cout << "YES\n";
                add(rem, 1);
            }
            int dis = i - y;
            int l = (inside + 1) / 2;
            int r = inside - l;
            add(dis + l - 1, 1);
            add(dis + r, 1);
            add(dis, -1);
            add(dis + L + 1, 1);
            add(dis + 1, -1);
        }

        i64 cur = 0;
        for (int i = n; i >= 1; i--) {
            cur += freq[i];
            ans[i - 1] = cur;
        }
        return ans;
    }
};

// ~ JustJie
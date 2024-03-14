/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.12.2024 21:27:51
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
using Segment = array<int, 2>;

class Solution {
public:
    vector<int> movesToStamp(string st, string t) {
        int n = st.size(), m = t.size();

        vector<bool> marked(m);
        vector<int> ans;

        auto work = [&](int pos) -> bool {
            bool good = false;
            for (int i = 0; i < n; i++) {
                if (marked[pos + i])
                    continue;
                if (t[pos + i] != st[i])
                    return false;
                good = true;
            }

            if (good) {
                ans.push_back(pos);
                for (int i = 0; i < n; i++)
                    marked[i + pos] = true;
            }

            return good;
        };

        bool working = true;
        do {
            working = false;
            for (int i = 0; i < m - n + 1; i++)
                working |= work(i);
        } while (working);

        if (any_of(marked.begin(), marked.end(), [&](bool b) { return !b; }))
            return {};

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// ~ JustJie
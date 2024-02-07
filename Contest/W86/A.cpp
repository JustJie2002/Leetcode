/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.01.2024 21:33:23
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

// #define BROKEN_CODE

#ifdef BROKEN_CODE
    #define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #define dbp(...) cout << __VA_ARGS__ << "\n";
#else
    #define dbg(...) 10082002
    #define dbp(...) "Gimme Internship"
#endif

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int all_seen = 0;
        for (int i = 1; i < 10; i++) {
            all_seen |= (1 << i);
        }

        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                set<int> sums;
                int cur_sum_dia = mat[i][j] + mat[i + 2][j + 2];
                cur_sum_dia -= (mat[i + 2][j] + mat[i][j + 2]);
                int msk = 0;
                for (int di = 0; di < 3; di++) {
                    int cur_sum_row = 0;
                    for (int dj = 0; dj < 3; dj++) {
                        cur_sum_row += mat[i + di][j + dj];
                        msk |= (1 << mat[i + di][j + dj]);
                    }
                    sums.insert(cur_sum_row);
                }
                for (int di = 0; di < 3; di++) {
                    int cur_sum_col = 0;
                    for (int dj = 0; dj < 3; dj++) {
                        cur_sum_col += mat[i + dj][j + di];
                    }
                    sums.insert(cur_sum_col);
                }
                if (msk == all_seen && int(sums.size()) == 1 && cur_sum_dia == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

// ~ JustJie
/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.30.2023 21:42:03
*********************************************/

using i64 = long long;

constexpr int ord(char c) {
    return c - 'a';
}

array<int, 26> operator-(const array<int, 26>& a, const array<int, 26>& b) {
    array<int, 26> c;
    for (int i = 0; i < 26; i++) {
        c[i] = a[i] - b[i];
    }
    return c;
}

void print(const array<int, 26>& a) {
    for (int i = 0; i < 26; i++) {
        cout << a[i] << " \n"[i == 25];
    }
}

class Solution {
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        int n = s.length(), Q = queries.size();

        vector<int> is_pal(n / 2 + 1);
        for (int i = 0; i < n / 2; i++) {
            is_pal[i + 1] = is_pal[i];
            if (s[i] == s[n - i - 1]) {
                is_pal[i + 1]++;
            }
        }

        vector<array<int, 26>> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i];
            pre[i + 1][ord(s[i])]++;
        }

        auto get = [&](int L, int R) -> array<int, 26> {
            return pre[R + 1] - pre[L];
        };

        vector<bool> res(Q, true);
        for (int q = 0; q < Q; q++) {
            int a = queries[q][0], b = queries[q][1];
            int c = queries[q][2], d = queries[q][3];

            if (n % 2 == 1 && c == n / 2) {
                c++;
            }

            auto L = get(a, b);
            auto R = get(c, d);

            // check if there's any corresponding parts
            int opd = n - a - 1, opc = n - b - 1;
            int opa = n - d - 1, opb = n - c - 1;

            pair<int, int> area = {min(a, opa), max(b, opb)};

            if (is_pal[area.first] != area.first) {
                res[q] = false;
                continue;
            }

            area.second++;
            if (area.second < n / 2 && is_pal.back() - is_pal[area.second] != n / 2 - area.second) {
                res[q] = false;
                continue;
            }

            pair<int, int> area2 = {max(a, opa), min(b, opb)};

            if (area2.first <= area2.second) {
                if (a < opa && b >= opa) {
                    const auto& aa = get(d + 1, opd);
                    L = L - aa;
                }
                if (b > opb && a <= opb) {
                    const auto& bb = get(opc, c - 1);
                    L = L - bb;
                }
                if (opc > c && d >= opc) {
                    const auto& cc = get(b + 1, opb);
                    R = R - cc;
                }
                if (opd < d && c <= opd) {
                    const auto& dd = get(opa, a - 1);
                    R = R - dd;
                }
            } else {
                const auto& aa = get(opa, opb);
                R = R - aa;
                const auto& bb = get(opc, opd);
                L = L - bb;
                swap(area2.first, area2.second);
                area2.first++;
                area2.second--;
                if (is_pal[area2.second + 1] - is_pal[area2.first] != area2.second - area2.first + 1) {
                    res[q] = false;
                    continue;
                }
            }

            for (int a = 0; a < 26; a++) {
                if (L[a] < 0) {
                    res[q] = false;
                    break;
                }
                if (R[a] < 0) {
                    res[q] = false;
                    break;
                }
                if (L[a] != R[a]) {
                    res[q] = false;
                    break;
                }
            }
        }

        return res;
    }
};

// ~ JustJie
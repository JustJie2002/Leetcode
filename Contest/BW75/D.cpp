/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.04.2024 20:50:46
*********************************************/

using i64 = long long;

vector<int> z_func(const string& s) {
    int n = s.length();
    vector<int> z(n);
    int l = -1, r = -1;
    for (int i = 1; i < n; i++) {
        z[i] = (i >= r ? 0 : min(r - i, z[i - l]));
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    z[0] = n;
    return z;
}

class Solution {
public:
    long long sumScores(string s) {
        auto z = z_func(s);
        return accumulate(z.begin(), z.end(), 0LL);
    }
};

// ~ JustJie
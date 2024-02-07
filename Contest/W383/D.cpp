/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.03.2024 21:38:00
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
    return z;
}

class Solution {
public:
    int minimumTimeToInitialState(string s, int k) {
        int n = s.size();

        auto z = z_func(s);
        for (int i = 1; i < n; i++) {
            if (i % k == 0 && z[i] == n - i) {
                return i / k;
            }
        }
        return (n + k - 1) / k;
    }
};

// ~ JustJie
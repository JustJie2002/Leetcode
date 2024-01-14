/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.13.2024 21:31:45
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

void debug(const vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {

        auto solve = [&](const string& x, const string& y) {
            int n = y.length(), m = x.length();
            auto str = y + "$" + x;
            const auto& z = z_func(str);
            set<int> res;
            for (int i = n + 1; i < n + m + 1; i++) {
                if (z[i] == n) {
                    res.insert(i - n - 1);
                }
            }
            return res;
        };

        auto pa = solve(s, a);
        auto pb = solve(s, b);
        
        vector<int> ans;
        for (int i : pa) {
            auto it = pb.lower_bound(i - k);
            if (it != pb.end()) {
                int j = *it;
                if (abs(j - i) <= k) {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};

// ~ JustJie
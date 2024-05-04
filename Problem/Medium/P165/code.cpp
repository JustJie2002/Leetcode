/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.02.2024 21:37:12
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> get(string ver) {
        ver += '.';
        vector<int> v;
        string sb;
        for (char c : ver) {
            if (c == '.') {
                if (!sb.empty()) {
                    v.push_back(stoi(sb));
                }
                sb = "";
            } else {
                sb += c;
            }
        }
        while (!v.empty() && !v.back()) {
            v.pop_back();
        }
        return v;
    }

    int compareVersion(string v1, string v2) {
        auto a = get(v1);
        auto b = get(v2);

        int n = a.size(), m = b.size();
        for (int i = 0; i < min(n, m); i++) {
            if (a[i] == b[i]) {
                continue;
            }
            if (a[i] < b[i]) {
                return -1;
            } else {
                return 1;
            }
        }
        if (n == m) {
            return 0;
        }
        return (n < m ? -1 : +1);
    }
};

// ~ JustJie
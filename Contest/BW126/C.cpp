/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.17.2024 17:22:46
*********************************************/

using i64 = long long;

constexpr int A = 26;

class Solution {
public:
    string minimizeStringValue(string s) {
        int n = s.length();

        string t = s;
        array<int, A> freq {};
        vector<int> pos;
        int m = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != '?') {
                freq[s[i] - 'a']++;
            } else {
                pos.push_back(i);
                m++;
            }
        }

        string add;
        while (m--) {
            int mi = *min_element(freq.begin(), freq.end());
            for (int a = 0; a < A; a++) {
                if (freq[a] == mi) {
                    freq[a]++;
                    add.push_back(a);
                    break;
                }
            }
        }

        sort(add.rbegin(), add.rend());

        for (int p : pos) {
            t[p] = char(add.back() + 'a');
            add.pop_back();
        }

        return t;
    }
};

// ~ JustJie
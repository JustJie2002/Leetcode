/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.06.2024 18:18:36
*********************************************/

using i64 = long long;
using Key = pair<int, int>;

const string vowels = "aeiou";

bool is_vowel(char c) {
    return vowels.find(c) != string::npos;
}

class Solution {
public:
    i64 beautifulSubstrings(string s, int k) {
        vector<int> a;
        for (char c : s) {
            a.push_back(is_vowel(c) ? 1 : -1);
        }

        vector<int> sq;
        for (int i = 0; i < 2 * k; i++) {
            if ((i * i) % (4 * k) == 0) {
                sq.push_back(i);
            }
        }

        i64 res = 0;
        map<Key, int> out = {
            {{0, 0}, 1}
        };
        int pre = 0, ct = 0;
        for (int v : a) {
            pre += v;
            ct++;

            if (ct == 2 * k) {
                ct = 0;
            }

            for (int q : sq) {
                int search = q + ct;
                if (search >= 2 * k) {
                    search -= 2 * k;
                }
                Key cur_key = make_pair(pre, search);
                res += out[cur_key];
            }

            Key key = make_pair(pre, ct);
            out[key]++;
        }

        return res;
    }
};


// ~ JustJie
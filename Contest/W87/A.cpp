/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.01.2024 21:06:38
*********************************************/

using i64 = long long;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        auto dostuff = [&](const string& s) {
            string res;
            for (auto c : s) {
                if (c == '#') {
                    if (res.empty()) {
                        continue;
                    }
                    res.pop_back();
                } else {
                    res += c;
                }
            }
            return res;
        };

        return dostuff(s) == dostuff(t);
    }
};

// ~ JustJie
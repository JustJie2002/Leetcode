/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 08.16.2024 20:24:12
*********************************************/

using i64 = long long;
using Info = array<int, 2>;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<Info> stk;
        for (char c : s) {
            if (stk.empty()) {
                stk.push_back({c, 1});
            } else {
                if (stk.back()[0] == c) {
                    stk.back()[1]++;
                    if (stk.back()[1] == k) {
                        stk.pop_back();
                    }
                } else {
                    stk.push_back({c, 1});
                }
            }
        }
        
        string ans;
        for (const auto& [c, f] : stk) {
            ans += string(f, c);
        }
        return ans;
    }
};

// ~ JustJie
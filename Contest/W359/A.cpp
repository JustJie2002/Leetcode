/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.08.2024 00:57:18
*********************************************/

using i64 = long long;

class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string t;
        for (auto& word : words) {
            t += word[0];
        }
        return s == t;
    }
};

// ~ JustJie
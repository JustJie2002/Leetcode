/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.06.2024 18:20:18
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char c) {
        int n = words.size();

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (words[i].find(c) != string::npos) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

// ~ JustJie
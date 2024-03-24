/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.20.2024 23:03:29
*********************************************/

using i64 = long long;

class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n = words.size();

        auto ord = [&](char c) -> int {
            return c - 'a';
        };

        unordered_map<int, int> freq;
        int ans = 0;
        for (const auto& word : words) {
            int msk = 0;
            for (char c : word) {
                msk |= (1 << ord(c));
            }
            ans += freq[msk]++;
        }

        return ans;
    }
};

// ~ JustJie
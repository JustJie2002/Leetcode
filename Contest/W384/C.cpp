/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.10.2024 21:31:53
*********************************************/

using i64 = long long;

constexpr int A = 26;

class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        array<int, A> occ {};

        auto ord = [&](char c) -> int {
            return c - 'a';
        };

        vector<int> siz;
        for (const auto& word : words) {
            siz.push_back(size(word));
            for (char c : word) {
                occ[ord(c)]++;
            }
        }

        int use = 0;
        for (int a = 0; a < A; a++) {
            use += occ[a] / 2;
        }

        sort(siz.begin(), siz.end());

        int ans = 0;
        for (int x : siz) {
            int need = x / 2;
            if (need > use) break;
            ans++;
            use -= need;
        }

        return ans;
    }
};

// ~ JustJie
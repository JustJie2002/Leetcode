/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.13.2024 21:30:15
*********************************************/

using i64 = long long;

class Solution {
public:
    int maxFrequencyElements(vector<int>& a) {
        map<int, int> freq;
        int mx = 0;
        for (int x : a) {
            mx = max(++freq[x], mx);
        }
        int ans = 0;
        for (auto& [x, f] : freq) {
            if (mx == f) {
                ans += f;
            }
        }
        return ans;
    }
};

// ~ JustJie
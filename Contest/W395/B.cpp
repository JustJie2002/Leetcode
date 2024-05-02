/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.27.2024 22:24:34
*********************************************/

using i64 = long long;

constexpr int inf = 1e9 + 5;

class Solution {
public:
    int minimumAddedInteger(vector<int>& a, vector<int>& b) {
        map<int, int> freq;
        for (int x : b) {
            freq[x]++;
        }

        map<int, int> freq2;
        for (int x : a) {
            freq2[x]++;
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int n = a.size();
        int ans = inf;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                freq[a[i]]--;
                freq[a[j]]--;
                int k = 0;
                int res = inf;
                bool same = true;
                for (int l = 0; l < n; l++) {
                    if (l == i || l == j) {
                        continue;
                    }
                    int d = b[k] - a[l];
                    if (res == inf) {
                        res = d;
                    } else if (res != d) {
                        same = false;
                        break;
                    }
                    k++;
                }
                if (same) {
                    ans = min(ans, res);
                }
            }
        }
        return ans;
    }
};

// ~ JustJie
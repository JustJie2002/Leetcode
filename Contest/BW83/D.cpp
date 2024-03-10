/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.07.2024 21:49:15
*********************************************/

using i64 = long long;

class Solution {
public:
    int shortestSequence(vector<int>& a, int k) {
        int n = a.size();

        if (k == 1) {
            return n + 1;
        }

        vector<vector<int>> pos(k + 1);
        vector<int> ptr(k + 1), cnt(k + 1);
        for (int i = 0; i < n; i++) {
            pos[a[i]].push_back(i);
            cnt[a[i]]++;
        }

        int cur = 0;
        int sz = 1;
        // O(N)
        while (true) {
            int ma = 0;
            for (int i = 1; i <= k; i++) {
                while (ptr[i] < cnt[i] && pos[i][ptr[i]] < cur) {
                    ptr[i]++;
                }
                if (ptr[i] == cnt[i]) {
                    return sz;
                }
                ma = max(ma, pos[i][ptr[i]]);
            }
            sz++;
            cur = ma + 1;
        }

        assert(false);
    }
};

// ~ JustJie
/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 07.27.2024 22:38:02
*********************************************/

using i64 = long long;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> pos;
        pos.push_back(-1);
        map<int, int> idx;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                idx[i] = pos.size();
                pos.push_back(i);
            }
        }
        pos.push_back(n);
        int m = n - pos.size() + 2;

        int sqr = 1;
        while (sqr * sqr <= m) {
            sqr++;
        }
        sqr = min(sqr, int(pos.size() - 2));

        int ans = 0;
        int streak = 0;
        for (char c : s) {
            if (c == '1') {
                streak++;
            } else {
                streak = 0;
            }
            ans += streak;
        }

        for (int j = 1; j < pos.size() - 1; j++) {
            int R = pos[j + 1] - pos[j] - 1;
            int bet = 0;
            for (int i = j - 1; i >= 0; i--) {
                int cur = j - i;
                if (cur > sqr) {
                    break;
                }
                cur *= cur;
                int L = pos[i + 1] - pos[i] - 1;
                if (L + R + bet >= cur) {
                    cur -= bet;
                    int mi = min(L, R);
                    int ma = max(L, R);
                    for (int t = 0; t <= mi; t++) {
                        int need = max(0, cur - t);
                        if (need > ma) {
                            continue;
                        }
                        ans += ma - need + 1;
                    }
                }
                bet += L;
            }
        }
        return ans;
    }
};

// ~ JustJie
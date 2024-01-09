/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.06.2024 17:57:45
*********************************************/

using i64 = long long;
using Segment = pair<int, int>;

constexpr int A = 26;
constexpr int ord(char c) { return c - 'a'; }
class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int n = word.size();

        vector<vector<int>> pos(A);
        for (int i = n - 1; i >= 0; i--) {
            pos[ord(word[i])].push_back(i);
        }

        vector<Segment> segments;
        int p = 0;
        for (int i = 0; i < n - 1; i++) {
            if (abs(word[i] - word[i + 1]) > 2) {
                segments.emplace_back(p, i + 1);
                p = i + 1;
            }
        }
        segments.emplace_back(p, n);

        int res = 0;
        array<int, A> used;
        used.fill(-1);
        int idx = 0;
        for (const auto& [l, r] : segments) {
            for (int i = l; i < r; i++, idx++) {
                if (idx > 0) {
                    p = ord(word[idx - 1]);
                    pos[p].pop_back();
                }
                int ptr = i - 1;
                for (int a = 0; a < A; a++) {
                    int loc = n;
                    for (int b = 0; b < A; b++) if (!pos[b].empty() && used[b] != i) {
                        loc = min(loc, pos[b].back());
                    }
                    if (loc == n || loc > ptr + 1) {
                        break;
                    }
                    int b = ord(word[loc]);
                    int m = pos[b].size();
                    if (m < k) {
                        break;
                    }
                    int t = pos[b][m - k];
                    if (t >= r) {
                        break;
                    }
                    ptr = max(ptr, t);
                    used[b] = i;
                    int tot = ptr - i + 1;
                    if (tot % k == 0) {
                        res += (tot / k == (a + 1));
                    }
                }
            }
        }

        return res;
    }
};

// ~ JustJie
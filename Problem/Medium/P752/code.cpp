/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.21.2024 20:03:39
*********************************************/

using i64 = long long;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> gone(deadends.begin(), deadends.end());

        auto get = [&](char c) {
            vector<char> nxt;
            if (c == '0') {
                nxt.push_back('9');
            } else {
                nxt.push_back(c - 1);
            }
            if (c == '9') {
                nxt.push_back('0');
            } else {
                nxt.push_back(c + 1);
            }
            return nxt;
        };
        auto issoke = [&](const string& cur) {
            return !gone.contains(cur);
        };

        queue<string> q;
        auto add = [&](const string& cur) {
            if (issoke(cur)) {
                q.push(cur);
                gone.insert(cur);
            }
        };

        add("0000");
        for (int l = 0; !q.empty(); l++) {
            int Q = q.size();
            while (Q--) {
                auto cur = q.front();
                q.pop();

                if (cur == target) {
                    return l;
                }

                for (int d = 0; d < 4; d++) {
                    char p = cur[d];
                    for (auto c : get(cur[d])) {
                        cur[d] = c;
                        add(cur);
                    }
                    cur[d] = p;
                }
            }
        }

        return -1;
    }
};

// ~ JustJie
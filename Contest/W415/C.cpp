/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.14.2024 22:52:28
*********************************************/

using i64 = long long;

template<int SIZE = 26, char MIN_CHAR = 'a'>
struct Trie {
    struct Info {
        Info* nex[SIZE];
        bool poss(int pos) {
            return nex[pos] ? true : false;
        }
        Info* move(int pos) {
            assert(0 <= pos && pos < SIZE);
            return nex[pos];
        }
        Info* norm(int pos) {
            assert(0 <= pos && pos < SIZE);
            if (!poss(pos))
                nex[pos] = new Info();
            return nex[pos];
        }
    };

    Info* root = NULL;
    Trie() { root = new Info(); }
    constexpr int ord(char c) { return c - MIN_CHAR; }
    constexpr char chr(int o) { return o + MIN_CHAR; }

    void add(const string& word) {
        Info* ptr = root;
        for (char c : word) {
            int o = ord(c);
            ptr->norm(o);
            ptr = ptr->move(o);
        }
    }

    Info* get_root() {
        return root;
    }
};

constexpr int inf = int(1e9) + 5;

class Solution {
public:
    int minValidStrings(vector<string>& words, string t) {
        int n = t.size();

        Trie trie;
        for (const string& word : words) {
            trie.add(word);
        }

        vector<int> dp(n + 1, inf);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            auto ptr = trie.get_root();
            for (int j = i; j < n; j++) {
                int o = t[j] - 'a';
                if (ptr->poss(o)) {
                    if (dp[j + 1] + 1 < dp[i]) {
                        dp[i] = dp[j + 1] + 1;
                    }
                    ptr = ptr->move(o);
                } else {
                    break;
                }
            }
        }

        int ans = dp[0];
        if (ans == inf) {
            return -1;
        }
        return ans;
    }
};

// ~ JustJie
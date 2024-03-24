/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.24.2024 00:55:04
*********************************************/

using i64 = long long;


constexpr int inf = 1e9 + 5;

template <int A>
struct Trie {
    struct Info {
        Info* nex[A];
        int size = inf;
        int ans = -1;
        void update(int sz, int idx) {
            if (size > sz) {
                size = sz;
                ans = idx;
            }
        }
        Info* move(int pos) {
            assert(0 <= pos && pos < A);
            return nex[pos];
        }
        Info* norm(int pos) {
            assert(0 <= pos && pos < A);
            if (!nex[pos]) {
                nex[pos] = new Info();
            }
            return nex[pos];
        }
    };

    Info* root = NULL;
    Trie() { root = new Info(); }
    constexpr int ord(char c) { return c - 'a'; }

    void add(const string& word, int idx) {
        int m = word.size();

        Info* ptr = root;
        ptr->update(m, idx);
        for (char c : word) {
            int o = ord(c);
            ptr = ptr->norm(o);
            ptr->update(m, idx);
        }
    }

    int query(const string& query_word) {
        Info* ptr = root;
        for (char c : query_word) {
            int o = ord(c);
            if (!ptr->nex[o]) {
                break;
            }
            ptr = ptr->move(o);
        }
        return ptr->ans;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& words, vector<string>& queries) {
        int n = words.size(), Q = queries.size();

        Trie<26> t;
        for (int i = 0; i < n; i++) {
            reverse(words[i].begin(), words[i].end());
            t.add(words[i], i);
        }

        vector<int> ans(Q);
        for (int q = 0; q < Q; q++) {
            reverse(queries[q].begin(), queries[q].end());
            ans[q] = t.query(queries[q]);
        }

        return ans;
    }
};

// ~ JustJie
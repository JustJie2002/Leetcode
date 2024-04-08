/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.26.2024 22:55:23
*********************************************/

using i64 = long long;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

template <int SIZE = 26, char MIN_CHAR = 'a'>
struct Trie {
    struct Info {
        Info* nex[SIZE];
        int is_word = false;
        void update() {
            is_word = true;
        }
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
    Trie() { root = new Info(); root->is_word = true; }
    constexpr int ord(char c) { return c - MIN_CHAR; }
    constexpr char chr(int o) { return o + MIN_CHAR; }

    void add(const string& word) {
        Info* ptr = root;
        for (char c : word) {
            int o = ord(c);
            ptr = ptr->norm(o);
        }
        ptr->update();
    }

    string query() {
        string ans;
        string word;
        y_combinator([&](auto&& dfs, Info* node) -> void {
            int n = ans.length(), m = word.length();

            if (!node->is_word) {
                return;
            }

            if (m > n) {
                ans = word;
            } else if (m == n) {
                ans = min(ans, word);
            }

            for (int a = 0; a < SIZE; a++) {
                if (node->poss(a)) {
                    word += chr(a);
                    dfs(node->move(a));
                    word.pop_back();
                }
            }
        })(root);
        return ans;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie t;
        for (const auto& word : words) {
            t.add(word);
        }
        return t.query();
    }
};

// ~ JustJie
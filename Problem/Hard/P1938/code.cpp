/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.01.2024 21:30:24
*********************************************/

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

using i64 = long long;

constexpr int B = 18;

struct BTrie {
    struct Node {
        Node* nei[2];
        int cnt;
    };
    Node* root = NULL;

    BTrie() {
        root = new Node();
    }

    void add(int v) {
        Node* node = root;
        for (int i = B - 1; i >= 0; i--) {
            int o = (v >> i) & 1;
            if (!node->nei[o]) {
                node->nei[o] = new Node();
            }
            node = node->nei[o];
            node->cnt++;
        }
    }

    void rem(int v) {
        Node* node = root;
        for (int i = B - 1; i >= 0; i--) {
            int o = (v >> i) & 1;
            assert(node->nei[o]);
            node = node->nei[o];
            node->cnt--;
        }
    }

    int search(int v) {
        Node* node = root;
        int res = 0;
        for (int i = B - 1; i >= 0; i--) {
            int o = (v >> i) & 1;
            int w = o ^ 1;
            if (node->nei[w] && node->nei[w]->cnt) {
                res |= (1 << i);
                node = node->nei[w];
            } else if (node->nei[o] && node->nei[o]->cnt) {
                node = node->nei[o];
            } else {
                break;
            }
        }
        return res;
    }
};

using Query = pair<int, int>;

class Solution {
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n = parents.size();

        vector<vector<int>> adj(n);
        int root;
        for (int i = 0; i < n; i++) {
            if (parents[i] == -1) {
                root = i;
            } else {
                adj[parents[i]].push_back(i);
            }
        }

        int q = queries.size();
        vector<vector<Query>> query_set(n);
        for (int qi = 0; qi < q; qi++) {
            const auto& query = queries[qi];
            query_set[query[0]].emplace_back(qi, query[1]);
        }

        BTrie t;
        vector<int> ans(q);
        y_combinator([&](auto&& dfs, int cur) -> void {
            t.add(cur);
            for (const auto& [qi, v] : query_set[cur]) {
                ans[qi] = t.search(v);
            }
            for (int nei : adj[cur]) {
                dfs(nei);
            }
            t.rem(cur);
        })(root);

        return ans;
    }
};

// ~ JustJie
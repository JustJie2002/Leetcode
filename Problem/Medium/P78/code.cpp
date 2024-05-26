/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.19.2024 11:56:42
*********************************************/

template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

using i64 = long long;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        int n = a.size();

        vector<vector<int>> ans;
        ans.push_back({});
        for (int x : a) {
            auto nans = ans;
            for (auto&& res : ans) {
                res.push_back(x);
                nans.push_back(res);
            }
            ans.swap(nans); // if we want more space then we can do ans = std::move(nans)
        }

        return ans;
    }
};

// ~ JustJie
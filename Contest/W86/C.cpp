/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.01.2024 21:46:50
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

class Solution {
public:
    vector<int> splitIntoFibonacci(string s) {
        int n = s.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                
            }
        }

        // suppose s[:i] to s[i:j] and we can simulate
    }
};

// ~ JustJie
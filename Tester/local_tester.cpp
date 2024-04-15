/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.07.2024 22:52:12
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Need Internship"
#endif

using i64 = long long;

class Solution {
public:
    string getSmallestString(string s, int k) {

        auto ord = [&](char c) {
            return c - 'a';
        };

        auto dis = [&](char from, char to) {
            int a = ord(from);
            int b = ord(to);
            assert(a >= b);
            return min(a - b, b + 26 - a);
        };

        string t;
        for (char from : s) {
            for (char to = 'a'; to <= from; to++) {
                auto d = dis(from, to);
                if (d <= k) {
                    t += to;
                    k -= d;
                    break;
                }
            }
        }

        return t;
    }
};

int main() {
    Solution obj;
    assert(obj.getSmallestString("zbbz", 3) == "aaaz");
    assert(obj.getSmallestString("xaxcd", 4) == "aawcd");
    assert(obj.getSmallestString("lol", 0) == "lol");
    puts("BAD");
}

// ~ Just Jie
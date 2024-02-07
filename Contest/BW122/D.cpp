/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.20.2024 12:47:02
*********************************************/

using i64 = long long;

constexpr i64 inf = 1e15 + 10;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

template <typename T> struct SortedList {
    ordered_set<pair<T, int>> ost;
    map<T, int> freq;

    void add(T val) { ost.insert(make_pair(val, ++freq[val])); }
    void remove(T val) { ost.erase(make_pair(val, freq[val]--)); }
    int index(T val) { return ost.order_of_key(make_pair(val, -1)); }
    T operator[] (int i) const { return ost.find_by_order(i)->first; }

    T lower_bound(T val) {
        auto it = ost.lower_bound(make_pair(val, -1));
        return it == ost.end() ? ost.size() : ost.order_of_key(*it);
    }

    T upper_bound(T val) {
        auto it = ost.lower_bound(make_pair(val, 1000000000));
        return it == ost.end() ? ost.size() : ost.order_of_key(*it);
    }

    int size() { return ost.size(); }
    bool empty() { return ost.empty(); }
};

class Solution {
public:
    i64 minimumCost(vector<int>& a, int k, int dis) {
        int n = a.size();
        SortedList<int> sl;
        i64 res = 0;
        i64 ans = inf;

        auto Del = [&](int x) -> void {
            int idx = sl.index(x);
            sl.remove(x);
            if (idx < k - 1) {
                res -= x;
                if (sl.size() >= k - 1) {
                    res += sl[k - 2];
                }
            }
        };

        auto Ins = [&](int x) -> void {
            sl.add(x);
            int idx = sl.index(x);
            if (idx < k - 1) {
                res += x;
                if (sl.size() > k - 1) {
                    res -= sl[k - 1];
                }
            }
        };

        for (int i = 1, j = 1; i < n - k + 2; i++) {
            while (j < n && j - i <= dis) {
                Ins(a[j]);
                j++;
            }
            ans = min(ans, res);
            Del(a[i]);
        }

        return ans + a[0];
    }
};

// ~ JustJie
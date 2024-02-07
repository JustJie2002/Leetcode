/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.03.2024 14:02:23
*********************************************/

using i64 = long long;

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
    i64 maximumSubarraySum(vector<int>& a, int k) {
        SortedList<int> sl;
        i64 ans = 0;
        for (int x : a) {
            int L = sl.lower_bound(x - k);
            int R = sl.upper_bound(x + k);
            ans += R - L;
            sl.add(x); 
        }
        return ans;
    }
};

// ~ JustJie
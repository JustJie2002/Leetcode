/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.17.2024 23:06:24
*********************************************/

using i64 = long long;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

template<typename T>
struct SortedList {
    ordered_set<pair<T, int>> ost;
    map<T, int> freq;

    void add(T val) { ost.insert(make_pair(val, ++freq[val])); }
    void remove(T val) { ost.erase(make_pair(val, freq[val]--)); }
    int index(T val) { return ost.order_of_key(make_pair(val, -1)); }
    T operator[] (int i) const { return ost.find_by_order(i)->first; }

    int lower_bound(T val) {
        auto it = ost.lower_bound(make_pair(val, -1));
        return it == ost.end() ? ost.size() : ost.order_of_key(*it);
    }
    int upper_bound(T val) {
        auto it = ost.lower_bound(make_pair(val, 1000000000));
        return it == ost.end() ? ost.size() : ost.order_of_key(*it);
    }

    int size() { return ost.size(); }
    bool empty() { return ost.empty(); }
};

class Solution {
public:
    i64 numberOfPairs(vector<int>& a, vector<int>& b, int diff) {
        int n = a.size();

        SortedList<int> sl;
        i64 ans = 0;
        for (int i = 0; i < n; i++) {
            int d = a[i] - b[i];
            ans += sl.upper_bound(d + diff);
            sl.add(d);
        }
        return ans;
    }
};

// ~ JustJie
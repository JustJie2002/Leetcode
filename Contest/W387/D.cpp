/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.02.2024 21:41:49
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
    vector<int> resultArray(vector<int>& a) {
        int n = a.size();

        SortedList<int> sl1, sl2;
        vector<int> a1, a2;
        a1.push_back(a[0]);
        a2.push_back(a[1]);
        sl1.add(a[0]);
        sl2.add(a[1]);
        for (int i = 2; i < n; i++) {
            int x = a[i];
            int gc1 = sl1.size() - sl1.upper_bound(x);
            int gc2 = sl2.size() - sl2.upper_bound(x);
            if (gc1 > gc2) {
                a1.push_back(a[i]);
                sl1.add(a[i]);
            } else if (gc2 > gc1) {
                a2.push_back(a[i]);
                sl2.add(a[i]);
            } else {
                if (sl1.size() <= sl2.size()) {
                    a1.push_back(a[i]);
                    sl1.add(a[i]);
                } else {
                    a2.push_back(a[i]);
                    sl2.add(a[i]);
                }
            }
        }

        for (int x : a2) {
            a1.push_back(x);
        }

        return a1;
    }
};

// ~ JustJie
/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 12.23.2023 09:30:33
*********************************************/

using i64 = long long;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

template <typename T> struct SortedList {
    ordered_set<pair<T, int>> ost;
    map<T, int> freq;

    void add(T val) {
        ost.insert(make_pair(val, ++freq[val]));
    }
    
    void erase(T val) {
        ost.erase(make_pair(val, freq[val]--));
    }

    int order_of_key(T val) {
        return ost.order_of_key(make_pair(val, -1));
    }
    
    T find_by_order(T val) {
        return ost.find_by_order(val)->first;
    }

    T lower_bound(T val) {
        auto it = ost.lower_bound(make_pair(val, -1));
        return it == ost.end() ? ost.size() : ost.order_of_key(*it);
    }

    T upper_bound(T val) {
        auto it = ost.lower_bound(make_pair(val, 1000000000));
        return it == ost.end() ? ost.size() : ost.order_of_key(*it);
    }

    int size() {
        return ost.size();
    }

    bool empty() {
        return ost.empty();
    }
};

class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& a) {
        int n = a.size();

        vector<bool> pre(n), suf(n);
        pre[0] = true;
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] && (a[i] > a[i - 1]);
        }
        suf[n - 1] = true;
        for (int i = n - 2; ~i; i--) {
            suf[i] = suf[i + 1] && (a[i] < a[i + 1]);
        }

        SortedList<int> sl;
        i64 res = 1;
        for (int i = 1; i < n; i++) {
            if (suf[i]) {
                res += sl.lower_bound(a[i]) + 1;
            }
            if (pre[i - 1]) {
                sl.add(a[i - 1]);
            }
        }
        res += accumulate(pre.begin(), pre.end(), 0) - pre[n - 1];

        return res;
    }
};

// ~ JustJie
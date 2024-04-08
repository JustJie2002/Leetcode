/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.27.2024 17:05:28
*********************************************/

using i64 = long long;
using Segment = array<int, 2>;

constexpr int inf = 1e9 + 5;

class RangeModule {
public:
    set<Segment> seg;
    RangeModule() { seg.clear(); }
    
    void addRange(int left, int right) {
        Segment start = {left, inf};
        auto it = seg.upper_bound(start);
        int s = left, e = right - 1;
        if (it != seg.begin()) {
            auto [l, r] = *prev(it);
            if (left <= r + 1) {
                s = min(s, l);
                e = max(e, r);
                seg.erase(prev(it));
            }
        }
        while (it != seg.end()) {
            auto [l, r] = *it;
            auto nex = next(it);
            if (l > e + 1) {
                break;
            }
            seg.erase(it);
            it = nex;
            s = min(s, l);
            e = max(e, r);
        }
        seg.insert({s, e});
    }
    
    bool queryRange(int left, int right) {
        Segment segment = {left, inf};
        auto it = seg.upper_bound(segment);
        if (it != seg.begin()) {
            auto [l, r] = *prev(it);
            if (r >= right - 1) {
                return true;
            }
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        Segment start = {left, inf};
        auto it = seg.upper_bound(start);
        if (it != seg.begin()) {
            auto [l, r] = *prev(it);
            if (r >= left) {
                seg.erase(prev(it));
                int new_r = left - 1;
                if (l <= new_r) {
                    seg.insert({l, new_r});
                }
                if (r > right - 1) {
                    seg.insert({right, r});
                }
            }
        }
        while (it != seg.end()) {
            auto [l, r] = *it;
            if (l > right - 1) {
                break;
            }
            auto nex = next(it);
            seg.erase(it);
            it = nex;
            if (r >= right) {
                seg.insert({right, r});
                break;
            }
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */

// ~ JustJie
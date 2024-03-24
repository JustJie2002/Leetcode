/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.20.2024 22:19:02
*********************************************/

using i64 = long long;
using Segment = pair<int, int>;

class Allocator {
public:
    set<Segment> seg;
    unordered_map<int, vector<Segment>> log;
    Allocator(int n) {
        seg.insert({0, n - 1});
    }

    int allocate(int size, int mID) {
        set<Segment>::iterator it;
        for (it = seg.begin(); it != seg.end(); it++) {
            const auto& [l, r] = *it;
            if (r - l + 1 >= size) {
                break;
            }
        }

        if (it == seg.end()) {
            return -1;
        }

        auto [l, r] = *it;
        seg.erase(it);
        log[mID].push_back({l, l + size - 1});
        Segment new_segment = {l + size, r};
        if (l + size <= r) {
            seg.insert(new_segment);
        }

        return l;
    }
    
    int free(int mID) {
        int mem_freed = 0;
        for (auto& [l, r] : log[mID]) {
            mem_freed += r - l + 1;
            auto it = seg.lower_bound({l, l});
            if (it != seg.end()) {
                if (it->first == r + 1) {
                    r = it->second;
                    seg.erase(it);
                }
            }
            if (it != seg.begin()) {
                it = prev(it);
                if (it->second == l - 1) {
                    l = it->first;
                    seg.erase(it);
                }
            }
            seg.insert({l, r});
        }
        log.erase(mID);
        return mem_freed;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */

// ~ JustJie
/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.07.2024 21:46:47
*********************************************/

using i64 = long long;

class NumberContainers {
public:
    unordered_map<int, set<int>> mp;
    unordered_map<int, int> loc;
    NumberContainers() {}
    
    void change(int id, int x) {
        if (loc.contains(id)) {
            mp[loc[id]].erase(id);
        }
        mp[x].insert(id);
        loc[id] = x;
    }
    
    int find(int x) {
        if (!mp[x].empty()) {
            return *mp[x].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

// ~ JustJie
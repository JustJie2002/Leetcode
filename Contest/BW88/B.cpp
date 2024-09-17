/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 06.17.2024 23:15:34
*********************************************/

using i64 = long long;

class LUPrefix {
public:
    set<int> s;
    LUPrefix(int n) {
        for (int i = 1; i <= n + 1; i++) {
            s.insert(i);
        }
    }
    
    void upload(int x) {
        s.erase(x);
    }
    
    int longest() {
        return *s.begin() - 1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */

// ~ JustJie
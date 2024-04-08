/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.03.2024 22:09:17
*********************************************/

using i64 = long long;

class Solution {
public:
    bool canArrange(vector<int>& a, int k) {
        multiset<int> s;

        for (int x : a) {
            int m = (x % k + k) % k;
            int w = (k - m) % k;
            if (s.contains(w)) {
                s.erase(s.find(w));
            } else {
                s.insert(m);
            }
        }

        return s.size() == 0;
    }
};

// ~ JustJie
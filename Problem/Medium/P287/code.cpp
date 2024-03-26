/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.24.2024 19:49:55
*********************************************/

using i64 = long long;

constexpr int LIM = 2e5 + 1;

int mark[LIM];
int id = 0;

class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int n = a.size();
        id++;

        for (int x : a) {
            if (mark[x] == id) {
                return x;
            }
            mark[x] = id;
        }

        assert(0);
    }
};

// ~ JustJie
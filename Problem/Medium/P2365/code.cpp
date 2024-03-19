/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.18.2024 22:19:52
*********************************************/

using i64 = long long;

class Solution {
public:
    i64 taskSchedulerII(vector<int>& tasks, int t) {
        unordered_map<int, i64> pre;
        i64 time = 0;
        for (int x : tasks) {
            if (pre.contains(x)) {
                time = max(pre[x] + t + 1, time);
            }
            pre[x] = time++;
        }
        return time;
    }
};

// ~ JustJie
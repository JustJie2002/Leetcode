/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.18.2024 22:04:10
*********************************************/

using i64 = long long;

constexpr int A = 26;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int t) {
        int m = tasks.size();
        t++;

        array<int, A> freq {};
        for (char c : tasks) {
            freq[c - 'A']++;
        }

        priority_queue<int> pq;
        for (int a = 0; a < A; a++) {
            if (freq[a]) {
                pq.push(freq[a]);
            }
        }

        int cur_time = 0;
        while (!pq.empty()) {
            vector<int> left;
            int sz = pq.size();
            int used = 0;
            for (int i = 0; i < min(sz, t); i++) {
                auto cnt = pq.top();
                pq.pop();
                cnt--;
                used++;
                if (cnt) {
                    left.push_back(cnt);
                }
            }
            for (int x : left) {
                pq.push(x);
            }
            if (pq.empty()) {
                cur_time += used;
            } else {
                cur_time += t;
            }
        }

        return cur_time;
    }
};

// ~ JustJie
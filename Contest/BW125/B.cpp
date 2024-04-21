/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.02.2024 09:49:21
*********************************************/

using i64 = long long;

#define dequeue(pq)     pq.top(); pq.pop()

class Solution {
public:
    int minOperations(vector<int>& a, int k) {
        priority_queue<i64, vector<i64>, greater<i64>> pq(a.begin(), a.end());
        
        int ops = 0;
        while (!pq.empty()) {
            i64 u = dequeue(pq);
            if (u >= k) break;
            i64 v = dequeue(pq);
            pq.push(u * 2 + v);
            ops++;
        }

        return ops;
    }
};

// ~ JustJie
/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.10.2024 10:10:13
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& a) {
        int n = a.size();

        sort(a.begin(), a.end());

        queue<int> q;
        q.push(n - 1);
        for (int i = 0; i < n - 1; i++) {
            q.push(i);
        }

        auto dequeue = [&]() {
            int x = q.front();
            q.pop();
            return x;
        };

        int order = 0;
        vector<int> ans(n);
        do {
            int cur = dequeue();
            q.push(cur);
            cur = dequeue();
            ans[cur] = a[order++];
        } while (!q.empty());

        return ans;
    }
};

// ~ JustJie
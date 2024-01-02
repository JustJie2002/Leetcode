/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.01.2024 20:16:39
*********************************************/

using i64 = long long;

using Pair = pair<int, int>;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& a, vector<int>& b) {
        int n = a.size();

        vector<int> res(k);
        set<int> good;
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        for (int i = 0; i < k; i++) {
            good.insert(i);
        }

        auto norm = [&](int t) -> void {
            while (!pq.empty() && pq.top().first <= t) {
                good.insert(pq.top().second);
                pq.pop();
            }
        };

        auto get = [&](int id) -> int {
            if (good.empty()) {
                return -1;
            }
            auto it = good.lower_bound(id);
            return (it == good.end() ? *good.begin() : *it);
        };

        auto assign = [&](int id, int t) -> void {
            res[id]++;
            good.erase(id);
            pq.emplace(t, id);
        };

        for (int i = 0; i < n; i++) {
            int s = i % k;
            int st = a[i], dur = b[i];
            norm(st);
            int id = get(s);
            if (id != -1) {
                assign(id, st + dur);
            }
        }

        int most = *max_element(res.begin(), res.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (res[i] == most) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

// ~ JustJie
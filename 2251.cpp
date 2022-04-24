constexpr int INF = 1E9 + 100;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int, int> diff;

        auto update = [&](int l, int r) -> void {
            diff[l]++;
            diff[r + 1]--;
        };

        for (auto& w : flowers) {
            int l = w[0], r = w[1];
            update(l, r);
        }

        map<int, int> queries;

        int prev = -1;
        for (auto& [idx, c] : diff) {
            if (prev == -1) {
                queries[idx] = c;
            } else {
                queries[idx] = c + queries[prev];
            }
            prev = idx;
        }

        queries[INF] = queries[prev];

        int m = persons.size();
        vector<int> ans(m);

        for (int i = 0; i < m; i++) {
            auto it = queries.upper_bound(persons[i]); it--;
            ans[i] = it -> second;
        }

        return ans;
    }
};
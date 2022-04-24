class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> store(101);

        for (auto& rec : rectangles) {
            int w = rec[0], h = rec[1];
            store[h].push_back(w);
        }

        for (int i = 0; i < 101; i++) {
            sort(store[i].begin(), store[i].end());
        }

        int m = points.size();
        vector<int> ans(m);
        for (int k = 0; k < m; k++) {
            int w = points[k][0], h = points[k][1];

            int res = 0;

            for (int i = h; i <= 100; i++) {
                auto it = lower_bound(store[i].begin(), store[i].end(), w);
                int idx = store[i].end() - it;
                res += idx;
            }

            ans[k] = res;
        }

        return ans;
    }
};
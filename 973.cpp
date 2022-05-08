class Solution {
public:
    int dist(const vector<int>& w) {
        return w[0] * w[0] + w[1] * w[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [&](const vector<int>& a, const vector<int>& b){
            return dist(a) < dist(b);
        });
        vector<vector<int>> w;
        for (int i = 0; i < k; i++)
            w.push_back(points[i]);
        return w;
    }
};
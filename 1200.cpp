class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        unordered_map<int, vector<vector<int>>> mp;
        int mx = 1e9;
        for (int i = 0; i < n - 1; i++) {
            int diff = arr[i + 1] - arr[i];
            mp[diff].push_back({arr[i], arr[i + 1]});
            mx = min(mx, diff);
        }
        return mp[mx];
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnter;
        for (const auto& x : nums)
            ++cnter[x];
        vector<pair<int,int>> order;
        for (const auto& [x, cnt] : cnter)
            order.emplace_back(cnt, x);
        sort(order.rbegin(), order.rend());
        vector<int> ans;
        for (int i = 0; i < k; i++)
            ans.push_back(order[i].second);
        return ans;
    }
};
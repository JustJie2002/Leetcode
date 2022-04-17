class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> tot;
        for (int i : tasks) tot[i]++;
        int ans = 0;
        for (auto& [_, c] : tot) {
            int three = c / 3;
            if (three == 0) {
                if (c == 1) return -1;
                ans += 1;
            } else {
                c -= three * 3;
                if (c == 1) {
                    three -= 1;
                    c += 3;
                    ans += (2 + three);
                } else {
                    if (c == 2) three += 1;
                    ans += three;
                }
            }
        }
        return ans;
    }
};
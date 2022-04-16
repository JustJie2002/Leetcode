class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> res;

        sort(a.begin(), a.end());

        int n = a.size();

        for (int i = 0; i < n; i++) {
            int target = -a[i];
            int front = i + 1;
            int back = n - 1;

            if (target < 0) break;

            while (front < back) {
                int sum = a[front] + a[back];

                if (sum < target) 
                    front++;
                else if (sum > target) 
                    back--;
                else {
                    vector<int> triplet = {a[i], a[front], a[back]};
                    res.push_back(triplet);

                    while (front < back && a[front] == triplet[1]) front++;
                    while (front < back && a[back] == triplet[2]) back--;
                }
            }

            while (i + 1 < n && a[i + 1] == a[i]) i++;
        }

        return res;
    }
};
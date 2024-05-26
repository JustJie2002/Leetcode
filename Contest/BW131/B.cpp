/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 05.25.2024 12:24:13
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& a, vector<int>& queries, int x) {
        int n = a.size();

        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (a[i] == x) {
                pos.push_back(i);
            }
        }

        int Q = queries.size();
        vector<int> ans;
        ans.reserve(Q);
        for (int q : queries) {
            if (q > pos.size()) {
                ans.push_back(-1);
            } else {
                ans.push_back(pos[q - 1]);
            }
        }
        return ans;
    }
};

// ~ JustJie
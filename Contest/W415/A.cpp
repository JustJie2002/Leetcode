/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.14.2024 22:46:19
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& a) {
        int n = a.size();

        set<int> s;
        vector<int> ans;
        for (int x : a) {
            if (s.contains(x)) {
                ans.push_back(x);
            }
            s.insert(x);
        }

        return ans;
    }
};

// ~ JustJie
/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.15.2024 22:14:05
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();

        deque<int> dq;
        for (int i = 0; i < n + 1; i++) {
            dq.push_back(i);
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'I') {
                ans.push_back(dq.front());
                dq.pop_front();
            } else {
                ans.push_back(dq.back());
                dq.pop_back();
            }
        }
        ans.push_back(dq.back());
        
        return ans;
    }
};

// ~ JustJie
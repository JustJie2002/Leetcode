/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 04.05.2024 21:05:30
*********************************************/

using i64 = long long;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();

        stack<int> stk;
        vector<bool> add(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                if (!stk.empty()) {
                    add[stk.top()] = add[i] = true;
                    stk.pop();
                }
            } else {
                add[i] = true;
            }
        }

        string t;
        for (int i = 0; i < n; i++) {
            if (add[i]) {
                t += s[i];
            }
        }
        return t;
    }
};

// ~ JustJie
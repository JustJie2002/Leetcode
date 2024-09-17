/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 08.16.2024 20:33:08
*********************************************/

using i64 = long long;

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();

        stack<char> stk;
        int ans = 0;
        for (auto direction : directions) {
            if (direction == 'L') {
                if (!stk.empty() && stk.top() == 'R') {
                    ans += 2;
                    stk.pop();
                    direction = 'S';
                } else if (!stk.empty() && stk.top() == 'S') {
                    ans++;
                }
            } else if (direction == 'R') {
                stk.push(direction);
            }
            if (direction == 'S') {
                while (!stk.empty() && stk.top() == 'R') {
                    stk.pop();
                    ans++;
                }
                stk.push(direction);
            }
        }

        return ans;
    }
};

// ~ JustJie
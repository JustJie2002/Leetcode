/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.24.2024 22:09:00
*********************************************/

using i64 = long long;

struct Point {
    int x, y;
};

struct Rec {
    Point bottomLeft, topRight;
};

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bot_left, vector<vector<int>>& top_right) {
        int n = bot_left.size();

        i64 ans = 0;
        auto work = [&](const Rec& rect1, const Rec& rect2) -> void {
            Rec intersection;
    
            // Check for intersection
            if (rect1.bottomLeft.x > rect2.topRight.x || rect2.bottomLeft.x > rect1.topRight.x || rect1.bottomLeft.y > rect2.topRight.y || rect2.bottomLeft.y > rect1.topRight.y) {
                // No intersection
            } else {
                // Intersection exists, find coordinates
                intersection.bottomLeft.x = max(rect1.bottomLeft.x, rect2.bottomLeft.x);
                intersection.bottomLeft.y = max(rect1.bottomLeft.y, rect2.bottomLeft.y);
                intersection.topRight.x = min(rect1.topRight.x, rect2.topRight.x);
                intersection.topRight.y = min(rect1.topRight.y, rect2.topRight.y);
                int x_dif = abs(intersection.bottomLeft.x - intersection.topRight.x);
                int y_dif = abs(intersection.bottomLeft.y - intersection.topRight.y);
                int side = min(x_dif, y_dif);
                ans = max(ans, 1LL * side * side);
            }
        };
        
        vector<Rec> r(n);
        for (int i = 0; i < n; i++) {
            r[i].bottomLeft = {bot_left[i][0], bot_left[i][1]};
            r[i].topRight = {top_right[i][0], top_right[i][1]};
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                work(r[i], r[j]);
            }
        }

        return ans;
    }
};

// ~ JustJie
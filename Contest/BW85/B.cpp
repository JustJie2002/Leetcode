/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.01.2024 10:07:25
*********************************************/

using i64 = long long;

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.size();
        
        int t = 0;
        bool running = true;
        while (running) {
            running = false;
            for (int i = 0; i < n - 1; i++) {
                if (s[i] == '0' && s[i + 1] == '1') {
                    swap(s[i], s[i + 1]);
                    i++;
                    running = true;
                }
            }
            t++;
        }
        return t - 1;
    }
};

// ~ JustJie
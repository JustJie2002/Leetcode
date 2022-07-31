/* stuff you should look for 
    * check for int overflow
    * check for time complexity (make sure not to TLE)
    * special case (n = 1)
    * make sure to initialize everything (array)
    * don't be lazy, write out your thought and code it out
*/

using int64 = long long;

class Solution {
private:
    int N;
    const int cap = 17;
    string num;
    vector<int64> add;

    bool check() {
        int M = add.size();
        if (M < 3) return false;
        int64 a = add[0];
        int64 b = add[1];
        for (int i = 2; i < M; i++) {
            int64 c = add[i];
            if (a + b != c)
                return false;
            a = b;
            b = c;
        }
        return true;
    }

    bool dfs(int i, int k, string cur) {
        if (i == N) {
            assert(cur.empty());
            return check();
        } 

        bool ok = false;

        k++;
        cur += num[i];

        // we can split
        add.push_back(stoll(cur));
        ok |= dfs(i + 1, 0, "");
        add.pop_back();

        if (ok)
            return true;

        // we can continue if the current length is shorter than cap
        if (k <= cap && i != N - 1 && cur != "0")
            ok |= dfs(i + 1, k, cur);

        return ok;
    }

public:
    bool isAdditiveNumber(string s) {
        num = s;
        N = s.size();
        return dfs(0, 0, "");
    }
};
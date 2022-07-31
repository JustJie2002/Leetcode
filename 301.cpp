/* stuff you should look for 
    * check for int overflow
    * check for time complexity (make sure not to TLE)
    * special case (n = 1)
    * make sure to initialize everything (array)
    * don't be lazy, write out your thought and code it out
*/

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int N = s.size();

        set<pair<string, int>> Q;
        Q.emplace("", 0);

        for (int i = 0; i < N; i++) {
            set<pair<string, int>> nQ;
            int score = s[i] == '(' ? 1 : -1;
            if (s[i] >= 'a' && s[i] <= 'z') score = 0;
            for (auto& q : Q) {
                if (q.second > (N - i)) continue;
                if (q.second + score >= 0)
                    nQ.emplace(q.first + s[i], q.second + score);
                nQ.insert(q);
            }
            Q.swap(nQ);
        }

        vector<string> bucket;

        map<int, vector<string>> m;

        for (auto& q : Q) if (q.second == 0)
            m[q.first.size()].push_back(q.first);

        return m.rbegin()->second;
    }
};
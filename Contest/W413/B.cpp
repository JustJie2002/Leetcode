/********************************************
 * author : Jie Chen (4th Year CS)
 * school : Rochester Institute of Technology
 * created: 09.06.2024 01:36:30
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int query_count = queries.size();

        vector<int> response(query_count, -1);
        multiset<int> distances;
        for (int q = 0; q < query_count; q++) {
            int x = queries[q][0];
            int y = queries[q][1];
            int dis = abs(x) + abs(y);
            distances.insert(dis);
            if (q + 1 > k) {
                distances.extract(*distances.rbegin());
            }
            if (q + 1 >= k) {
                response[q] = *distances.rbegin();
            }
        }

        return response;
    }
};

// ~ JustJie
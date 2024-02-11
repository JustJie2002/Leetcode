/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 02.10.2024 20:31:50
*********************************************/

using i64 = long long;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> reachable(n); // default set as false

        for (const auto& edge : edges) {
            int from = edge[0], to = edge[1];
            reachable[to] = true;
        }

        vector<int> has_to_start_with;
        for (int i = 0; i < n; i++) {
            if (!reachable[i]) { // since node i can not be reachable by any nodes
                has_to_start_with.push_back(i); // we have to start with it
            }
        }

        return has_to_start_with;
    }
};

// ~ JustJie
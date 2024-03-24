/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.20.2024 23:13:08
*********************************************/

using i64 = long long;

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        // add at most 2 edges
        vector<int> deg(n);
        vector<unordered_set<int>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            u--, v--;
            deg[u]++;
            deg[v]++;
            adj[u].insert(v);
            adj[v].insert(u);
        }

        vector<int> odd_deg;
        for (int i = 0; i < n; i++) {
            if (deg[i] & 1) {
                odd_deg.push_back(i);
            }
        }

        int m = odd_deg.size();

        if (m > 4 || m % 2 == 1) {
            return false;
        }

        if (m == 2) {
            int u = odd_deg[0];
            int v = odd_deg[1];
            for (int i = 0; i < n; i++) {
                if (u == i || v == i) {
                    continue;
                }
                if (!adj[u].contains(i) && !adj[v].contains(i)) {
                    return true;
                }
            }
            return !adj[u].contains(v);
        }

        sort(odd_deg.begin(), odd_deg.end());

        do {
            bool good = true;
            for (int i = 0; i < m; i += 2) {
                int u = odd_deg[i], v = odd_deg[i + 1];
                good &= !(adj[u].contains(v));
            }
            if (good) {
                return true;
            }
        } while (next_permutation(odd_deg.begin(), odd_deg.end()));
        return false;
    }
};

// ~ JustJie
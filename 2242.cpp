/**
 * 
 * Explanation:
 * - Since we only want a node sequence of length 4,
 *  we can just have 2 out of the 4 nodes being the edge from edges
 *  then we iterate through nodes that are connected to node 1 and 
 *  iterate through nodes that are connected to node 1
 * - In order to reduce the time here, we can sort all of the connected
 *  edges of a node by the score of each node
 * - Now we have iterate through the max(first 3, # of connected nodes) nodes of
 *  node 1 and node 2
 * - First 3 because we have to consider the follow scenario
 *      - It is possible that one of the highest score for node that
 *      is connected to node 1 is node 2
 *      - It is possible that one of the highest score for node 1 and node 2
 *      is the same node
 *      - Therefore, with everything consider, all we need to consider is take at most 3
 * 
 **/

class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();

        vector<vector<int>> adj(n);

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int ans = -1;

        for (int i = 0; i < n; i++) {
            sort(adj[i].begin(), adj[i].end(), [&](int x, int y){
                return scores[x] > scores[y];
            });
        }

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            for (int i = 0; i < 2 && i < adj[u].size(); i++) {
                if (adj[u][i] != v) {
                    for (int j = 0; j < 2 && j < adj[v].size(); j++) {
                        if (adj[v][j] != u) {
                            if (adj[v][j] != adj[u][i]) {
                                ans = max(ans, 
                                    scores[adj[u][i]] +
                                    scores[adj[v][j]] +
                                    scores[u] + scores[v]
                                );
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};
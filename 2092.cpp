using pii = pair<int, int>;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, vector<pii>> adj;
        adj[0].emplace_back(firstPerson, 0);
        for (auto& w : meetings) {
            int u = w[0], v = w[1], t = w[2];
            adj[t].emplace_back(v, u);
        }
        unordered_set<int> know;
        know.insert(0);
        know.insert(firstPerson);
        for (const auto& [_, edges] : adj) {
            unordered_set<int> que;

            unordered_map<int, vector<int>> nadj;

            for (const auto& edge : edges) {
                int u = edge.first, v = edge.second;
                nadj[u].push_back(v);
                nadj[v].push_back(u);

                if (know.count(u)) {
                    que.insert(v);
                    know.insert(v);
                }
                if (know.count(v)) {
                    que.insert(u);
                    know.insert(u);
                }
            }

            queue<int> q;

            for (int x : que) q.push(x);

            while (!q.empty()) {
                int cur = q.front(); q.pop();

                for (int nei : nadj[cur])
                    if (!know.count(nei)) {
                        know.insert(nei);
                        q.push(nei);
                    }
            }
        }
        return vector<int>(know.begin(), know.end());
    }
};
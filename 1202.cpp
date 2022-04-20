
struct UnionFind {
    int size;
    vector<int> parent;
    UnionFind(int _size) : size(_size) {
        parent.resize(size + 1);
        for (int i = 0; i <= size; i++)
            parent[i] = i;
    }

    int find(int x) {
        return (parent[x] == x ? x : parent[x] = find(parent[x]));
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x != y) {
            parent[y] = x;
            return 1;
        }
        return 0;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        UnionFind uf(n);
        for (const auto& e : pairs) {
            int u = e[0], v = e[1];
            uf.unite(u, v);
        }
        unordered_map<int, pair<vector<int>, vector<char>>> mp;
        for (int i = 0; i < n; i++) {
            int father = uf.find(i);
            mp[father].first.push_back(i);
            mp[father].second.push_back(s[i]);
        }
        for (auto& [_, a] : mp) {
            sort(a.first.begin(), a.first.end());
            sort(a.second.begin(), a.second.end());
            int m = a.first.size();
            for (int i = 0; i < m; i++) {
                int idx = a.first[i];
                s[idx] = a.second[i];
            }
        }
        return s;
    }
};
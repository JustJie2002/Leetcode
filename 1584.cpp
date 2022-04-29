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

constexpr int N = 1010;

struct E{
    int i, j, dist;
    E(int _i, int _j, int _dist): i(_i), j(_j), dist(_dist) {}
    E(): i(0), j(0), dist(0) {}

    bool operator < (const E& other) const {
        return dist < other.dist;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int N = points.size();
        vector<E> Es(N * N);
        int idx = 0;
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
                Es[++idx] = E(i, j, 
                    abs(points[i][0] - points[j][0]) +
                    abs(points[i][1] - points[j][1])
                );
        sort(Es.begin(), Es.end());
        UnionFind UF(N);
        int ans = 0;
        for (const E& e : Es) {
            if (UF.unite(e.i, e.j)) {
                ans += e.dist;
            }
        }
        return ans;
    }
};
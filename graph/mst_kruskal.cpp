// Kruskal's algorithm
//
// https://en.wikipedia.org/wiki/Kruskal%27s_algorithm
// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2
// https://leetcode.com/problems/min-cost-to-connect-all-points/
//
// Algorithm:
// Sort edges or use heap + DSU
//
// Limitations:
// - Both Prim and Kruskal work on negative edges
// - Kruskal can work on a disconnected graph to generate forest while Prim always generates connected graph.
// - Use Kruskal when the graph is sparse, small number of edges or edges are sorted or we can sort them in a linear time
//
// Complexity:
// - Sorting with O(ElogE) or O(ElogV) because E is at most V^2
// - DSU can perform E operations in O(E logV) - O(E * alpa(V)) ackermann
//
// Space Complexity: O(V + E)


class Solution
{
    int points_dist(const vector<vector<int>>& ps, int i, int j)
    {
        return abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1]);
    }

    int findSet(int i, vector<int> &p) {
        while (p[i] != i) {
            p[i] = p[p[i]];
            i = p[i];
        }
        return i;
    }

    bool setUnion(int i, int j, vector<int> &p, vector<int> &rank) {
        i = findSet(i, p);
        j = findSet(j, p);
        
        if (i == j) return false;
        
        if (rank[i] < rank[j]) swap(i, j);
        p[j] = i;
        if (rank[i] == rank[j]) ++rank[i];
        return true;
    }

public:
    // Heap + DSU
    //
    int minCostConnectPoints(vector<vector<int>>& ps) {
        int n = ps.size();

        vector<array<int, 3>> graph(n * n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                graph[i*n+j] = {points_dist(ps, i, j), i, j};
        
        vector<int> p(n), rank(n);
        iota(p.begin(), p.end(), 0);

        int res = 0, edges = 0;
        make_heap(graph.begin(), graph.end(), greater<array<int, 3>>());
        while (!graph.empty())
        {
            pop_heap(graph.begin(), graph.end(), greater<array<int, 3>>());
            auto [dist, i, j] = graph.back();
            graph.pop_back();
            
            if (setUnion(i, j, p, rank))
            {
                res += dist;
                edges += 1;
                if (edges == n-1) break;
            }
        }
        
        return res;
    }
};
// Prim's algorithm - use this by default
//
// In computer science, Prim's algorithm is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph.
// This means it finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized.
//
// https://en.wikipedia.org/wiki/Prim%27s_algorithm
// https://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/
// https://leetcode.com/problems/min-cost-to-connect-all-points/
//
// Algorithm:
// Keep distance and used vectors. Pick smallest v(any at start), check all the neighbours and
// add {-dist(v, u), vertex} to heap if smaller than dist[u] and unprocessed
//
// Limitations:
// - Both Prim and Kruskal work on negative edges
// - Kruskal can work on a disconnected graph to generate forest while Prim always generates connected graph.
// - Use Kruskal when the graph is sparse, small number of edges or edges are sorted or we can sort them in a linear time
//
// Complexity:
// - O((V+E)logV)=O(Elog V)
// - We may have multiple entries for same vertex as we do not (and we can not) make isMST[v] = true in if condition.
// - There will be at most O(E) vertices in priority queue and O(logE) = O(logV) because E is at most V^2
//
// Space Complexity: O(V + E)


class Solution {
    static int points_dist(const vector<vector<int>>& points, int i, int j)
    {
        return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> used(n, false);
        vector<int> dist(n, INT_MAX);
        
        priority_queue<pair<int, int>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        
        int res = 0, connected = 0;
        for (int connected = 0; connected < n; ++connected)
        {
            while (used[pq.top().second]) pq.pop();
            int v = pq.top().second; pq.pop();

            used[v] = true;
            res += dist[v];

            // can construct adjacency list and iterate over it
            //
            for (int u = 0; u < n; ++u)
            {
                if (used[u]) continue;
                
                int edge_dist = points_dist(points, v, u);
                if (edge_dist < dist[u])
                {
                    pq.push({-edge_dist, u});
                    dist[u] = edge_dist;
                }
            }
        }
        
        return res;
    }
};

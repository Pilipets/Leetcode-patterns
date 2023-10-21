// Prim's algorithm
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
    int minCostConnectPoints(vector<vector<int>>& ps) {
        int n = ps.size(), res = 0, i = 0, connected = 0;

        vector<int> min_d(n, INT_MAX - 1);
        while (++connected < n) {
            min_d[i] = INT_MAX;

            int min_j = i;
            for (int j = 0; j < n; ++j)
                if (min_d[j] != INT_MAX) {
                    min_d[j] = min(min_d[j], points_dist(ps, i, j));
                    min_j = min_d[j] < min_d[min_j] ? j : min_j;
                }

            res += min_d[min_j];
            i = min_j;
        }
        return res;
    }
};

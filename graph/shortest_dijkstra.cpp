// Dijkstra's algorithm
//
// Dijkstra's algorithm finds the shortest path from one vertex to all other vertices. It does so by repeatedly selecting
// the nearest unvisited vertex and calculating the distance to all the unvisited neighboring vertices.
//
// https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/
// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-set-in-stl/
// https://leetcode.com/problems/path-with-minimum-effort/
// https://www.geeksforgeeks.org/what-are-the-differences-between-bellman-fords-and-dijkstras-algorithms/
//
// Algorithm:
// It picks the unvisited vertex with the lowest distance calculates the distance through it to each unvisited neighbor and updates the neighbor's distance if smaller.
// Mark visited (set to red) when done with neighbors.
//
// Limitations:
// - Works with cycles but can't work on negative weights
// - Dynamic Programming approach in Bellman Ford’s algorithm and Greedy approach in Dijkstra’s algorithm.
// - Can't be easily implemented in distributed manner while Bellman Ford can
// - O(ElogV) for Dijkstra vs O(VE) belman ford
//
// Time complexity:
// - O((V+E)logV)=O(Elog V)
// - We may have multiple entries for same vertex as we do not (and we can not) make isMST[v] = true in if condition.
// - There will be at most O(E) vertices in priority queue and O(logE) = O(logV) because E is at most V^2
//
// Space complexity: O(V + E)


// pure dijkstra
//
vector<int> distances(n, INT_MAX);
distances[source] = 0;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
heap.push({0, source});

while (!heap.empty())
{
    auto [currDist, node] = heap.top();
    heap.pop();
    
    if (currDist > distances[node]) continue;
    
    for (auto &edge: graph[node])
    {
        auto [nei, weight] = edge;
        int dist = currDist + weight;
        
        if (dist < distances[nei])
        {
            distances[nei] = dist;
            heap.push({dist, nei});
        }
    }
}


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[0][0] = 0;

        priority_queue<array<int, 3>> pq;
        pq.push({0, 0, 0});
        
        int dirs[] = {-1, 0, 1, 0, -1};
        while (true)
        {
            auto cur = pq.top(); pq.pop();
            int i = cur[1], j = cur[2];
            // vertex is visited here
            if (-cur[0] > dp[i][j]) continue;

            if (i == n - 1 && j == m - 1) break;

            for (int k = 0; k < 4; ++k)
            {
                int x = i + dirs[k], y = j + dirs[k+1];
                    
                if (x >= 0 && y >= 0 && x < n && y < m)
                {
                    int diff = max(dp[i][j], abs(heights[x][y] - heights[i][j]));
                    if (diff < dp[x][y])
                    {
                        dp[x][y] = diff;
                        pq.push({-diff, x, y});
                    }
                }
            }
        }
        return dp.back().back();
    }
};
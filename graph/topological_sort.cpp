// Topological sort
//
// Two approaches are feasible: Khan's algorithm and DFS on Direct Acyclic Graph.
// USE Khan's algorithm as DFS is implemented with recursion.
// Both give O(V + E) time complexity and O(V) space.
//
// https://leetcode.com/problems/course-schedule/
// https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
// https://en.wikipedia.org/wiki/Topological_sorting
//
// Khan's Algorithm (USE THIS!!!):
// - Build adjacency list and find the indegree of each vertex
// - Select the vertices with indegree 0 and add it to the queue.
// - Take next vertex from queue and add it to the result.
// - Iterate over the neighbors of the vertex and decrement their indegree. If it becomes 0, add it to the queue.
// - Final check for cycle is to check for the number of vertices in the result.
//
// DFS algorithm:
// - Start dfs from each node and go deep until you find a visited node (cycle) or all the neighbors are visited.
// - Now add the node to the result.
// - Reverse the result to get the topological order.
// - So each node has three states: unvisited (go deep), visited (end of dfs), visiting (cycle).


// https://leetcode.com/problems/course-schedule/
//
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        for (auto prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }

        queue<int> q;
        // Push all the nodes with indegree zero in the queue.
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int nodesVisited = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            nodesVisited++;

            for (auto& neighbor : adj[node]) {
                // Delete the edge "node -> neighbor".
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return nodesVisited == numCourses;
    }
};
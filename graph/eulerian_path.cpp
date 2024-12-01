// Eulerian Path and Circuit(Cycle)
//
// An Eulerian path(trail) is a path that uses every edge of a graph exactly once.
// An Eulerian circuit is an Eulerian path that starts and ends on the same vertex.
// 
// Main algorithm to use is Hierholzer's algorithm. (https://cp-algorithms.com/graph/euler_path.html)
// Algorithm in simple terms: We find all simple cycles and combine them into one - this will be the Eulerian cycle.
// If the graph is such that the Eulerian path is not a cycle, then add the missing edge, find the Eulerian cycle, then remove the extra edge.
//
// Detailed algorithm (https://en.wikipedia.org/wiki/Eulerian_path):
// - Choose any starting vertex v, and follow a trail of edges from that vertex until returning to v.
//  It is not possible to get stuck at any vertex other than v, because the even degree of all vertices ensures that,
//  when the trail enters another vertex w there must be an unused edge leaving w. The tour formed in this way is a closed tour,
//  but may not cover all the vertices and edges of the initial graph.
// - As long as there exists a vertex u that belongs to the current tour but that has adjacent edges not part of the tour,
//  start another trail from u, following unused edges until returning to u, and join the tour formed in this way to the previous tour.
//  Since we assume the original graph is connected, repeating the previous step will exhaust all edges of the graph.
//
// Algorithm (https://cp-algorithms.com/graph/euler_path.html, https://www.geeksforgeeks.org/hierholzers-algorithm-directed-graph/):
// stack St;
// put start vertex in St;
// until St is empty
//   let V be the value at the top of St;
//   if degree(V) = 0, then
//     add V to the answer;
//     remove V from the top of St;
//   otherwise
//     find any edge coming out of V;
//     remove it from the graph;
//     put the second end of this edge in St;
//
// IMPORTANT NOTE: For the algorithm above one must take start node into account. If it's cycle, then start node is any node.
// If it's trail, find the one from criteria below or add edge to make it cycle and remove it after.
// 
// Alternative implementation from https://www.geeksforgeeks.org/hierholzers-algorithm-directed-graph/.
//
// Complexity:
// - Time Complexity : O(V + E), where V is the number of vertices and E is the number of edges in the graph.
//   Algorithm performs a depth-first search (DFS) and visits each vertex and each edge exactly once. Building adj list is O(E),
//   reversing the result is O(V).
// - Space complexity: O(V + E), as the algorithm uses a stack to store the current path and a list to store the final circuit.
//   The maximum size of the stack can be V + E for the adj list.
//
// Criteria to exist (https://en.wikipedia.org/wiki/Eulerian_path).
// - Eulerian cycle:
// 1. An undirected graph - if and only if every vertex has even degree.
// 2. A directed graph - if and only if every vertex has equal in degree and out degree
// - Eulerian path/trail:
// 1. An undirected graph - if and only if exactly zero or two vertices have odd degree
// 2. A directed graph - if and only if at most one vertex has (out-degree) − (in-degree) = 1,
// at most one vertex has (in-degree) − (out-degree) = 1, every other vertex has equal in-degree and out-degree.
// - FOR ALL ABOVE: all of its vertices with nonzero degree belong to a single connected component of the underlying graph.
//


// https://leetcode.com/problems/valid-arrangement-of-pairs/
// Eulerian path in a directed graph.
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs)
    {
        unordered_map<int, vector<int>> adj;
        int start = pairs[0][0];
        {
            unordered_map<int, int> degree;
            for (const auto& e : pairs)
            {
                adj[e[0]].push_back(e[1]);
                degree[e[1]] -= 1;
                degree[e[0]] += 1;
            }
            
            auto it = std::find_if(degree.begin(), degree.end(), [](const auto& v_out) {
                return v_out.second == 1;
            });
            if (it != degree.end())
                start = it->first;
        }
        
        vector<int> path;
        stack<int> st{{start}};
        while(!st.empty())
        {
            auto v = st.top();
            if (adj.count(v) == 0 or adj[v].empty())
            {
                path.push_back(v);
                st.pop();
            }
            else
            {
                auto u = adj[v].back();
                adj[v].pop_back();
                st.push(u);
            }
        }
        
        // std::copy(path.begin(), path.end(), std::ostream_iterator<int>(std::cout, " "));
        vector<vector<int>> res;
        for (int i = static_cast<int>(path.size()) - 1; i >= 1; --i)
        {
            res.push_back({path[i], path[i - 1]});
        }
        return res;
    }
};


// https://leetcode.com/problems/reconstruct-itinerary/
// Eulerian path in a directed graph.
//
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        for (auto &e : tickets)
            graph[e[0]].insert(e[1]);

        vector<string> res;
        stack<string> dfs{{"JFK"}};
        while (!dfs.empty())
        {
            const string& cur = dfs.top();
            if (graph.count(cur) && graph[cur].size())
            {
                auto v_it = graph[cur].begin();
                dfs.push(*v_it);
                graph[cur].erase(v_it);
            }
            else
            {
                dfs.pop();
                res.push_back(cur);
            }
        }

        return vector(res.rbegin(), res.rend());
    }
};
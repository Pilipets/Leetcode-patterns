//
// Rerooting - two dfs traversals.
// dfs1 takes results from childs to root, while dfs2 from root to childs.
//
// Task examples:
// - find number of nodes at event distances for each node 
// - number of leaves for each node
//
// https://www.geeksforgeeks.org/sum-of-length-of-paths-from-every-node-to-all-other-nodes-using-tree-rerooting-technique/
//


// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/
//
class Solution {
    vector<int> even, odd;

    vector<vector<int>> buildAdjacencyList(const vector<vector<int>>& edges)
    {
        vector<vector<int>> adj(edges.size() + 1);
        for (const auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        return adj;
    }

    void dfs1(const vector<vector<int>>& adj, vector<int>& odd, vector<int>& even)
    {
        int n = adj.size();
        vector<bool> visited(n);
        visited[0] = true;
        
        stack<pair<int, bool>> st;
        st.push({0, true});
        
        while (!st.empty())
        {
            auto [node, init] = st.top();
            
            if (init)
            {
                visited[node] = true;
                st.top().second = false;
                
                for (int child : adj[node])
                {
                    if (!visited[child])
                        st.push({child, true});
                }
            }
            else
            {
                st.pop();
                even[node] = 1;
                odd[node] = 0;

                for (int child : adj[node])
                {
                    // yes, we can go to parent here, but it's zero initialized, so fine.
                    //
                    assert(visited[child]);
                    even[node] += odd[child];
                    odd[node] += even[child];
                }
            }
        }
    }
    
    void dfs2(const vector<vector<int>>& adj, vector<int>& odd, vector<int>& even)
    {
        stack<pair<int, int>> st; // node, parent
        st.push({0, -1});
        
        while (!st.empty())
        {
            auto [node, parent] = st.top();
            st.pop();
            for (int child : adj[node])
            {
                if (child != parent)
                {
                    int p_even = even[node] - odd[child];
                    int p_odd = odd[node] - even[child];
                    even[child] += p_odd;
                    odd[child] += p_even;
                    st.push({child, node});
                }
            }
        }
    }
    
    pair<vector<int>, vector<int>> findCountsForNodes(const vector<vector<int>>& edges)
    {
        auto adj = buildAdjacencyList(edges);
        
        int n = adj.size();
        vector<int> odd(n);
        vector<int> even(n);
        
        dfs1(adj, odd, even);
        dfs2(adj, odd, even);
        return {odd, even};
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2)
    {
        auto [_, even1] = findCountsForNodes(edges1);
        auto [odd2, even2] = findCountsForNodes(edges2);
        
        int maxi2 = max(*max_element(odd2.begin(), odd2.end()), *max_element(even2.begin(), even2.end()));

        vector<int> res(even1.size());
        for (int i = 0; i < res.size(); ++i)
        {
            res[i] = even1[i] + maxi2;
        }
        
        return res;
    }
};
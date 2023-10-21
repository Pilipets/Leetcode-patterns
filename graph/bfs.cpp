// Breadth-first search(BFS)
//


int bfs(vector<vector<int>>& graph) {
    queue<int> queue;
    unordered_set<int> seen;
    queue.add(START_NODE);
    seen.insert(START_NODE);
    int ans = 0;

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        // do some logic
        for (int neighbor: graph[node]) {
            if (seen.find(neighbor) == seen.end()) {
                seen.insert(neighbor);
                queue.push(neighbor);
            }
        }
    }
}


int bfs_level(vector<vector<int>>& graph) {
    vector<int> cur{{START_NODE}};
    unordered_set<int> seen{{START_NODE}};

    int ans = 0;

    while (!cur.empty()) {
        vector<int> next;
        for (int node : cur)
        {
            // do some logic
            for (int neighbor: graph[node]) {
                if (seen.find(neighbor) == seen.end()) {
                    seen.insert(neighbor);
                    next.push_back(neighbor);
                }
            }
        }

        swap(cur, next);
    }
}
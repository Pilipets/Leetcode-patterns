// Disjoint-set data structure
//
// https://cp-algorithms.com/data_structures/disjoint_set_union.html
// https://en.wikipedia.org/wiki/Disjoint-set_data_structure
//
// Complexity:
// - Amortized O(1) complexity on every operation.
// - Single call up to O(log(n));
// - Final amortized time complexity is O(alpha(n)), where alpha(n) is the inverse Ackermann function, which grows very slowly.


// https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/
//
class Solution {
    int findSet(vector<int> &p, int i)
    {
        while (i != p[i])
        {
            i = p[i];
        }
        return i;
    }
    
    bool setUnion(vector<int> &p, vector<int> &rank, int i, int j)
    {
        i = findSet(p, i);
        j = findSet(p, j);
        
        if (i == j) return false;

        p[j] = i;
        return true;
    }

public:
    int earliestAcq(vector<vector<int>>& logs, int n)
    {
        if (logs.size() < n - 1) return -1;

        sort(logs.begin(), logs.end());
        
        vector<int> p(n), rank(n);
        iota(p.begin(), p.end(), 0);

        // connect n-1 edges
        for (auto &log : logs)
            if (setUnion(p, rank, log[1], log[2]))
                if (--n == 1) return log[0];
        
        return -1;
    }
};


// dsu compression + rank
// https://www.geeksforgeeks.org/union-by-rank-and-path-compression-in-union-find-algorithm/

class Solution
{
    // path compression
    int findSet(int i, vector<int> &p)
    {
        while (p[i] != i) {
            p[i] = p[p[i]]; // optional if we don't need compression
            i = p[i];
        }
        return i;
    }

    // Union by size / rank
    bool setUnion(int i, int j, vector<int> &p, vector<int> &rank)
    {
        i = findSet(i, p);
        j = findSet(j, p);
        
        if (i == j) return false;
        
        // Attach smaller rank tree under root of high rank tree
        if (rank[i] < rank[j]) swap(i, j);
        p[j] = i;
        if (rank[i] == rank[j]) ++rank[i];
        return true;
    }
public:
    int findCircleNum(vector<vector<int>> &mat) {
        if (mat.empty()) return 0;

        int n = mat.size();
        vector<int> p(n), rank(n);
        std::iota(p.begin(), p.end(), 0);
        
        int groups = n;
        for (int i = 0, s1, s2; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
                if (mat[i][j]) groups -= setUnion(i, j, p, rank);
        return groups;
    }
};
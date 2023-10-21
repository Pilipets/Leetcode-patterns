// Disjoint-set data structure
//
// https://cp-algorithms.com/data_structures/disjoint_set_union.html
// https://en.wikipedia.org/wiki/Disjoint-set_data_structure
//
// Complexity:
// - Amortized O(1) complexity on every operation.
// - Single call up to O(log(n));
// - Final amortized time complexity is O(alpha(n)), where alpha(n) is the inverse Ackermann function, which grows very slowly.


class Solution
{
    // path compression
    int findSet(int i, vector<int> &p)
    {
        while (p[i] != i) {
            p[i] = p[p[i]];
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
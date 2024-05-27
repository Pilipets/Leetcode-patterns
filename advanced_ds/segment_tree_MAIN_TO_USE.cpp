//
// Segment tree part1
//
// Segment Tree is a versatile data structure used in computer science and data structures that allow efficient
// querying and updating of intervals or segments of an array. It is particularly useful for problems
// involving range queries, such as finding the sum, minimum, maximum, or any other operation over a specific range of elements in an array.
// The tree is built recursively by dividing the array into segments until each segment represents a single element.
// This structure enables fast query and update operations with a time complexity of O(log n)
//
// https://leetcode.com/articles/a-recursive-approach-to-segment-trees-range-sum-queries-lazy-propagation/
// https://www.geeksforgeeks.org/segment-tree-data-structure/
// https://cp-algorithms.com/data_structures/segment_tree.html
//
// Structure of the Tree: The segment tree works on the principle of divide and conquer. 
// -  At each level, we divide the array segments into two parts. If the given array had [0, . . ., N-1] elements in it
//  then the two parts of the array will be [0, . . ., N/2-1] and [N/2, . . ., N-1]. 
// - We will then recursively go on until the lower and upper bounds of the range become equal. 
// - The structure of the segment tree looks like a binary tree.
//
// The segment tree is generally represented using an array where the first value stores
// the value for the total array range and the child of the node at the ith index are at (2*i + 1) and (2*i + 2).
//
// https://leetcode.com/articles/a-recursive-approach-to-segment-trees-range-sum-queries-lazy-propagation/
//
// Implementation recursive top-down:
// - build O(2*n) time & O(4*n) space for array because of storing the last level of the tree.
//  A segment tree for an  n element range can be comfortably represented using an array of size ≈ 4∗n.
//  We visit each leaf of the segment tree (corresponding to each element in our array arr[]). That makes  n leaves.
//  Also there will be n−1 internal nodes. So we process about 2∗n nodes.
// - The update O(log(n)) process discards half of the range for every level of recursion to reach the appropriate leaf in the tree.
//  This takes time linear to height of the tree.
// - The read/query O(long(n)) process traverses depth-first through the tree looking for node(s) that match exactly with the queried range.
//  At worst, we query for a interval/range of size 1 (which corresponds to a single element), and we end up traversing through the height
//  of the tree. This takes time linear to height of the tree.
//
// Time complexity for query O(log n), update O(log n), https://cs.stackexchange.com/questions/37669/time-complexity-proof-for-segment-tree-implementation-of-the-ranged-sum-problem
//
// Lazy propagation will allow to update range in O(log(n)) time:
//  Ancestors of adjacent leaves are guaranteed to be common at some levels of the tree.
//  lazy[i] holds the amount by which the node tree[i] needs to be incremented, when that node is finally accessed or queried.
//  When lazy[i] is zero, it means that node tree[i] is not lazy and has no pending updates.
//  More in the same link as implementation

// https://leetcode.com/problems/range-sum-query-mutable/
// Segment tree for range sum query
//
class NumArray {
    int n;
    vector<int> tree;
    
    array<int, 3> getChilds(int node, int l, int r)
    {
        int m = l + (r - l) / 2;
        int lnode = 2 * node + 1, rnode = 2 * node + 2;
        return {m, lnode, rnode};
    }
    
    void segmentMerge(int node, int lnode, int rnode)
    {
        tree[node] = tree[lnode] + tree[rnode];
    }

    void segmentBuild(int node, const vector<int>& nums, int l, int r)
    {
        if (l == r)
        {
            tree[node] = nums[l];
            return;
        }

        auto [m, lnode, rnode] = getChilds(node, l, r);

        segmentBuild(lnode, nums, l, m);
        segmentBuild(rnode, nums, m + 1, r);

        segmentMerge(node, lnode, rnode);
    }
    
    void segmentUpdate(int node, int idx, int val, int l, int r)
    {
        if (l == r)
        {
            tree[node] = val;
            return;
        }
        
        auto [m, lnode, rnode] = getChilds(node, l, r);
        if (idx <= m)
        {
            segmentUpdate(lnode, idx, val, l, m);
        }
        else
        {
            segmentUpdate(rnode, idx, val, m + 1, r);
        }

        segmentMerge(node, lnode, rnode);
    }
    
    int segmentQuery(int node, int left, int right, int l, int r)
    {
        // node doesn't cover range
        //
        if (right < l || r < left)
            return 0;

        // node lies in the range
        //
        if (left <= l && r <= right)
            return tree[node];
        
        auto [m, lnode, rnode] = getChilds(node, l, r);
        
        return segmentQuery(lnode, left, right, l, m) + segmentQuery(rnode, left, right, m + 1, r);
    }

public:
    NumArray(vector<int>& nums) : n(nums.size()), tree(4 * n)
    {
        segmentBuild(0, nums, 0, n - 1);
    }
    
    void update(int index, int val)
    {
        segmentUpdate(0, index, val, 0, n - 1);
    }
    
    int sumRange(int left, int right)
    {
        return segmentQuery(0, left, right, 0, n - 1);
    }
};
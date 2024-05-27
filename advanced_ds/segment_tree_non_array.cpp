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
//

// https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LazySegmentTree.h
// https://leetcode.com/problems/maximum-sum-of-subsequence-with-non-adjacent-elements/
//
struct Node
{
    static constexpr long long inf = 1e18;
    Node *l = nullptr, *r = nullptr;
    int lo, hi;
    long long selected[2][2];

    Node(const vector<int> &nums, unsigned int lo, unsigned int hi) : lo(lo), hi(hi)
    {
        if (lo < hi)
        {
            int mid = (lo + hi) / 2;
            l = new Node(nums, lo, mid);
            r = new Node(nums, mid + 1, hi);

            combine();
        }
        else
        {
            selected[0][0] = 0;
            selected[0][1] = -inf;
            selected[1][0] = -inf;
            selected[1][1] = nums[lo];
        }
    }

    void combine()
    {
        selected[0][0] = max(l->selected[0][0] + r->selected[0][0], max(l->selected[0][1] + r->selected[0][0], l->selected[0][0] + r->selected[1][0]));
        selected[0][1] = max(l->selected[0][0] + r->selected[0][1], max(l->selected[0][1] + r->selected[0][1], l->selected[0][0] + r->selected[1][1]));
        selected[1][0] = max(l->selected[1][0] + r->selected[0][0], max(l->selected[1][1] + r->selected[0][0], l->selected[1][0] + r->selected[1][0]));
        selected[1][1] = max(l->selected[1][0] + r->selected[0][1], max(l->selected[1][1] + r->selected[0][1], l->selected[1][0] + r->selected[1][1]));
    }

    void update(int i, long long x)
    {
        if (i < lo || hi < i) return;

        if (lo == hi)
        {
            selected[0][0] = 0;
            selected[1][1] = x;
            return;
        }

        l->update(i, x);
        r->update(i, x);

        combine();
    }
};

class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries)
    {
        static constexpr long long mod = 1e9 + 7;

        Node segmentTree(nums, 0, nums.size() - 1);
        long long res = 0;

        for (auto &query : queries) {
            segmentTree.update(query[0], query[1]);
            res += max(segmentTree.selected[0][0], max(segmentTree.selected[0][1], max(segmentTree.selected[1][0], segmentTree.selected[1][1])));
            res %= mod;
        }
        return res;
    }
};

// Array-based segment tree
// https://www.geeksforgeeks.org/introduction-to-segment-trees-data-structure-and-algorithm-tutorials/
//
class Solution {
    static constexpr int inf = 2e9;

    void merge(long st[][2][2], int node, int lnode, int rnode)
    {
        for (int i = 0; i < 4; i++)
        {
            int x = i / 2;
            int y = i & 1;
            st[node][x][y] = max({
                st[lnode][x][0] + st[rnode][0][y],
                st[lnode][x][1] + st[rnode][0][y],
                st[lnode][x][0] + st[rnode][1][y]
            });
        }
    }

public:
    void build(long st[][2][2], vector<int>& arr, int node, int l, int r)
    {
        if (l == r)
        {
            st[node][0][0] = 0;
            st[node][0][1] = -inf;
            st[node][1][0] = -inf;
            st[node][1][1] = arr[l];
        }
        else
        {
            int m = l + (r - l) / 2;
            int lnode = 2 * node + 1, rnode = 2 * node + 2;

            build(st, arr, lnode, l, m);
            build(st, arr, rnode, m + 1, r);

            merge(st, node, lnode, rnode);
        }
    }

    void update(long st[][2][2], int node, int idx, int val, int l, int r)
    {
        if (l == r)
        {
            st[node][1][1] = val;
            return;
        }

        int m = l + (r - l) / 2;
        int lnode = 2 * node + 1, rnode = 2 * node + 2;
        if (idx <= m)
        {
            update(st, lnode, idx, val, l, m);
        }
        else
        {
            update(st, rnode, idx, val, m + 1, r);
        }

        merge(st, node, lnode, rnode);
    }

    int maximumSumSubsequence(vector<int>& arr, vector<vector<int>>& qarr)
    {
        static constexpr int m = 1e9 + 7;
        const int n = arr.size();
        long st[n << 2][2][2];

        build(st, arr, 0, 0, n - 1);

        long ans = 0;
        for (const auto& q : qarr)
        {
            int idx = q[0], val = q[1];
            update(st, 0, idx, val, 0, n - 1);

            long cs = 0;
            for (int i = 0; i < 4; i++)
                cs = max(cs, st[0][i / 2][i & 1]);
            ans = (ans + cs) % m;
        }
        return ans;
    }
};
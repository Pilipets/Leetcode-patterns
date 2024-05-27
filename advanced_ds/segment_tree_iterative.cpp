//
// Segment tree part2
//
// Segment Tree is a versatile data structure used in computer science and data structures that allow efficient
// querying and updating of intervals or segments of an array. It is particularly useful for problems
// involving range queries, such as finding the sum, minimum, maximum, or any other operation over a specific range of elements in an array.
// The tree is built recursively by dividing the array into segments until each segment represents a single element.
// This structure enables fast query and update operations with a time complexity of O(log n)
//
// https://leetcode.com/problems/range-sum-query-mutable/solution/
//
// !!!DON'T USE IN THE INTERVIEW OR CONTEST BECAUSE IS HARD TO IMPLEMENT AND UNDERSTAND
//
// Implementation iterative bottom-up:
// - build O(2*n) time & O(2*n) space for array because of storing the last level of the tree.
//  The number of nodes in each level is half the number in the level below.
//  n + n/2 + n/4 + ... + n/2^k + ... + 1 = 2n - 1 = O(n)
// - Time complexity for query O(log n), update O(log n), https://cs.stackexchange.com/questions/37669/time-complexity-proof-for-segment-tree-implementation-of-the-ranged-sum-problem
//
// https://www.geeksforgeeks.org/segment-tree-efficient-implementation/
// Link above is even more efficient in terms of operations, not complexity.
//

// https://leetcode.com/problems/range-sum-query-mutable/
// Segment tree for range sum query
//
class NumArray {
    int n;
    vector<int> tree;

public:
    NumArray(vector<int>& nums) : n(nums.size()), tree(2 * n)
    {
        for (int i = n, j = 0;  i < 2 * n; i++,  j++)
            tree[i] = nums[j];
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    
    void update(int pos, int val)
    {
        pos += n;
        tree[pos] = val;

        while (pos > 0)
        {
            int left = pos, right = pos;

            if (pos % 2 == 0)
                right = pos + 1;
            else
                left = pos - 1;

            // parent is updated after child is updated
            //
            tree[pos / 2] = tree[left] + tree[right];
            pos /= 2;
        }
    }
    
    int sumRange(int l, int r)
    {
        l += n; // get leaf with value 'l'
        r += n; // get leaf with value 'r'

        int sum = 0;
        while (l <= r)
        {
            if ((l % 2) == 1)
            {
               sum += tree[l];
               l++;
            }

            if ((r % 2) == 0)
            {
               sum += tree[r];
               r--;
            }

            l /= 2;
            r /= 2;
        }

        return sum;
    }
};

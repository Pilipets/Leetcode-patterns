// Find number of subarrays that fit an exact criteria
//
int fn(vector<int>& arr, int k)
{
    unordered_map<int, int> counts;
    counts[0] = 1;
    int ans = 0, curr = 0;

    for (int num: arr)
    {
        // do logic to change curr
        if (counts.count(curr - k))
            ans += counts[curr - k];
        counts[curr]++;
    }

    return ans;
}


// https://leetcode.com/problems/special-array-ii/
// Result on the range [l, r] is the same as result on the range [0, r] - result on the range [0, l - 1]
//
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries)
    {
        vector<int> prefix(nums.size());
        for (int i = 1; i < nums.size(); ++i)
            prefix[i] = ((nums[i] & 1) == (nums[i - 1] & 1)) + prefix[i - 1];

        vector<bool> res;
        res.reserve(queries.size());
        for (const auto& q : queries)
        {
            res.push_back(prefix[q[1]] == prefix[q[0]]);
        }
        
        return res;
    }
};


// https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/
// Another example is line sweep where we add before range and subtract after range
//
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // If there's only one element, the maximum beauty is 1
        if (nums.size() == 1) return 1;

        int maxBeauty = 0;
        int maxValue = 0;

        // Find the maximum value in the array
        for (int num : nums) maxValue = max(maxValue, num);

        // Create an array to keep track of the count changes
        vector<int> count(maxValue + 1, 0);

        // Update the count array for each value's range [val - k, val + k]
        for (int num : nums) {
            count[max(num - k, 0)]++;  // Increment at the start of the range
            if (num + k + 1 <= maxValue)
                count[num + k + 1]--;  // Decrement after the range
        }

        int currentSum = 0;  // Tracks the running sum of counts
        // Calculate the prefix sum and find the maximum value
        for (int val : count) {
            currentSum += val;
            maxBeauty = max(maxBeauty, currentSum);
        }

        return maxBeauty;
    }
};
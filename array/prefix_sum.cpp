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
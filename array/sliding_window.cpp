// Sliding window
//


int fn(vector<int>& arr)
{
    int left = 0, ans = 0, curr = 0;

    for (int right = 0; right < arr.size(); right++) {
        // do logic here to add arr[right] to curr

        while (WINDOW_CONDITION_BROKEN) {
            // remove arr[left] from curr
            left++;
        }

        // update ans
    }

    return ans;
}


// Non-decreasing sliding window
//
// LC problem - https://leetcode.com/problems/find-the-longest-equal-subarray/
// https://leetcode.com/problems/find-the-longest-equal-subarray/discuss/3934172/JavaC%2B%2BPython-One-Pass-Sliding-Window-O(n)
//
// Algorithm: Since maxf is actually the max frequency in HISTORY (not the current subarray), then why we usej - i + 1 - maxf
// to determine if the subarray is valid or not? The numbers correspond to maxf may not be even in the subarray!!!
// The answer is, the subarray may indeed be invalid, but, it is always guaranteed to be valid when we are updating maxf,
// namely, when for nums[j] we get count[nums[j]] > maxf, the subarray is valid.


class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k)
    {
        unordered_map<int, int> nums_count;
        
        int max_count = 0;
        
        for (int i = 0, j = 0; j < nums.size(); ++j)
        {
            int num_cnt = ++nums_count[nums[j]];
            if (num_cnt > max_count)
                max_count = num_cnt;

            int to_del = j - i + 1 - max_count;
            if (to_del > k)
                --nums_count[nums[i++]];
        }
        
        return max_count;
    }
};
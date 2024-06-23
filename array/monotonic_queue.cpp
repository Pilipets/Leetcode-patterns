// Monotonic queue
//
// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/solution/
//
// Algorithm:
//   One deque maintains numbers in decreasing order, ensuring the largest number in the window is always at the front.
// If a new number exceeds those at the deque's end, we remove those elements since they can no longer be the maximum in the current window.
//   Removing elements from the front of either deque maintains the correct min and max values in constant time, enabling efficient checks to ensure the window stays within the limit.
//
// Complexity:
// O(n)

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> q_min, q_max;
        
        int res = 0;
        for (int l = 0, r = 0; r < nums.size(); ++r)
        {
            // 1 4 7
            while (!q_min.empty() && q_min.back() > nums[r])
                q_min.pop_back();
            q_min.push_back(nums[r]);
            
            // 7 4 1
            while (!q_max.empty() && q_max.back() < nums[r])
                q_max.pop_back();
            q_max.push_back(nums[r]);
            
            while (q_max.front() - q_min.front() > limit)
            {
                if (nums[l] == q_min.front())
                    q_min.pop_front();

                if (nums[l] == q_max.front())
                    q_max.pop_front();

                l += 1;
            }
            
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};
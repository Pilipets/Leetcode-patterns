// Monotonic increasing stack
//
// https://www.geeksforgeeks.org/introduction-to-monotonic-stack-data-structure-and-algorithm-tutorials/
//
// Algorithm:
// - Monotonic stack is generally used to deal with a typical problem like Next Greater Element(NGE).
// - Before pushing into the stack, POP all the elements till top is bigger than the element to be inserted.


int fn(vector<int>& arr)
{
    stack<integer> stack;
    int ans = 0;

    for (int num: arr)
    {
        // for monotonic decreasing, just flip the > to <
        while (!stack.empty() && stack.top() > num)
        {
            // do logic
            stack.pop();
        }

        stack.push(num);
    }
}


// https://leetcode.com/problems/number-of-valid-subarrays/solution/
//
class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int res = 0;
        stack<int> st;

        for (int i = 0; i < nums.size(); ++i)
        {
            while (!st.empty() && nums[i] < nums[st.top()])
            {
                // pop all items smaller than current
                res += (i - st.top());
                st.pop();
            }
            
            st.push(i);
        }
        
        while (!st.empty())
        {
            res += (nums.size() - st.top());
            st.pop();
        }
        
        return res;
    }
};

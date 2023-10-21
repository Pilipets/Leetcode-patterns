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
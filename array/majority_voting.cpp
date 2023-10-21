// Boyer–Moore majority vote algorithm
//
// The algorithm finds a majority element, if there is one: that is, an element that occurs repeatedly for more than half of the elements of the input.
// Second pass through the data can be used to verify that the element found in the first pass really is a majority.


int majorityElement(vector<int>& nums)
{
    int counter = 0, majority;
    for (int num : nums) {
        if (!counter) {
            majority = num;
        }
        counter += num == majority ? 1 : -1;
    }
    return majority;
}
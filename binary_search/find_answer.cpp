// Binary search the answer and check if valid
//


int fn(vector<int>& arr)
{
    int left = MINIMUM_POSSIBLE_ANSWER, right = MAXIMUM_POSSIBLE_ANSWER;
    int res = -1;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (check(mid)) {
            res = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return res;
}

bool check(int x)
{
    // this function is implemented depending on the problem
    return BOOLEAN;
}
// Binary Search upper bound
//


int upperBound(vector<int>& arr, int target)
{
    int left = 0, right = arr.size();
    while (left < right)
    {
        int mid = left + ((right - left) >> 1);
        if (target >= arr[mid]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}


template<class ForwardIt, class T>
ForwardIt upper_bound(ForwardIt first, ForwardIt last, const T& value)
{
    ForwardIt it;
    typename std::iterator_traits<ForwardIt>::difference_type count, step;
    count = std::distance(first, last);
 
    while (count > 0)
    {
        it = first; 
        step = count / 2; 
        std::advance(it, step);
 
        if (!(value < *it))
        {
            first = ++it;
            count -= step + 1;
        } 
        else
            count = step;
    }
 
    return first;
}
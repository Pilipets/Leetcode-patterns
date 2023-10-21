// Binary Search lower bound
//


int lowerBound(vector<int>& arr, int target)
{
    int left = 0, right = arr.size();
    while (left < right)
    {
        int mid = left + ((right - left) >> 1);
        if (target < arr[midd]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}


template<class ForwardIt, class T, class Compare>
ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value, Compare comp)
{
    ForwardIt it;
    typename std::iterator_traits<ForwardIt>::difference_type count, step;
    count = std::distance(first, last);
 
    while (count > 0)
    {
        it = first;
        step = count >> 1;
        std::advance(it, step);
 
        if (comp(*it, value))
        {
            first = ++it;
            count -= step + 1;
        }
        else
            count = step;
    }
 
    return first;
}



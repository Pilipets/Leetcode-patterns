// Quickselect or k-th largest element
//
// https://en.wikipedia.org/wiki/Quickselect
// https://www.geeksforgeeks.org/kth-smallest-largest-element-in-unsorted-array/
//
// Algorithm: Hoare's selection algorithm
// - Choose a random pivot.
// - Use a partition algorithm to place the pivot into its perfect position pos in the sorted array,
//  move smaller elements to the left of pivot, and larger or equal ones - to the right.
// Compare pos and N - k to choose the side of array to proceed recursively.
// - This algorithm works well even for arrays with duplicates.
// - A modification of Quicksort known as ternary Quicksort creates a third sub-array with all elements equal to the pivot. 
//
// Note: nth_element is implemented as introselect (introspective selection) is a selection algorithm
// - Hybrid of quickselect and median of medians which has fast average performance and optimal worst-case performance
// - https://en.wikipedia.org/wiki/Introselect
// - https://stackoverflow.com/questions/29145520/how-is-nth-element-implemented
//
// Complexity: average O(n) time
// In the worst case, the randomized function may always pick a corner element - O(n^2)
//
//
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int left = 0, right = nums.size() - 1;
        while (true) {
            int p = partition(nums, left, right, left + rand() % (right-left+1));
            if (p == k) return nums[p];

            if (k < p) right = p - 1;
            else left = p + 1;
        }
        return -1;
    }
private:
    int partition(vector<int>& arr, int low, int high, int pivot) {
        swap(arr[pivot], arr[high]);
        pivot = arr[high];

        for (int i = low; i < high; ++i)
            if(arr[i] < pivot)
                swap(arr[i], arr[low++]);

        swap(arr[high], arr[low]);
        return low;
    }
};

// There are exists an algorithm with wost case O(n) but has poor performance on average.
// https://www.geeksforgeeks.org/kth-smallest-largest-element-in-unsorted-array-worst-case-linear-time/
//
// Algorithm: kthSmallest(arr[0..n-1], k) 
// 1) Divide arr[] into ⌈n/5⌉ groups where size of each group is 5 except possibly the last group which may have less than 5 elements. 
// 2) Sort the above created ⌈n/5⌉ groups and find median of all groups. Create an auxiliary array ‘median[]’ and store medians of all ⌈n/5⌉ groups in this median array.
// Recursively call this method to find median of median[0..⌈n/5⌉-1] 
// 3) medOfMed = kthSmallest(median[0..⌈n/5⌉-1], ⌈n/10⌉)
// 4) Partition arr[] around medOfMed and obtain its position. pos = partition(arr, n, medOfMed)
// 5) If pos == k return medOfMed
// 6) If pos > k return kthSmallest(arr[l..pos-1], k) 
// 7) If pos < k return kthSmallest(arr[pos+1..r], k-pos+l-1)
//
//
int partition(int arr[], int l, int r, int k); 
  
// A simple function to find median of arr[].  This is called 
// only for an array of size 5 in this program. 
int findMedian(int arr[], int n) 
{ 
    sort(arr, arr+n);  // Sort the array 
    return arr[n/2];   // Return middle element 
} 
  
// Returns k'th smallest element in arr[l..r] in worst case 
// linear time. ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT 
int kthSmallest(int arr[], int l, int r, int k) 
{ 
    // If k is smaller than number of elements in array 
    if (k > 0 && k <= r - l + 1) 
    { 
        int n = r-l+1; // Number of elements in arr[l..r] 
  
        // Divide arr[] in groups of size 5, calculate median 
        // of every group and store it in median[] array. 
        int i, median[(n+4)/5]; // There will be floor((n+4)/5) groups; 
        for (i = 0; i < n/5; i++) 
            median[i] = findMedian(arr + l + i*5, 5); 
        if (i*5 < n) //For last group with less than 5 elements 
        { 
            median[i] = findMedian(arr + l+i*5, n % 5);  
            i++; 
        }     
  
        // Find median of all medians using recursive call. 
        // If median[] has only one element, then no need 
        // of recursive call 
        int medOfMed = (i == 1)? median[i-1] : kthSmallest(median, 0, i-1, i/2); 
  
        // Partition the array around a random element and 
        // get position of pivot element in sorted array 
        int pos = partition(arr, l, r, medOfMed); 
  
        // If position is same as k 
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)  // If position is more, recur for left 
            return kthSmallest(arr, l, pos-1, k); 
  
        // Else recur for right subarray 
        return kthSmallest(arr, pos+1, r, k-pos+l-1); 
    } 
  
    // If k is more than number of elements in array 
    return INT_MAX; 
}
  
// It searches for x in arr[l..r], and partitions the array  
// around x. 
int partition(int arr[], int l, int r, int x) 
{ 
    // Search for x in arr[l..r] and move it to end 
    int i; 
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swap(arr[i], arr[r]); 
  
    // Standard partition algorithm 
    i = l; 
    for (int j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(arr[i], arr[j]); 
            i++; 
        } 
    } 
    swap(arr[i], arr[r]); 
    return i; 
} 
// Binary Heap or Priority Queue
//
// https://www.geeksforgeeks.org/heap-data-structure/
// https://www.quora.com/How-is-STLs-partial_sort-implemented
// https://leetcode.com/submissions/detail/290918157/
// https://www.geeksforgeeks.org/time-complexity-of-building-a-heap/
//
// Algorithm:
// - Operations are build, insert, extract, decrease
// - Other heaps are binomial, Fibonacci, Leftist, K-ary
// - Heapify, Insertion, Deletion, Decrease, Build
// - Build is O(n)
//
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        buildMaxHeap(nums);
        for (int i = 0; i < k - 1; i++) {
            swap(nums[0], nums[--heapSize]);
            maxHeapify(nums, 0);
        }
        return nums[0];
    }
private:
    int heapSize;
    
    int left(int i) { return (i << 1) + 1; }
    int right(int i) { return (i << 1) + 2; }
    
    void maxHeapify(vector<int>& nums, int i) {
        int largest = i, l = left(i), r = right(i);
        if (l < heapSize && nums[l] > nums[largest]) {
            largest = l;
        }
        if (r < heapSize && nums[r] > nums[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(nums[i], nums[largest]);
            maxHeapify(nums, largest);
        }
    }
    
    void buildMaxHeap(vector<int>& nums) {
        heapSize = nums.size();
        for (int i = (heapSize >> 1) - 1; i >= 0; i--)
            maxHeapify(nums, i);
    }
};


// STL heap
//
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};

// STL make_heap, pop_heap, push_heap, sort_heap - push/pop from the end
//
int main()
{
    print("Max heap");
 
    std::vector<int> v{3, 2, 4, 1, 5, 9};
    print("initially, v", v);
 
    std::make_heap(v.begin(), v.end());
    print("after make_heap, v", v);
 
    std::pop_heap(v.begin(), v.end());
    print("after pop_heap, v", v);
 
    auto top = v.back();
    v.pop_back();
    print("former top element", {top});
    print("after removing the former top element, v", v);

    v.push_back(6);
    println("after push_back: ", v);
 
    std::push_heap(v.begin(), v.end());
    println("after push_heap: ", v);
}


// GeeksForGeeks implementation for Min Heap - root is smallest
//
class MinHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
 
    void MinHeapify(int i)
    {
        int l = left(i), r = right(i);

        int smallest = i;
        if (l < heap_size && harr[l] < harr[i])
            smallest = l;

        if (r < heap_size && harr[r] < harr[smallest])
            smallest = r;

        if (smallest != i)
        {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }
 
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

public:
    MinHeap(int capacity) : capacity(capacity)
    {
        harr = new int[capacity];
        heap_size = 0;
    }
 
    int extractMin()
    {
        if (heap_size <= 0) return INT_MAX;
        if (heap_size-- == 1) return harr[0];
    
        int root = std::exchange(harr[0], harr[heap_size]);
        MinHeapify(0);
        return root;
    }
 
    void decreaseKey(int i, int new_val)
    {
        // It is assumed that new_val is smaller than harr[i].
        harr[i] = new_val;
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }
 
    int getMin() { return harr[0]; }
 
    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }
 
    void MinHeap::insertKey(int k)
    {
        if (heap_size == capacity)
        {
            return;
        }
    
        // First insert the new key at the end
        heap_size++;
        int i = heap_size - 1;
        harr[i] = k;
    
        // Fix the min heap property if it is violated
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }
};
//
// https://www.geeksforgeeks.org/heap-sort/
//
// Remarks:
// - Heap sort is an in-place algorithm. 
// - Its typical implementation is not stable but can be made stable.
// - Typically 2-3 times slower than well-implemented QuickSort.  The reason for slowness is a lack of locality of reference.
//
// Complexity:
// - Time: O(N log N)
// - Space: O(log n), due to the recursive call stack. However, auxiliary space can be O(1) for iterative implementation.
//
//

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int N, int i)
{

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int N)
{

    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// iterative heap-sort
// https://www.geeksforgeeks.org/iterative-heap-sort/
//
// function build Max Heap where value  
// of each child is always smaller 
// than value of their parent 
void buildMaxHeap(int arr[], int n)  
{  
    for (int i = 1; i < n; i++)  
    { 
        // if child is bigger than parent 
        if (arr[i] > arr[(i - 1) / 2])  
        { 
            int j = i; 
      
            // swap child and parent until 
            // parent is smaller 
            while (arr[j] > arr[(j - 1) / 2])  
            { 
                swap(arr[j], arr[(j - 1) / 2]); 
                j = (j - 1) / 2; 
            } 
        } 
    } 
} 
  
void heapSort(int arr[], int n)  
{ 
    buildMaxHeap(arr, n); 
  
    for (int i = n - 1; i > 0; i--) 
    { 
        // swap value of first indexed  
        // with last indexed  
        swap(arr[0], arr[i]); 
      
        // maintaining heap property 
        // after each swapping 
        int j = 0, index; 
          
        do
        { 
            index = (2 * j + 1); 
              
            // if left child is smaller than  
            // right child point index variable  
            // to right child 
            if (arr[index] < arr[index + 1] &&  index < (i - 1)) 
                index++; 
          
            // if parent is smaller than child  
            // then swapping parent with child  
            // having higher value 
            if (arr[j] < arr[index] && index < i) 
                swap(arr[j], arr[index]); 
          
            j = index; 
          
        } while (index < i); 
    } 
} 
//
// Radix sort
//
// Steps:
// - Sort array using bucket sort: For each place value (unit place to last place) sort the array using counting/bucket sort.
// - Bucket Sort: We need 10 buckets for each digit (0 - 9), and we will push array elements into their respective bucket
//  and fetch the elements from each bucket one by one in the order it was pushed in the bucket.
//
// Why not to use always?
// https://stackoverflow.com/questions/3539265/why-quicksort-is-more-popular-than-radix-sort
// Reason: Extra memory, Only numbers comparison, Complexity implementation, non-stable...
//

class Solution {
    // Bucket sort function for each place value digit.
    void bucketSort(vector<int>& arr, int placeValue) {
        vector<vector<int>> buckets(10, vector<int>());
        // Store the respective number based on its digit.
        for (int& val : arr) {
            int digit = abs(val) / placeValue;
            digit = digit % 10;
            buckets[digit].push_back(val);
        }

        // Overwrite 'arr' in sorted order of current place digits.
        int index = 0;
        for (int digit = 0; digit < 10; ++digit) {
            for (int& val : buckets[digit]) {
                arr[index] = val;
                index++;
            }
        }
    }

    // Radix sort function.
    void radixSort(vector<int>& arr) {
        // Find the absolute maximum element to find max number of digits.
        int maxElement = arr[0];
        for (int& val : arr) {
            maxElement = max(abs(val), maxElement);
        }
        int maxDigits = 0;
        while (maxElement > 0) {
            maxDigits += 1;
            maxElement /= 10;
        }

        // Radix sort, least significant digit place to most significant.
        int placeValue = 1;
        for (int digit = 0; digit < maxDigits; ++digit) {
            bucketSort(arr, placeValue);
            placeValue *= 10;
        }
    }

public:
    int heightChecker(vector<int>& heights) {
        // Sort the array using radix sort.
        vector<int> sortedHeights = heights;
        radixSort(sortedHeights);

        int count = 0;
        // Loop through the original and sorted arrays.
        for (int i = 0; i < sortedHeights.size(); ++i) {
            // Increment count if elements at the same index differ.
            if (heights[i] != sortedHeights[i]) {
                count += 1;
            }
        }
        // Return the total count of differing elements.
        return count;
    }
};
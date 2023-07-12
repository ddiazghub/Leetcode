#include <vector>
#include <iostream>

/**
 * Merge 2 sorted arrays into a single sorted array.
 */
std::vector<int> merge(std::vector<int> &array1, std::vector<int> &array2) {
    int size1 = array1.size(), size2 = array2.size();

    // Initialize indexes and output array.
    int index1 = 0, index2 = 0, outIndex = 0;
    std::vector<int> merger(size1 + size2);

    // While we haven't reached the end of any array.
    while (index1 < size1 && index2 < size2) {
        // If the next element in array 1 is smaller than the next element of array 2, insert it at the next position of the merger.
        // Otherwise insert the element of array 2, advance the respective pointers to the next position.
        if (array1[index1] < array2[index2]) {
            merger[outIndex] = array1[index1];
            index1++;
        } else {
            merger[outIndex] = array2[index2];
            index2++;
        }

        outIndex++;
    }

    // One of the arrays will exit the loop without being completely inserted.
    // Copy the rest of the remaining array into the merged array.
    if (index1 == size1)
        std::copy(array2.begin() + index2, array2.end(), merger.begin() + outIndex);
    else
        std::copy(array1.begin() + index1, array1.end(), merger.begin() + outIndex);

    return merger;
}

/**
 * Find the median of the merger of 2 sorted array.
 */
double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
    // Merge the arrays.
    std::vector<int> merger = merge(nums1, nums2);
    int n = merger.size();

    // Empty arrays.
    if (n == 0)
        return 0.0;

    // Find the index of the median.
    int half = n / 2;

    // If the number of elements is even, the median is the average of the 2 middle elements.
    if (n % 2 == 0)
        return (merger[half - 1] + merger[half]) / 2.0;
    
    return merger[half];
}

int main() {
    std::vector<int> nums1{3};
    std::vector<int> nums2{-2, -1};
    std::cout << findMedianSortedArrays(nums1, nums2) << '\n';
}
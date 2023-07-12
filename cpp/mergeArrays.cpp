#include <vector>
#include <algorithm>

/**
 * Merge 2 sorted arrays into a single one.
 */
void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    // Init pointers.
    int index1 = m - 1;
    int index2 = n - 1;
    int outIndex = m + n - 1;

    // Merge while the end of any array  hasn't been reached.
    while (index1 > -1 && index2 > -1) {
        // If the next value of array1 is greater than the next value of array 2 add it to the out pointer's position otherwise add the next element of array 2.
        if (nums1[index1] > nums2[index2]) {
            nums1[outIndex] = nums1[index1];
            index1--;
        } else {
            nums1[outIndex] = nums2[index2];
            index2--;
        }

        outIndex--;
    }
    
    // Copy the rest of the array that wasn't completely merged.
    if (index1 == -1)
        std::copy(nums2.cbegin(), nums2.cbegin() + (index2 + 1), nums1.begin());
    else
        std::copy(nums1.cbegin(), nums1.cbegin() + (index1 + 1), nums1.begin());
}

int main() {
    
}
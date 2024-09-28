#include <stdio.h>
#include <stdlib.h>

extern "C" {
#include "Median_Of-Two_Sorted_Arrays.h"
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double median = 0.0;
    int total_size = nums1Size + nums2Size;
    int* merged = (int*)malloc(total_size * sizeof(int));
    int i = 0, j = 0, k = 0;

    if (nums1Size == 0 && nums2Size == 0) {
        printf("Size of nums1 and nums2 are both 0\n");
        free(merged);
        return median;
    }
    else if (nums1Size == 0) {
        if (nums2Size % 2 == 0) {
            free(merged);
            return (nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2.0;
        }
        else {
            free(merged);
            return nums2[nums2Size / 2];
        }
    }
    else if (nums2Size == 0) {
        if (nums1Size % 2 == 0) {
            free(merged);
            return (nums1[nums1Size / 2 - 1] + nums1[nums1Size / 2]) / 2.0;
        }
        else {
            free(merged);
            return nums1[nums1Size / 2];
        }
    }

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            merged[k++] = nums1[i++];
        }
        else {
            merged[k++] = nums2[j++];
        }
    }

    while (i < nums1Size) {
        merged[k++] = nums1[i++];
    }

    while (j < nums2Size) {
        merged[k++] = nums2[j++];
    }
    if (total_size % 2 == 0) {
        median = (merged[total_size / 2 - 1] + merged[total_size / 2]) / 2.0;
    }
    else {
        median = merged[total_size / 2];
    }

    free(merged);
    return median;
}

int main() {
    int nums1[] = { 1, 2, 5, 10, 1 };
    int nums2[] = { 3, 4, 5, 8, 4, 10, 500 };
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    double med = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf("Median is: %f\n", med);

    return 0;
}

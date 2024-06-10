extern "C" {
#include "Median_Of-Two_Sorted_Arrays.h"
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

int main()
{
	double nums1[] = {1, 3}, nums2[] = {2};
	int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
	int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

	findMedianSortedArrays((int*) nums1, nums1Size, (int*) nums2, nums2Size);

	return 0;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	double median = 0.0, sum = 0.0;
	if (nums1Size == 0 && nums2Size == 0) {
		printf("Size if nums1 and nums2 are 0\n");
		return median;
	}
	else if (nums1Size == 0) {
		printf("Size of nums1 is 0\n");
		for (int i = 0; i < nums2Size - 1; i++){
			 sum += nums2[i];
			 median = sum / nums2Size;
		}
		return median;
	}
	else if (nums2Size == 0) {
		printf("Size of nums2 is 0\n");
		for (int j = 0; j < nums1Size - 1; j++) {
			sum += nums1[j];
			median = sum / nums1Size;
		}
		return median;
	}
	 int totallSize = nums1Size + nums2Size;
	const int temp = 10;
	int temp_nums[temp] = { 0 };
	printf("sizenums1 is:%d and sizenums2 is:%d\n", nums1Size, nums2Size);
	printf("---------------------------------------------------------\n");
	printf("totallsize is:%d\n", totallSize);

	return median;
}
extern "C" {
	#include "Two_Sum.h"
}

void Two_Sum(int num[], int target, int array_size);

int main()
{
	int num[] = {2,7,11,15,40,4};
	int target = 2;
	int array_size = sizeof(num) / sizeof(num[0]);
	Two_Sum(num, target, array_size);

	return 0;
}

void Two_Sum(int num[], int target, int array_size) {
	int res = 0;
	for (int i = 0; i < array_size - 1; i++) {
		for (int j = 0; j < array_size - i; j++) {
			res = num[i] + num[j + i];
			if (res == target) {
				printf("num is [%d,%d]\n", i, j+i);
				break;
			}
		}
		res = 0;
	}
}
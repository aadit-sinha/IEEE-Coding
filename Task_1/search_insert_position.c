#include <stdio.h>

int searchInsert(int nums[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

int main() {
    int nums[] = {1, 3, 5, 6};
    int n = 4;
    int target = 5;

    int result = searchInsert(nums, n, target);

    printf("Insert Position = %d\n", result);

    return 0;
}
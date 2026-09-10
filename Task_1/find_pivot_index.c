#include <stdio.h>

int pivotIndex(int nums[], int n) {
    int totalSum = 0;
    int leftSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totalSum += nums[i];
    }

    // Check each index
    for (int i = 0; i < n; i++) {

        // Right sum = total sum - left sum - current element
        int rightSum = totalSum - leftSum - nums[i];

        if (leftSum == rightSum) {
            return i;
        }

        // Add current element to left sum
        leftSum += nums[i];
    }

    return -1;
}

int main() {
    int nums[] = {1, 7, 3, 6, 5, 6};
    int n = 6;

    int result = pivotIndex(nums, n);

    printf("Pivot Index = %d\n", result);

    return 0;
}
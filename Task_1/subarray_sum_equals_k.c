#include <stdio.h>

int subarraySum(int nums[], int n, int k) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += nums[j];

            if (sum == k) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int nums[] = {1, 1, 1};
    int n = 3;
    int k = 2;

    int result = subarraySum(nums, n, k);

    printf("Number of subarrays = %d\n", result);

    return 0;
}
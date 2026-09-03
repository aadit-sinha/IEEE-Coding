#include <stdio.h>

double MaxAverage(int nums[], int n, int k) {
    int sum = 0;

    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }

    int maxSum = sum;

    for (int i = k; i < n; i++) {
        sum = sum - nums[i - k] + nums[i];

        if (sum > maxSum) {
            maxSum = sum;
        }
    }

    return (double)maxSum / k;
}

int main() {
    int nums[] = {1, 12, -5, -6, 50, 3};
    int n = 6;
    int k = 4;

    double result = MaxAverage(nums, n, k);

    printf("Maximum Average = %.5f\n", result);

    return 0;
}
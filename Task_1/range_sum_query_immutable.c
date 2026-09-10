#include <stdio.h>

typedef struct {
    int prefix[10000];
} NumArray;

void NumArrayCreate(NumArray* obj, int nums[], int n) {
    obj->prefix[0] = 0;

    for (int i = 0; i < n; i++) {
        obj->prefix[i + 1] = obj->prefix[i] + nums[i];
    }
}

int sumRange(NumArray* obj, int left, int right) {
    return obj->prefix[right + 1] - obj->prefix[left];
}

int main() {
    int nums[] = {-2, 0, 3, -5, 2, -1};
    int n = 6;

    NumArray obj;

    NumArrayCreate(&obj, nums, n);

    printf("Sum from index 0 to 2 = %d\n", sumRange(&obj, 0, 2));
    printf("Sum from index 2 to 5 = %d\n", sumRange(&obj, 2, 5));
    printf("Sum from index 0 to 5 = %d\n", sumRange(&obj, 0, 5));

    return 0;
}
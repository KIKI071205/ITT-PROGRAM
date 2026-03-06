#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Element;

// Comparator for qsort
int compare(const void* a, const void* b) {
    return ((Element*)a)->val - ((Element*)b)->val;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Element* elements = (Element*)malloc(numsSize * sizeof(Element));
    for (int i = 0; i < numsSize; i++) {
        elements[i].val = nums[i];
        elements[i].index = i;
    }

    // Sort elements based on value
    qsort(elements, numsSize, sizeof(Element), compare);

    int left = 0;
    int right = numsSize - 1;
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    while (left < right) {
        int sum = elements[left].val + elements[right].val;
        if (sum == target) {
            result[0] = elements[left].index;
            result[1] = elements[right].index;
            free(elements);
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    free(elements);
    return NULL;
}

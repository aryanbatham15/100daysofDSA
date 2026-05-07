#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];  // sort by start time
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, 
            int* returnSize, int** returnColumnSizes) {
    
    // Sort by start time
    qsort(intervals, intervalsSize, sizeof(int*), compare);
    
    // Allocate result
    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < intervalsSize; i++) {
        if (*returnSize == 0 || intervals[i][0] > result[*returnSize - 1][1]) {
            // No overlap → add new interval
            result[*returnSize] = (int*)malloc(2 * sizeof(int));
            result[*returnSize][0] = intervals[i][0];
            result[*returnSize][1] = intervals[i][1];
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        } else {
            // Overlap → merge by extending end
            if (intervals[i][1] > result[*returnSize - 1][1])
                result[*returnSize - 1][1] = intervals[i][1];
        }
    }

    return result;
}

// ---- Test ----
int main() {
    int n = 4;
    int data[][2] = {{1,3},{2,6},{8,10},{15,18}};

    int** intervals = (int**)malloc(n * sizeof(int*));
    int* colSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        intervals[i] = data[i];
        colSizes[i] = 2;
    }

    int returnSize;
    int* returnColSizes;
    int** res = merge(intervals, n, colSizes, &returnSize, &returnColSizes);

    printf("Merged Intervals:\n");
    for (int i = 0; i < returnSize; i++)
        printf("[%d, %d]\n", res[i][0], res[i][1]);

    return 0;
}
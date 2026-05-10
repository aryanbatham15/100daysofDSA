
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int val;    
    int idx;   
} Pair;

static int *g_count;   

static void merge(Pair *arr, Pair *tmp, int left, int mid, int right) {
    int i = left, j = mid, k = left;

    while (i < mid && j <= right) {
        if (arr[i].val <= arr[j].val) {
            g_count[arr[i].idx] += (k - j); 
            tmp[k++] = arr[i++];
        } else {
            
            tmp[k++] = arr[j++];
        }
    }
    /* Flush remaining left-half elements */
    while (i < mid) {
        g_count[arr[i].idx] += (k - j);
        tmp[k++] = arr[i++];
    }
    /* Flush remaining right-half elements */
    while (j <= right) {
        tmp[k++] = arr[j++];
    }
    /* Copy merged result back */
    memcpy(arr + left, tmp + left, (right - left + 1) * sizeof(Pair));
}

static void merge_sort(Pair *arr, Pair *tmp, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    merge_sort(arr, tmp, left,    mid);
    merge_sort(arr, tmp, mid + 1, right);
    merge(arr, tmp, left, mid + 1, right);
}

void count_smaller_merge_sort(int *arr, int n, int *result) {
    Pair *pairs = (Pair *)malloc(n * sizeof(Pair));
    Pair *tmp   = (Pair *)malloc(n * sizeof(Pair));
    g_count = result;

    for (int i = 0; i < n; i++) {
        pairs[i].val = arr[i];
        pairs[i].idx = i;
        result[i]    = 0;
    }

    merge_sort(pairs, tmp, 0, n - 1);

    free(pairs);
    free(tmp);
}


static int bit[100005];  
static int bit_size;

static void bit_update(int i, int delta) {
    for (; i <= bit_size; i += i & (-i))
        bit[i] += delta;
}

static int bit_query(int i) {    
    int s = 0;
    for (; i > 0; i -= i & (-i))
        s += bit[i];
    return s;
}
static int cmp_val(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void count_smaller_bit(int *arr, int n, int *result) {
    /* Step 1: coordinate compress */
    int *sorted = (int *)malloc(n * sizeof(int));
    memcpy(sorted, arr, n * sizeof(int));
    qsort(sorted, n, sizeof(int), cmp_val);
    int *rank = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        /* binary search for arr[i] in sorted */
        int lo = 0, hi = n - 1, pos = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (sorted[mid] < arr[i]) { lo = mid + 1; }
            else if (sorted[mid] > arr[i]) { hi = mid - 1; }
            else { pos = mid; break; }
        }
        rank[i] = pos + 1;   
    }
    bit_size = n;
    memset(bit, 0, (n + 1) * sizeof(int));
    for (int i = n - 1; i >= 0; i--) {
        result[i] = (rank[i] > 1) ? bit_query(rank[i] - 1) : 0;
        bit_update(rank[i], 1);
    }

    free(sorted);
    free(rank);
}

/* ═══════════════════════════════════════════════════════════════
 * DRIVER
 * ═══════════════════════════════════════════════════════════════ */

static void print_arr(const char *label, int *a, int n) {
    printf("%s: [", label);
    for (int i = 0; i < n; i++) printf("%d%s", a[i], i < n-1 ? ", " : "");
    printf("]\n");
}

int main(void) {
    printf("=== Count of Smaller Numbers After Self ===\n\n");

    int tests[][8] = {
        {5, 2, 6, 1},
        {3, 4, 9, 6, 1},
        {2, 2, 2, 2},
    };
    int sizes[] = {4, 5, 4};
    int num_tests = 3;

    for (int t = 0; t < num_tests; t++) {
        int n = sizes[t];
        int *arr = tests[t];
        int out_ms[8] = {0}, out_bit[8] = {0};

        count_smaller_merge_sort(arr, n, out_ms);
        count_smaller_bit(arr, n, out_bit);

        printf("Test %d:\n", t + 1);
        print_arr("  Input       ", arr,    n);
        print_arr("  MergeSort   ", out_ms, n);
        print_arr("  Fenwick BIT ", out_bit, n);
        printf("\n");
    }

    return 0;
}
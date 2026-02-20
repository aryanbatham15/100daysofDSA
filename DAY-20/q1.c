#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    long long arr[n];
    for(int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    long long sum = 0, count = 0;

    long long *prefix = (long long*)calloc(200001, sizeof(long long));
    int offset = 100000;

    prefix[offset] = 1;

    for(int i = 0; i < n; i++) {
        sum += arr[i];
        count += prefix[sum + offset];
        prefix[sum + offset]++;
    }

    printf("%lld", count);

    return 0;
}
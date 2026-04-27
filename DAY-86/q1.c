#include <stdio.h>

int main() {
    long long n, low, high, mid, ans;
    scanf("%lld", &n);
    low = 0;
    high = n;
    ans = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (mid * mid == n) {
            printf("%lld\n", mid);
            return 0;
        } else if (mid * mid < n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
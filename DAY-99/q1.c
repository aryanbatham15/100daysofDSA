#include <stdio.h>
#include <stdlib.h>

/* ── Comparator for descending sort by position ── */
typedef struct {
    int position;
    int speed;
} Car;

int cmp_desc(const void *a, const void *b) {
    return ((Car *)b)->position - ((Car *)a)->position;
}
int carFleet(int target, int *position, int posSize, int *speed, int speedSize) {
    if (posSize == 0) return 0;

    /* Build car array */
    Car *cars = (Car *)malloc(posSize * sizeof(Car));
    for (int i = 0; i < posSize; i++) {
        cars[i].position = position[i];
        cars[i].speed    = speed[i];
    }

    /* Sort by position descending (closest to target first) */
    qsort(cars, posSize, sizeof(Car), cmp_desc);

    int fleets = 0;
    double topTime = 0.0;   /* time of the leading fleet */

    for (int i = 0; i < posSize; i++) {
        double time = (double)(target - cars[i].position) / cars[i].speed;

        if (time > topTime) {
            fleets++;
            topTime = time;
        }
        
    }

    free(cars);
    return fleets;
}

/* ── Driver / test harness ── */
int main(void) {
    printf("=== Car Fleet Problem ===\n\n");

    /* ── Test 1 (LeetCode example) ── */
    int pos1[]   = {10, 8, 0, 5, 3};
    int spd1[]   = {2,  4, 1, 1, 3};
    int target1  = 12;
    int n1       = 5;
    printf("Target : %d\n", target1);
    printf("Positions : ");
    for (int i = 0; i < n1; i++) printf("%d ", pos1[i]);
    printf("\nSpeeds    : ");
    for (int i = 0; i < n1; i++) printf("%d ", spd1[i]);
    printf("\nFleets    : %d\n", carFleet(target1, pos1, n1, spd1, n1));

    printf("\n─────────────────────────\n\n");

    /* ── Test 2 ── */
    int pos2[]  = {3};
    int spd2[]  = {3};
    int target2 = 10;
    int n2      = 1;
    printf("Target : %d\n", target2);
    printf("Positions : ");
    for (int i = 0; i < n2; i++) printf("%d ", pos2[i]);
    printf("\nSpeeds    : ");
    for (int i = 0; i < n2; i++) printf("%d ", spd2[i]);
    printf("\nFleets    : %d\n", carFleet(target2, pos2, n2, spd2, n2));

    printf("\n─────────────────────────\n\n");

    /* ── Test 3 ── */
    int pos3[]  = {0, 4, 2};
    int spd3[]  = {2, 1, 3};
    int target3 = 10;
    int n3      = 3;
    printf("Target : %d\n", target3);
    printf("Positions : ");
    for (int i = 0; i < n3; i++) printf("%d ", pos3[i]);
    printf("\nSpeeds    : ");
    for (int i = 0; i < n3; i++) printf("%d ", spd3[i]);
    printf("\nFleets    : %d\n", carFleet(target3, pos3, n3, spd3, n3));

    return 0;
}
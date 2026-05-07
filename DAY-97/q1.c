#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minMeetingRooms(int* start, int startSize, int* end, int endSize) {
    qsort(start, startSize, sizeof(int), compare);
    qsort(end,   endSize,   sizeof(int), compare);

    int rooms = 0, maxRooms = 0;
    int i = 0, j = 0;

    while (i < startSize) {
        if (start[i] < end[j]) { rooms++; i++; }
        else                   { rooms--; j++; }
        if (rooms > maxRooms) maxRooms = rooms;
    }

    return maxRooms;
}

int main() {
    int start[] = {2, 9, 6};
    int end[]   = {4, 12, 10};
    int n = 3;

    printf("Min Rooms: %d\n", minMeetingRooms(start, n, end, n));
    return 0;
}
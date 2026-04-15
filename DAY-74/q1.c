#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    char names[100][50];
    for (int i = 0; i < n; i++) scanf("%s", names[i]);
    
    char unique[100][50];
    int counts[100] = {0};
    int u = 0;
    
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < u; j++) {
            if (strcmp(names[i], unique[j]) == 0) {
                counts[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(unique[u], names[i]);
            counts[u++] = 1;
        }
    }
    
    int maxVotes = 0;
    char winner[50] = "";
    
    for (int i = 0; i < u; i++) {
        if (counts[i] > maxVotes || (counts[i] == maxVotes && strcmp(unique[i], winner) < 0)) {
            maxVotes = counts[i];
            strcpy(winner, unique[i]);
        }
    }
    
    printf("%s %d\n", winner, maxVotes);
    return 0;
}
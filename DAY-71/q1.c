#include <stdio.h>
#include <string.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    int table[m];
    memset(table, -1, sizeof(table));
    
    for (int q = 0; q < n; q++) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);
        
        if (strcmp(op, "INSERT") == 0) {
            for (int i = 0; i < m; i++) {
                int idx = (key + i * i) % m;
                if (table[idx] == -1) {
                    table[idx] = key;
                    break;
                }
            }
        } else {
            int found = 0;
            for (int i = 0; i < m; i++) {
                int idx = (key + i * i) % m;
                if (table[idx] == key) {
                    found = 1;
                    break;
                }
                if (table[idx] == -1) break;
            }
            printf("%s\n", found ? "FOUND" : "NOT FOUND");
        }
    }
    return 0;
}
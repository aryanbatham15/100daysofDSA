#include<stdio.h>
struct Student {
    int id;
    char name[50];
    float average;
};

int main() {
    struct Student s[3];
    int i;

    for(i = 0; i < 3; i++) {
        printf("Enter details of student %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &s[i].id);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("Average: ");
        scanf("%f", &s[i].average);
    }

    printf("\nStudent Details:\n");
    for(i = 0; i < 3; i++) {
        printf("ID: %d, Name: %s, Average: %.2f\n",
               s[i].id, s[i].name, s[i].average);
    }

    return 0;
}

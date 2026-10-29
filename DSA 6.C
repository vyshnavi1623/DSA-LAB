#include <stdio.h>
#define MAX 100
 
struct Element {
    int data;
    int priority; /* lower value = higher priority */
};
 
struct Element pqueue[MAX];
int n = 0;
 
void insert(int data, int priority) {
    if (n == MAX) {
        printf("Priority queue is full.\n");
        return;
    }
    pqueue[n].data = data;
    pqueue[n].priority = priority;
    n++;
    printf("Inserted %d with priority %d.\n", data, priority);
}
 
void deleteHighestPriority() {
    if (n == 0) {
        printf("Priority queue is empty.\n");
        return;
    }
    int highIdx = 0;
    for (int i = 1; i < n; i++) {
        if (pqueue[i].priority < pqueue[highIdx].priority)
            highIdx = i;
    }
    printf("Removed %d (priority %d).\n", pqueue[highIdx].data, pqueue[highIdx].priority);
    for (int i = highIdx; i < n - 1; i++)
        pqueue[i] = pqueue[i + 1];
    n--;
}
 
void display() {
    if (n == 0) {
        printf("Priority queue is empty.\n");
        return;
    }
    printf("Data\tPriority\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\n", pqueue[i].data, pqueue[i].priority);
}
 
int main() {
    int choice, data, priority;
 
    do {
        printf("\n1. Insert\n2. Delete Highest Priority\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                printf("Enter data and priority: ");
                scanf("%d %d", &data, &priority);
                insert(data, priority);
                break;
            case 2:
                deleteHighestPriority();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
 
    return 0;
}

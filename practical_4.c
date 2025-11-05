//Roll no 107
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int value, count = 0;

    printf("Enter elements to add to the linked list (enter 0 to stop):\n");

    while (1) {
        printf("enter data:");
        scanf("%d", &value);
        if (value == 0)
            break;

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        count++;
    }

    
    printf("\nLinked List elements:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d => ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    
    printf("\nTotal number of nodes: %d\n", count);

    return 0;
}

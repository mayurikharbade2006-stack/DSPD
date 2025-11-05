//Rollno 107
#include <stdio.h>
#define MAX 5  
char queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void insert(char element) {
    if (isFull()) {
        printf("\nQueue Overflow! Cannot insert '%c'.\n", element);
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = element;
        printf("Element '%c' inserted into the queue.\n", element);
    }
}

void delete() {
    if (isEmpty()) {
        printf("\nQueue Underflow! No element to delete.\n");
    } else {
        printf("Element '%c' deleted from the queue.\n", queue[front]);
        front++;
        if (front > rear) {  
            front = rear = -1;
        }
    }
}

void display() {
    if (isEmpty()) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nQueue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%c ", queue[i]);
        }
    }
}

int main() {
    int choice;
    char element;
    
    do {
        printf("\n----- QUEUE MENU -----");
        printf("\n1. Insert (Enqueue)");
        printf("\n2. Delete (Dequeue)");
        printf("\n3. Display Queue");
        printf("\n4. Exit");
        printf("\n----------------------");
        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
        
            while (getchar() != '\n');
            printf("Invalid input! Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &element);  
                insert(element);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

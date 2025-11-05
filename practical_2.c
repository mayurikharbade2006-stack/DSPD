//roll no-107
#include <stdio.h>
#include <string.h>
#define MAX 100   

int stack[MAX];
int top = -1;     

void push(int element) {
    if (top == MAX - 1) {
        printf("\nStack Overflow!\n", element);
    } else {
        top++;
        stack[top] = element;
        printf("%d pushed onto the stack.\n", element);
    }
}

void pop() {
    if (top == -1) {
        printf("\nStack Underflow!\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nStack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

void checkPalindrome() {
    char str[100], rev[100];
    int i,len;

    printf("\nEnter a string to check palindrome: ");
    scanf("%s", str);

    len = strlen(str);
    top = -1; 
    for (i = 0; i < len; i++) {
        push(str[i]);
    }

    for (i = 0; i < len; i++) {
        rev[i] = stack[top];
        pop();
    }
    rev[len] = '\0';  

    if (strcmp(str, rev) == 0)
        printf("The string '%s' is a palindrome.\n", str);
    else
        printf("The string '%s' is not a palindrome.\n", str);
}

int main() {
    int choice, element;

    do {
        printf("\n------ STACK MENU ------");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Check Palindrome");
        printf("\n4. Display Stack");
        printf("\n5. Exit");
        printf("\n-------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;

            case 2:
                pop();
                break;

            case 3:
                checkPalindrome();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

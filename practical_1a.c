#include <stdio.h>

int main() {
    int n, i;
    int arr[100];  
    int sumOdd = 0, sumEven = 0;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++) {
        if ((i + 1) % 2 == 0) {
            sumEven += arr[i];  
        } else {
            sumOdd += arr[i];   
        }
    }

    // Step 4: Display results
    printf("\nSum of numbers at ODD positions = %d\n", sumOdd);
    printf("Sum of numbers at EVEN positions = %d\n", sumEven);

    return 0;
}

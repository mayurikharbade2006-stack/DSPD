//Roll no-107
#include <stdio.h>

int main() {
    int n, i, key, start, end, mid, found = 0;

    printf("Enter the range of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nThe array elements are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nEnter the element to search: ");
    scanf("%d", &key);

    start = 0;
    end = n - 1;

    while (start <= end) {
        mid = (start + end) / 2;

        if (arr[mid] == key) {
            printf("\nElement %d found at position %d (index %d).\n", key, mid + 1, mid);
            found = 1;
            break;
        }
        else if (key > arr[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    if (found == 0) {
        printf("\nElement %d not found in the array.\n", key);
    }

    return 0;
}

#include <stdio.h>

#define MAX_SIZE 100  
int main() {
    int arr[MAX_SIZE];  
    int n, choice, pos, element, i;

    printf("Enter the size of the array (up to %d): ", MAX_SIZE);
    scanf("%d", &n);
    if (n > MAX_SIZE || n < 1) {
        printf("Invalid size! Please enter a size between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nArray Operations Menu\n");
        printf("1. Display Array Elements\n");
        printf("2. Insert an Element at a Given Position\n");
        printf("3. Delete an Element at a Given Position\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Array elements:\n");
                printf("Index\tElement\n");
                for (i = 0; i < n; i++) {
                    printf("%d\t%d\n", i, arr[i]);
                }
                break;

            case 2:
               
                if (n >= MAX_SIZE) {
                    printf("Array is full. Cannot insert a new element.\n");
                    break;
                }
                printf("Enter the position to insert (1 to %d): ", n + 1);
                scanf("%d", &pos);
                if (pos < 1 || pos > n + 1) {
                    printf("Invalid position!\n");
                    break;
                }
                printf("Enter the element to insert: ");
                scanf("%d", &element);

                for (i = n; i >= pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos - 1] = element;
                n++;
                printf("Element inserted successfully.\n");
                break;

            case 3:
             
                if (n == 0) {
                    printf("Array is empty. Cannot delete an element.\n");
                    break;
                }
                printf("Enter the position to delete (1 to %d): ", n);
                scanf("%d", &pos);
                if (pos < 1 || pos > n) {
                    printf("Invalid position!\n");
                    break;
                }

                for (i = pos - 1; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                printf("Element deleted successfully.\n");
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

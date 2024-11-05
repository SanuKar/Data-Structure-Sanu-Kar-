#include <stdio.h>
#include <stdlib.h>


void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
int linearSearch(int arr[], int n, int key);
void displaySparseMatrix(int rows, int cols, int sparse[][3]);
void generateFibonacci(int n);
long long factorial(int n);

int main() {
    int choice;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Quick Sort\n");
        printf("2. Linear Search\n");
        printf("3. Display Sparse Matrix\n");
        printf("4. Generate Fibonacci Numbers\n");
        printf("5. Calculate Factorial\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int n;
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                int arr[n];
                printf("Enter the elements:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                quickSort(arr, 0, n - 1);
                printf("Sorted array:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 2: {
                int n, key;
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                int arr[n];
                printf("Enter the elements:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                printf("Enter the element to search for: ");
                scanf("%d", &key);
                int result = linearSearch(arr, n, key);
                if (result != -1) {
                    printf("Element found at index: %d\n", result);
                } else {
                    printf("Element not found.\n");
                }
                break;
            }
            case 3: {
                int sparse[100][3], rows, cols, nonZeroCount = 0;
                printf("Enter the number of rows and columns of the matrix: ");
                scanf("%d %d", &rows, &cols);
                printf("Enter the sparse matrix (enter non-zero elements with their row, column and value):\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        int value;
                        scanf("%d", &value);
                        if (value != 0) {
                            sparse[nonZeroCount][0] = i;
                            sparse[nonZeroCount][1] = j;
                            sparse[nonZeroCount][2] = value;
                            nonZeroCount++;
                        }
                    }
                }
                sparse[nonZeroCount][0] = rows;
                sparse[nonZeroCount][1] = cols;
                sparse[nonZeroCount][2] = nonZeroCount;
                printf("Sparse Matrix Representation:\n");
                displaySparseMatrix(nonZeroCount + 1, 3, sparse);
                break;
            }
            case 4: {
                int n;
                printf("Enter the number of Fibonacci numbers to generate: ");
                scanf("%d", &n);
                printf("Fibonacci Series:\n");
                generateFibonacci(n);
                break;
            }
            case 5: {
                int n;
                printf("Enter a number to calculate its factorial: ");
                scanf("%d", &n);
                if (n < 0) {
                    printf("Factorial is not defined for negative numbers.\n");
                } else {
                    printf("Factorial of %d is %lld\n", n, factorial(n));
                }
                break;
            }
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}


int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1; 
}


void displaySparseMatrix(int rows, int cols, int sparse[][3]) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < rows; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}


void generateFibonacci(int n) {
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        int next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}


long long factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

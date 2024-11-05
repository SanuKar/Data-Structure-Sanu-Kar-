#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

char queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(char item) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue Overflow\n");
        return;
    } else if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear] = item;
}

char dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return -1;
    } else if (front == rear) {
        char item = queue[front];
        front = rear = -1;
        return item;
    } else {
        char item = queue[front];
        front = (front + 1) % MAX_SIZE;
        return item;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        int i = front;
        do {
            printf("%c ", queue[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int main() {
    int choice;
    char item;

    do {
        printf("\nMenu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf(" %c", &item);
                enqueue(item);
                break;
            case 2:
                item = dequeue();
                if (item != -1) {
                    printf("Dequeued element: %c\n", item);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void createList(int n) {
    struct Node* newNode, *temp;
    int data, i;

    for (i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtAnyPosition(int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1) {
        insertAtBeginning(data);
    } else {
        struct Node* temp = head;
        for (int i = 1; i < position - 1; i++) {
            if (temp == NULL) {
                printf("Position out of range\n");
                return;
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp = head;
        if (temp->next == NULL) {
            free(temp);
            head = NULL;
        } else {
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            free(temp->next);
            temp->next = NULL;
        }
    }
}

void deleteAfter(int position) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp = head;
        for (int i = 1; i < position; i++) {
            if (temp == NULL) {
                printf("Position out of range\n");
                return;
            }
            temp = temp->next;
        }

        struct Node* temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
}

void search(int data) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("Element found at position %d\n", position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element not found\n");
}

void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, n, data, position;

    do {
        printf("\nMenu\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at any Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete after a Position\n");
        printf("8. Search for an Element\n");
        printf("9. Display List\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 4:
                printf("Enter data to insert and position: ");
                scanf("%d %d", &data, &position);
                insertAtAnyPosition(data, position);
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                printf("Enter the position after which to delete: ");
                scanf("%d", &position);
                deleteAfter(position);
                break;
            case 8:
                printf("Enter the element to search: ");
                scanf("%d", &data);
                search(data);
                break;
            case 9:
                display();
                break;
            case 10:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 10);

    return 0;
}
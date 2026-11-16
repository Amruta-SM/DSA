#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;


struct Node *front = NULL;
struct Node *rear = NULL;


void push(int value) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed into Stack\n", value);
}


void pop() {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }

    temp = top;
    printf("Popped element: %d\n", temp->data);

    top = top->next;
    free(temp);
}


void displayStack() {
    struct Node *temp = top;

    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}


void enqueue(int value) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted into Queue\n", value);
}


void dequeue() {
    struct Node *temp;

    if (front == NULL) {
        printf("Queue Underflow!\n");
        return;
    }

    temp = front;

    printf("Deleted element: %d\n", temp->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}


void displayQueue() {
    struct Node *temp = front;

    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}


int main() {
    int choice, value;

    while (1) {
        printf("\n===== MAIN MENU =====\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\n--- STACK MENU ---\n");
                printf("1. PUSH\n");
                printf("2. POP\n");
                printf("3. DISPLAY\n");

                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Enter value: ");
                        scanf("%d", &value);
                        push(value);
                        break;

                    case 2:
                        pop();
                        break;

                    case 3:
                        displayStack();
                        break;

                    default:
                        printf("Invalid choice!\n");
                }
                break;

            case 2:
                printf("\n--- QUEUE MENU ---\n");
                printf("1. ENQUEUE\n");
                printf("2. DEQUEUE\n");
                printf("3. DISPLAY\n");

                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Enter value: ");
                        scanf("%d", &value);
                        enqueue(value);
                        break;

                    case 2:
                        dequeue();
                        break;

                    case 3:
                        displayQueue();
                        break;

                    default:
                        printf("Invalid choice!\n");
                }
                break;

            case 3:
                printf("Program Terminated.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

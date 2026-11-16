#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};


struct Node* createNode(int data) {
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}


struct Node* insert(struct Node *head, int data) {
    struct Node *newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    return head;
}


void display(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}


void sortList(struct Node *head) {
    struct Node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}


struct Node* reverseList(struct Node *head) {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}


struct Node* concatenate(struct Node *head1,
                         struct Node *head2) {
    if (head1 == NULL)
        return head2;

    struct Node *temp = head1;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;

    return head1;
}


int main() {
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    int n, m, i, data;


    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);

    printf("Enter elements of first list:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        head1 = insert(head1, data);
    }


    printf("Enter number of nodes in second list: ");
    scanf("%d", &m);

    printf("Enter elements of second list:\n");

    for (i = 0; i < m; i++) {
        scanf("%d", &data);
        head2 = insert(head2, data);
    }

    printf("\nFirst Linked List:\n");
    display(head1);

    printf("\nSecond Linked List:\n");
    display(head2);


    sortList(head1);
    printf("\nSorted First Linked List:\n");
    display(head1);


    head1 = reverseList(head1);
    printf("\nReversed First Linked List:\n");
    display(head1);


    head1 = concatenate(head1, head2);
    printf("\nConcatenated Linked List:\n");
    display(head1);

    return 0;
}

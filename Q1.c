#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
int findMiddle(struct Node* head) {
    int count = countNodes(head);  // Step 1: Count the nodes
    int midIndex = count / 2;      // Step 2: Calculate the middle index
    struct Node* current = head;

    // Step 3: Traverse again to the middle node
    for (int i = 0; i < midIndex; i++) {
        current = current->next;
    }
    return current->data;
}
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Linked list: ");
    printList(head);

    int middle = findMiddle(head);
    printf("Middle of the linked list: %d\n", middle);

    insertAtEnd(&head, 6);
    printf("\nLinked list: ");
    printList(head);

    middle = findMiddle(head);
    printf("Middle of the linked list: %d\n", middle);

    return 0;
}

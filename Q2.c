#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enQueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
        rear->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    printf("%d enqueued to queue\n", value);
}

void deQueue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    if (front == rear) {
        free(front);
        front = rear = NULL;
    } else {
        struct Node* temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }
    printf("Element dequeued from queue\n");
}

void displayFront() {
    if (front != NULL)
        printf("Front item is %d\n", front->data);
    else
        printf("Queue is empty\n");
}

void displayRear() {
    if (rear != NULL)
        printf("Rear item is %d\n", rear->data);
    else
        printf("Queue is empty\n");
}

int main() {
    enQueue(10);
    enQueue(20);
    enQueue(30);

    displayFront();
    displayRear();

    deQueue();
    deQueue();

    displayFront();
    displayRear();

    return 0;
}

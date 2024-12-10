#include<stdio.h>
#include<stdlib.h>

// Define the structure for the queue node
struct node {
    int data;         // Data to be stored in the node
    struct node *next;  // Pointer to the next node in the queue
};

// Define the global queue structure, containing front and rear pointers
struct node *front = NULL, *rear = NULL;

// Enqueue function to add an element to the rear of the queue
void enqueue() {
    int value;
    printf("Enter a value to insert:");
    scanf("%d",&value);
    // Create a new node for the value
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;  // The next pointer of the new node will be NULL

    if (rear == NULL) {  // If the queue is empty, both front and rear will point to the new node
        front = rear = newNode;
    } else {
        rear->next = newNode;  // Link the current rear node to the new node
        rear = newNode;  // Update the rear to point to the new node
    }

    printf("Enqueued %d to the queue.\n", value);
}

// Dequeue function to remove an element from the front of the queue
void dequeue() {
    if (front == NULL) {  // If the queue is empty
        printf("Queue underflow: Queue is empty!\n");
        return;
    }

    struct node *temp = front;  // Temporary pointer to the front node
    front = front->next;  // Update the front pointer to the next node

    // If the front becomes NULL, the queue is empty, so set rear to NULL as well
    if (front == NULL) {
        rear = NULL;
    }

    printf("Dequeued %d from the queue.\n", temp->data);
    free(temp);  // Free the memory of the dequeued node
}

// Peek function to see the front element of the queue
void peek() {
    if (front == NULL) {  // If the queue is empty
        printf("Queue underflow: Queue is empty!\n");
    } else {
        printf("Front element is: %d\n", front->data);
    }
}

// Display function to show all elements in the queue
void display() {
    if (front == NULL) {  // If the queue is empty
        printf("Queue is empty!\n");
        return;
    }

    struct node *temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {  // Traverse through the queue and print each element
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (choice!=4)
    {
        printf("\n---Queue operations---\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("\nEnter your choice(1/2/3/4):");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("Exit!!");
            break;
            default:
            printf("Invalid input!!");
            break;
        }
    }
}

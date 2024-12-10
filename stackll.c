#include<stdio.h>
#include<stdlib.h>
void main() {
    int i, val, ch, count = 0;
    // Node structure for stack
    struct node {
        int data;
        struct node *next;
    };

    struct node *top = NULL;

    // Push function to add an element to the stack
    void push() {
        printf("Enter the value to insert: ");
        scanf("%d", &val);

        // Allocate memory for new node
        struct node* newnode = (struct node*) malloc(sizeof(struct node));

        if (newnode == NULL) {  // Check for memory allocation failure
            printf("Memory allocation failed! Stack overflow.\n");
            return;
        }

        newnode->data = val;
        newnode->next = top;  // Link new node to the current top
        top = newnode;  // Update top to point to the new node

        count++;
        printf("New value pushed to the stack!\n");
    }

    // Pop function to remove the top element from the stack
    void pop() {
        if (top == NULL) {  // Check for empty stack
            printf("Stack underflow: Stack is empty!\n");
            exit(1);
        } else {
            struct node* temp = top;
            top = top->next;  // Update top to the next node
            free(temp);  // Free the memory of the popped node
            count--;
            printf("Value popped!!");
        }
    }

    // Peek function to show the top element of the stack
    void peek() {
        if (top == NULL) {
            printf("Stack underflow: Stack is empty!\n");
        } else {
            printf("Top element of the stack is: %d\n", top->data);
        }
    }

    // Display function to print all elements in the stack
    void display() {
        struct node* temp = top;

        if (count == 0) {
            printf("Stack underflow: Stack is empty!\n");
        } else {
            printf("Printing the stack:\n");
            while (temp != NULL) {
                printf("%d, ", temp->data);
                temp = temp->next;
            }
            printf("\n");
        }
    }

    // Main loop for stack operations
    while (ch!=5)
    {
       printf("\n---Stack operations using Linked List---\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("\nEnter your choice(1/2/3/4/5):");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exit!!");
                break;
            default:
                printf("Invalid input!!");
                break;
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *next;
} *head = NULL, *temp = NULL, *next = NULL;

// Function declarations
void insert();
void insert1();
void insert2();
void insert3();
void delete();
void delete1();
void delete2();
void delete3();
void search();
void display();

int main() {
    int ch = 0;

    while (ch != 5) {
        // Display the main menu
        printf("\nEnter the linked list operation to perform:\n");
        printf("1. Display\n2. Insert\n3. Delete\n4. Search\n5. Exit\n");
        printf("Enter your choice (1/2/3/4/5): ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                display();
                break;
            case 2:
                insert();
                break;
            case 3:
                delete();
                break;
            case 4:
                search();
                break;
            case 5:
                printf("Exit!!\n");
                return 0;
            default:
                printf("Invalid input\n");
        }
    }
}

// Insert a new node
void insert() {
    int ch1, val;
    printf("Enter the value to insert: ");
    scanf("%d", &val);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;

    printf("\nChoose the type of insertion:\n1. Insert at beginning\n2. Insert at a position\n3. Insert at the end\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &ch1);

    switch (ch1) {
        case 1:
            insert1(newnode);
            break;
        case 2:
            insert2(newnode);
            break;
        case 3:
            insert3(newnode);
            break;
        default:
            printf("Invalid choice.\n");
            free(newnode);
    }
}

// Insert at the beginning
void insert1(struct node* newnode) {
    newnode->next = head;
    head = newnode;
    printf("Node inserted at the beginning.\n");
}

// Insert at a specific position
void insert2(struct node* newnode) {
    int pos, i = 1;
    printf("Enter the position to insert the element: ");
    scanf("%d", &pos);

    if (pos == 1) {
        insert1(newnode);
        return;
    }

    temp = head;
    while (temp != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    printf("Node inserted at position %d.\n", pos);
}

// Insert at the end
void insert3(struct node* newnode) {
    if (head == NULL) {
        head = newnode;
        printf("Node inserted as the first element.\n");
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
    printf("Node inserted at the end.\n");
}

// Delete a node
void delete() {
    int ch2;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\nChoose the type of deletion:\n1. Delete from beginning\n2. Delete from a position\n3. Delete from the end\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &ch2);

    switch (ch2) {
        case 1:
            delete1();
            break;
        case 2:
            delete2();
            break;
        case 3:
            delete3();
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// Delete from the beginning
void delete1() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from the beginning.\n");
}

// Delete from a specific position
void delete2() {
    int pos, i = 1;
    printf("Enter the position to delete the element: ");
    scanf("%d", &pos);

    if (pos == 1) {
        delete1();
        return;
    }

    temp = head;
    while (temp != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    next = temp->next->next;
    free(temp->next);
    temp->next = next;
    printf("Node deleted from position %d.\n", pos);
}

// Delete from the end
void delete3() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    if (temp->next == NULL) {
        free(temp);
        head = NULL;
        printf("Node deleted from the end.\n");
        return;
    }

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    printf("Node deleted from the end.\n");
}

// Search for an element
void search() {
    int val;
    printf("Enter the element to search: ");
    scanf("%d", &val);

    temp = head;
    while (temp != NULL) {
        if (temp->data == val) {
            printf("Element found at position %d,\n");
            return;
        }
        temp = temp->next;
    }
    printf("Element not found.\n");
}

// Display the list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}

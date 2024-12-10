#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *end = NULL, *temp = NULL;

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

// Main function
int main() {
    int ch = 0;

    while (ch != 5) {
        // Display the main menu
        printf("\nEnter the linked list operation to be performed:\n");
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

// Insert function
void insert() {
    int ch1 = 0;
    int val;
    printf("Enter the data to insert: ");
    scanf("%d", &val);
    
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = val;
    node->next = NULL;
    node->prev = NULL;

    // Display the submenu for position
    printf("\nEnter the position:\n");
    printf("1. Beginning\n2. In between\n3. End\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &ch1);

    switch (ch1) {
        case 1:
            insert1(node);
            break;
        case 2:
            insert2(node);
            break;
        case 3:
            insert3(node);
            break;
        default:
            printf("Invalid position!\n");
    }
}

// Insert at the beginning
void insert1(struct node *node) {
    node->next = head;
    node->prev = NULL;
    
    if (head != NULL) {
        head->prev = node;
    } else {
        end = node;  // If the list is empty, end will also point to the new node
    }
    head = node;
}

// Insert in between
void insert2(struct node *node) {
    int pos;
    printf("Enter the position to insert the value: ");
    scanf("%d", &pos);

    if (pos == 1) {
        insert1(node);
        return;
    }

    temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Position out of range!\n");
            return;
        }
        temp = temp->next;
    }

    node->next = temp->next;
    node->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = node;
    }
    temp->next = node;
}

// Insert at the end
void insert3(struct node *node) {
    if (head == NULL) {
        insert1(node);  // If the list is empty, insert at the beginning
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = node;
    node->prev = temp;
    end = node;  // Update the end pointer
}

// Delete function
void delete() {
    int ch1 = 0;
    int val;
    printf("Enter the data to delete: ");
    scanf("%d", &val);

    struct node *node;
    temp = head;
    
    // Find the node with the given value
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in the list!\n");
        return;
    }

    // Display the submenu for position
    printf("\nEnter the position to delete:\n");
    printf("1. Beginning\n2. In between\n3. End\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &ch1);

    switch (ch1) {
        case 1:
            delete1(temp);
            break;
        case 2:
            delete2(temp);
            break;
        case 3:
            delete3(temp);
            break;
        default:
            printf("Invalid position!\n");
    }
}

// Delete at the beginning
void delete1(struct node *node) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    head = node->next;
    if (head != NULL) {
        head->prev = NULL;
    } else {
        end = NULL;  // If the list becomes empty
    }
    free(node);
}

// Delete in between
void delete2(struct node *node) {
    if (node == NULL) return;

    if (node->prev != NULL) {
        node->prev->next = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
    free(node);
}

// Delete at the end
void delete3(struct node *node) {
    if (end == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (node == end) {
        end = node->prev;
        if (end != NULL) {
            end->next = NULL;
        } else {
            head = NULL;  // If the list becomes empty
        }
        free(node);
    }
}

// Display the linked list
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Search function (optional)
void search() {
    int val;
    printf("Enter value to search: ");
    scanf("%d", &val);
    
    temp = head;
    while (temp != NULL) {
        if (temp->data == val) {
            printf("Value %d found in the list.\n", val);
            return;
        }
        temp = temp->next;
    }
    printf("Value %d not found in the list.\n", val);
}
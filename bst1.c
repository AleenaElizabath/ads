#include <stdio.h>
#include <stdlib.h>

// Definition of the structure for a tree node
typedef struct Node {
    int data;           // Data stored in the node
    struct Node *left;  // Pointer to the left child
    struct Node *right; // Pointer to the right child
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for new node
    newNode->data = data;  // Set the data
    newNode->left = NULL;   // Left child is initially NULL
    newNode->right = NULL;  // Right child is initially NULL
    return newNode;
}

// Function to insert a new value into the BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        // If the tree is empty, create a new node and return it as the root
        return createNode(data);
    }

    if (data < root->data) {
        // If the value is smaller, insert in the left subtree
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        // If the value is larger, insert in the right subtree
        root->right = insert(root->right, data);
    }
    
    // Return the unchanged root pointer
    return root;
}

// Function to search for a value in the BST
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root; // If the node is NULL or the data is found, return the node
    }

    // If the data is smaller, search in the left subtree
    if (data < root->data) {
        return search(root->left, data);
    }

    // Otherwise, search in the right subtree
    return search(root->right, data);
}

// Function to perform in-order traversal of the BST
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);  // Visit the left child
        printf("%d ", root->data);     // Visit the root
        inorderTraversal(root->right); // Visit the right child
    }
}

// Function to find the minimum value node in a BST
Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;  // Keep moving to the left child
    }
    return root;  // The leftmost node is the minimum
}

// Function to delete a node from the BST
Node* delete(Node* root, int data) {
    if (root == NULL) {
        return root;  // If the tree is empty, return NULL
    }

    // If the value to be deleted is smaller than the root's data, it lies in the left subtree
    if (data < root->data) {
        root->left = delete(root->left, data);
    }
    // If the value to be deleted is greater than the root's data, it lies in the right subtree
    else if (data > root->data) {
        root->right = delete(root->right, data);
    }
    // If the value to be deleted is the same as the root's data, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = delete(root->right, temp->data);
    }

    return root;
}

// Function to free all nodes of the BST
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);  // Free the current node
    }
}

int main() {
    Node* root = NULL;  // Initialize an empty tree
    int numValues, value;

    // Ask the user for the number of nodes to insert
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &numValues);

    // Insert nodes into the BST
    for (int i = 0; i < numValues; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);  // Insert each value into the BST
    }

    // Perform in-order traversal (should print sorted order)
    printf("In-order Traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a node in the BST
    printf("Enter value to search: ");
    scanf("%d", &value);
    Node* result = search(root, value);
    if (result != NULL) {
        printf("Node with value %d found in the tree.\n", value);
    } else {
        printf("Node with value %d not found in the tree.\n", value);
    }

    // Delete a node from the BST
    printf("Enter value to delete: ");
    scanf("%d", &value);
    root = delete(root, value);
    printf("In-order Traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    // Free all the memory used by the BST
    freeTree(root);

    return 0;
}

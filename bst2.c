#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *tree = NULL;

void search(struct node *tree, int val);
void insert(struct node **tree, int val);
void delete(struct node **tree, int val);
struct node *findLargestNode(struct node *root);
void inorder(struct node *tree);

int main()
{
    int choice, val;

    while (1)
    {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display Inorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insert(&tree, val);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            delete(&tree, val);
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &val);
            search(tree, val);
            break;
        case 4:
            printf("Inorder Traversal: ");
            inorder(tree);
            printf("\n");
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

void search(struct node *tree, int val)
{
    int depth = 0;
    struct node *temp = tree;
    while (temp != NULL)
    {
        depth++;
        if (temp->data == val)
        {
            printf("Item found at depth %d\n", depth);
            return;
        }
        else if (temp->data > val)
            temp = temp->left;
        else
            temp = temp->right;
    }
    printf("Item not found\n");
}

void insert(struct node **tree, int val)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;

    if (*tree == NULL)
    {
        *tree = new_node;
        return;
    }

    struct node *current = *tree;
    struct node *parent = NULL;

    while (current != NULL)
    {
        parent = current;
        if (val < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (val < parent->data)
        parent->left = new_node;
    else
        parent->right = new_node;
}

void delete(struct node **tree, int val)
{
    if (*tree == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    struct node *current = *tree;
    struct node *parent = NULL;

    while (current != NULL && current->data != val)
    {
        parent = current;
        if (val < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (current == NULL)
    {
        printf("Item not found\n");
        return;
    }

    if (current->left == NULL && current->right == NULL)
    {
        if (parent == NULL)
            *tree = NULL;
        else if (parent->left == current)
            parent->left = NULL;
        else
            parent->right = NULL;
        free(current);
    }
    else if (current->left == NULL)
    {
        if (parent->left == current)
            parent->left = current->right;
        else
            parent->right = current->right;
        free(current);
    }
    else if (current->right == NULL)
    {
        if (parent->left == current)
            parent->left = current->left;
        else
            parent->right = current->left;
        free(current);
    }
    else
    {
        struct node *temp = findLargestNode(current->left);
        current->data = temp->data;
        delete(&(current->left), temp->data);
    }
}

struct node *findLargestNode(struct node *root)
{
    struct node *current = root;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current;
}

void inorder(struct node *tree)
{
    if (tree != NULL)
    {
        inorder(tree->left);
        printf("%d ", tree->data);
        inorder(tree->right);
    }
}
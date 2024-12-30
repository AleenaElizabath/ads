#include <stdio.h>
#include <stdlib.h>

int MAX = 10, rear = -1, front = -1;
int a[10];  // Array to hold the queue for BFS traversal

// Function to enqueue (add) a node to the queue
void Enqueue(int n)
{
    // Check if the queue is full
    if (rear == MAX - 1)
        return;  // If the queue is full, return without adding the node

    // If the queue is empty, set front to 0
    if (rear == -1)
        front = 0;
    
    rear++;  // Move the rear pointer to the next position
    a[rear] = n;  // Add the node to the queue
}

// Function to dequeue (remove) a node from the queue
int Dequeue()
{
    // Check if the queue is empty
    if (front == -1)
        return -1;  // If the queue is empty, return -1

    // Get the node at the front of the queue
    int v = a[front];
    front++;  // Move the front pointer to the next position
    return v;  // Return the dequeued node
}

void main()
{
    int n, start;

    // Prompt the user to enter the number of nodes in the graph
    printf("Enter number of nodes: ");
    scanf("%d", &n);  // Read the number of nodes from the user

    int a[n][n], v[n];  // Adjacency matrix and visited array for BFS

    // Prompt the user to enter the adjacency matrix for the graph
    printf("Enter Adjacency matrix for the graph: ");
    for (int i = 0; i < n; i++)  // Loop through each row of the matrix
    {
        v[i] = 0;  // Initialize all nodes as unvisited
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);  // Read each element of the adjacency matrix
    }

    // Prompt the user to enter the starting node for BFS
    printf("Enter starting node (0-%d): ", (n - 1));
    scanf("%d", &start);  // Read the starting node from the user

    // Output the BFS traversal result
    printf("\nBFS Traversal: ");
    
    // Enqueue the starting node and mark it as visited
    Enqueue(start);
    v[start] = 1;

    // Perform BFS traversal while there are nodes in the queue
    while (front <= rear)  // While the queue is not empty
    {
        // Dequeue the front node from the queue
        start = Dequeue();
        
        // Print the current node (visited node)
        printf("%d ", start);

        // Explore all neighbors of the current node
        for (int i = 0; i < n; i++)  // Loop through all nodes to check adjacency
        {
            // If there's an edge to node `i` and it has not been visited
            if (a[start][i] == 1 && v[i] == 0)
            {
                // Enqueue the neighboring node and mark it as visited
                Enqueue(i);
                v[i] = 1;
            }
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

void dfs(int n, int a[n][n], int v[], int node) {
    // If the node is not visited
    if (v[node] != 1) {
        // Print the current node
        printf("%d ", node);
        // Mark the node as visited
        v[node] = 1;
        
        // Recurse for all the adjacent vertices
        for (int i = 0; i < n; i++) {
            if (a[node][i] == 1 && v[i] == 0) {
                dfs(n, a, v, i);
            }
        }
    }
}

int main() {
    int n, start;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    int a[n][n], v[n]; // Adjacency matrix and visited array
    
    printf("Enter Adjacency matrix for the graph:\n");
    for (int i = 0; i < n; i++) {    
        v[i] = 0; // Initialize visited array to 0 (not visited)
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("Enter starting node (0-%d): ", n - 1);
    scanf("%d", &start);
    
    // Check if the starting node is within the valid range
    if (start < 0 || start >= n) {
        printf("Invalid starting node.\n");
        return 1;
    }
    
    printf("\nDFS Traversal: ");
    dfs(n, a, v, start);
    
    return 0;
}

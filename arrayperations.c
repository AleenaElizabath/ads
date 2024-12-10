#include<stdio.h>
void main() {
    printf("ARRAY CREATION\n");
    printf("Enter the size of the array:");
    int i, num, j, ch;
    scanf("%d", &num);  // Take the size of the array from the user
    // Declare an array of size 100
    int arr[100];
    // Prompt the user to input elements into the array
    printf("Enter %d Elements of the array:", num);
    for (i = 0; i < num; i++) {
        scanf("%d", &arr[i]);  // Read elements into the array
    }
    // Function to display the elements of the array
    void display() {
        printf("Displaying the array:\n");
        for (i = 0; i < num; i++) {
            printf("%d, ", arr[i]);  // Print each element of the array
        }
        printf("\n");
    }
    // Function to search for a value in the array
    void search() {
        int val, flag = 0;
        printf("Enter the value to search: ");
        scanf("%d", &val);  // Take the value to search from the user
        // Loop through the array to find the value
        for (i = 0; i < num; i++) {
            if (arr[i] == val) {
                flag = 1;  // Set flag to 1 if value is found
                break;     // Exit the loop once value is found
            }
        }
        // Print the result of the search
        if (flag == 1) {
            printf("The array element %d found at position %d\n", val, i + 1);  // Print position (1-based index)
        } else {
            printf("Element not found\n");  // If the element wasn't found
        }
    }
    // Function to sort the array in ascending order
    void sort() {
        int k;
        // Perform a simple bubble sort algorithm
        for (i = 0; i < num - 1; i++) {
            for (j = i + 1; j < num; j++) {
                if (arr[i] > arr[j]) {
                    // Swap elements if they are in the wrong order
                    k = arr[j];
                    arr[j] = arr[i];
                    arr[i] = k;
                }
            }
        }
        printf("Array sorted\n");
    }
    // Function to delete an element from the array
    void delete() {
        int val,pos;
        // Check if the array is empty
        if (num == 0) {
            printf("Array is empty\n");
            return;  // Exit the function if the array is empty
        }   
        printf("Enter a value to delete: ");
        scanf("%d", &val);  // Take the value to delete
        printf("Enter the position of the value to delete: ");
        scanf("%d", &pos);  // Take the position of the element to delete
        // Validate the position (it should be within the current array size)
        if (pos < 1 || pos > num) {
            printf("Invalid position.\n");
            return;  // Exit if the position is invalid
        }
        for (i = pos - 1; i < num - 1; i++) {
                arr[i] = arr[i + 1];  // Shift elements left
            }
            num--;  // Reduce the array size
            printf("Element %d deleted from position %d\n", val, pos);
    }
    // Function to insert an element at a specified position
    void insert() {
        int val, pos, c;
        printf("Enter the position of the new element: ");
        scanf("%d", &pos);  // Take the position where the new element should be inserted
        printf("Enter the value: ");
        scanf("%d", &val);  // Take the value to insert

        // Increase the number of elements in the array
        num++;
        // Shift elements to the right to make space for the new element
        for (c = num - 1; c >= pos; c--) {
            arr[c] = arr[c - 1];
        }
        // Insert the new value at the given position (1-based index)
        arr[pos - 1] = val;
    }
    // Menu-driven program to perform array operations
    while (ch!=6)
    {
        // Display the menu
        printf("\nEnter the array operation to perform:\n1.Display\n2.Insert\n3.Delete\n4.Sort\n5.Search\n6.Exit\n");
        printf("Enter your choice (1/2/3/4/5/6): ");
        scanf("%d", &ch);  // Take user input for the operation choice
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
                sort();    
                break;
            case 5:
                search();   
                break;
            case 6:
                printf("Exit!\n");
                return;
            default:
                printf("Invalid input\n");
                break;
        }
    }
}

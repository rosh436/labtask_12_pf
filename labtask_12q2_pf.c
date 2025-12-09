#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, newSize, i;
    char choice;
    printf("Enter the number of integers you want to store: ");               // Ask user for initial array size
    scanf("%d", &size);
    int *arr = calloc(size, sizeof(int));
    
    if (arr == NULL) {                                               // Allocate memory using calloc() so values start at 0
        printf("Memory allocation failed!\n");
        return 0;
    }
    printf("\nInitial values in the array:\n");                    // Display initial values (all zero because of calloc)
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
 
    printf("\nDo you want to add more elements? (y/n): ");             // Ask user whether to enlarge array
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        printf("Enter the new size of the array: ");          // Ask for the new size
        scanf("%d", &newSize);
        int *temp = realloc(arr, newSize * sizeof(int));       // reallocate memory
        if(temp == NULL) {
            printf("Memory reallocation failed!\n");
            free(arr);
            return 0;
        }
        arr = temp; 
        printf("\nEnter %d new elements:\n", newSize - size);    //eneter new elements
        for (i = size; i < newSize; i++) {
            scanf("%d", &arr[i]);
        }
        printf("\nUpdated array values:\n");      //lets display the updated array
        for (i = 0; i < newSize; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("\nNo changes made. Exiting program...\n");
    }
    // Free allocated memory
    free(arr);
    getchar();
    getchar();
    return 0;
}


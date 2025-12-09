/*Write a C program that uses to store a list of integers entered by the user. The program 
should first ask the user how many elements they want to store, then allocate memory using 
malloc() according to the provided size. After allocating memory, take all elements from the 
user and store them in the dynamically created array. Then print the array elements using a loop.
Also include proper checks such as verifying if malloc() successfully allocated memory or not. 
Finally, before ending the program, free all the dynamically allocated memory using free() to 
avoid memory leaks. Add helpful messages for user interaction and use clear comments in your code*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int size, i;
    printf("Enter the no of integers you want to store: ");
    scanf("%d", &size);          //size that would be allocated
    int *arr = malloc(size * sizeof(int));
    if(arr == NULL){
        printf("Memory allocation failed!");     //when the arr is null, the allocation failed, exit program
        return 0;
    }
    printf("Enter the numbers: ");
    for(i = 0; i < size; i++){
        scanf("%d", &arr[i]);     //take input from user
    }
    printf("----Integers----\n");
    for(i = 0; i < size; i++){
        printf("%d\n", arr[i]);      //print the integers using loop
    }   
    free(arr);                     //free the array after all the work
    getchar();
    getchar();
    return 0;
}                                                                                                    

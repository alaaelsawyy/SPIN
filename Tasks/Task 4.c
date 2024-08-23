// 1. Write a C program to print all negative elements in an array
#include <stdio.h>

int main()
{
int n,i;

printf("Enter the number of elements you want to read:\n");
scanf("%i",&n);

int arr[n];
printf("\nEnter %d elements:\n", n);
for (i = 0; i < n; i++){
    scanf("%i",&arr[i]);
}

 printf("\nNegative elements: ");
for (int i = 0; i < n; i++) {
     if (arr[i] < 0) {
    printf("\n%d ", arr[i]);
        }
    }    
    
    return 0;
}




// 2. Write a C program to find maximum and minimum element in an array
#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);

    int arr[n];

    printf("\nEnter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    int min = arr[0];

    // Iterate through the array to find the max and min
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];       // If the current element is greater than max, it updates max.
        }
        if (arr[i] < min) {
            min = arr[i];      // If the current element is less than min, it updates min.
        }
    }

    printf("\nMaximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    return 0; 
}




// 3. Write a. program in C to find the sum of all elements of the array
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements you want to read:\n ");
    scanf("%d", &n);

    int arr[n], sum = 0;

    printf("\nEnter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }

    printf("\nSum of all elements: %d\n", sum);

    return 0;
}




// 4. Write a program in C to copy the elements of one array into another array.
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements you want to read:\n ");
    scanf("%d", &n);

    int arr1[n], arr2[n];

    printf("\nEnter %d elements for array 1:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    for (int i = 0; i < n; i++) {         // to copy all elements
        arr2[i] = arr1[i];           
    }

    printf("\nElements of array 2 (copied from array 1):");
    for (int i = 0; i < n; i++) {
        printf("\n%d ", arr2[i]);
    }

    return 0;
}





/* 5. Write a program in C to read n number of values in an array and
display it in reverse order. Where n_max=100.*/
#include<stdio.h>

int main(){
int arr [100];
int n;

printf("Enter the number of values you want to read: max(100):\n ");
scanf("%i",&n);

if (n < 1 || n > 100) {
printf("Invalid number of values. Please enter a number between 1 and 100:\n");
}

else{ 
printf("Enter %d values:\n", n);       
for (int i = 0; i < n; i++) {
scanf("\n%d", &arr[i]);
}
}

printf("Values in reverse order:\n");
for (int i = n - 1; i >= 0; i--) {
printf("%d \n", arr[i]);
    }
return 0;
}




// 6. Write a C program to add two 3*4 matrices
#include <stdio.h>

#define ROWS 3
#define COLS 4

int main() {
    // Define and initialize the matrices
    int matrix1[ROWS][COLS] = {
        {1, 2, 3, 4},
        {3, 4, 5, 6},
        {5, 6, 7, 8}
    };

    int matrix2[ROWS][COLS];

    // Copy matrix1 to matrix2
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix2[i][j] = matrix1[i][j]; 
        }
    }

    int summation[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            summation[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
      printf("Matrix1 + Matrix2 = \n\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", summation[i][j]);
        }
        printf("\n");
    }

    return 0;
}




// 7. Write a c program to find the maximum and the minimum of a given 3*4 array
#include <stdio.h>

#define ROWS 3
#define COLS 4

int main() {
    
    int arr[ROWS][COLS] = {
        {1, 2, 3, 4},
        {3, 4, 5, 6},
        {5, 6, 7, 8}
    };

    int max = arr[0][0];
    int min = arr[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    return 0;
}




// 8. Write a C program to check whether two matrices are equal or not
#include <stdio.h>

#define ROWS 3
#define COLS 4

int main() {
  
    int matrix1[ROWS][COLS] = {
        {1, 2, 3, 4},
        {3, 4, 5, 6},
        {5, 6, 7, 89}
    };

    int matrix2[ROWS][COLS] = {
        {1, 2, 3, 4},
        {3, 4, 5, 6},
        {5, 6, 7, 8}
    };

    int equal = 1; 

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix1[i][j] != matrix2[i][j]) {
                equal = 0;
                break;
            }
        }
    }
    if (equal) {
        printf("The matrices are equal.\n");
    } else {
        printf("The matrices are not equal.\n");
    }

    return 0;
}

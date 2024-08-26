/* 1. Write a function that takes the radius of a circle and return its area and
circumference.*/
#include <stdio.h>

#define pi 3.14159265359

void Area_Circumference(double radius, double *Area, double *Circumference) {
   *Area =  pi * radius * radius;
   *Circumference = 2 * pi *radius;
}

int main() {
    double radius, Area, Circumference;

    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    Area_Circumference(radius, &Area, &Circumference);
    
    printf("Area = %lf\n", Area);
    printf("circumference = %lf",Circumference);

    return 0;
}




/*2. Write a function that takes an array of integers (1D) and return its max
and minimum element also the average of the array.
*/
#include <stdio.h>

void max_min_avg(int arr[], int n, int *max, int *min, double *avg) {
    *max = arr[0];
    *min = arr[0];
    double sum = 0.0; 

    for (int i = 0; i < n; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
        sum += arr[i];
    }

    *avg = sum / n; 
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of elements must be positive.\n");
    }

    int numbers[n];

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    int max, min;
    double average;

    max_min_avg(numbers, n, &max, &min, &average);

    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
    printf("Average value: %.2f\n", average);

    return 0;
}




/*3. Write a C function that takes a 1D array of integers and return the count of
ones and regative numbers in the array using call by reference.*/
#include <stdio.h>

void count_ones_negatives(int arr[], int n, int *ones, int *negatives) {
    *ones = 0;
    *negatives = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            (*ones)++;                     // Increment ones counter if the element is 1
        } else if (arr[i] < 0) {
            (*negatives)++;                // Increment negatives counter if the element is negative
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n];

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    int ones, negatives;

    count_ones_negatives(numbers, n, &ones, &negatives);

    printf("Number of ones: %d\n", ones);
    printf("Number of negatives: %d\n", negatives);

    return 0;
}




//Dynamic memory allocation

/*1. Write a C function that takes an array of integers and return a reversed
array.
*/
#include <stdio.h>
#include <stdlib.h>

void reverseArray(int arr[], int size) {
    for (int i = 0, j = size - 1; i < j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int n;

   printf("Enter the number of elements: ");
    scanf("%d", &n) ;
     

    int *arr = malloc(n * sizeof(int));        //This code allocates memory for an integer array of size n using the malloc function
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]) ;
    }
    reverseArray(arr, n);

    printf("Reversed array: ");
    for (int i = 0; i < n; i++) {
        printf("\n%d ", arr[i]);
    }
 
    return 0;
}




/*2. Write a c function that takes an integer and returns a Fibonacci series
Input: 5
Output: 011235*/
#include <stdio.h>

void fibonacci(int n) {
    if (n <= 0) {
        printf("No Fibonacci numbers to display for non-positive input.\n");
        return;
    }

    int a = 0, b = 1, c;      // A Fibonacci series is a sequence of numbers where each number is the sum of the two preceding ones.

    printf("%d ", a); 

    if (n > 1) {
        printf("%d ", b); 
    }

    for (int i = 2; i < n; i++) {
        c = a + b; 
        printf("%d ", c);
        a = b;   
        b = c;
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter a positive integer number: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer number.\n");
        return 1;
    }

    printf("Fibonacci series: ");
    fibonacci(n);

    return 0;
}
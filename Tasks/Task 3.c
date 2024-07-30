// Jump Statements 

/* 1. Write a c program that print all the numbers from 1 to 100, 
 each number on a separate line, except when:
▸the number is divisible by 3 print FIZZ.
▸ the number is divisible by 5 print BUZZ
▸the number is divisible by both 3 and 5 print FIZZBUZZ */
#include <stdio.h>

int main() {
    int num;

    for (num = 1; num <= 100; num++) {
        if (num % 3 == 0 && num % 5 == 0) {
            printf("FIZZBUZZ\n");

        } else if (num % 3 == 0) {
            printf("FIZZ\n");

        } else if (num % 5 == 0) {
            printf("BUZZ\n");

        } else {
            printf("%d\n", num);
        }
    }

    return 0;
}



// 2. Write a c program that print the multiplication table from 1 to 10. 
#include <stdio.h>

int main() {
    int i, j;

    for (i = 1; i <= 10; i++) {
        printf("Multiplication table of %d:\n", i);
        for (j = 1 ; j <= 10 ; j++) {
            printf("%d x %d = %2d\n", i, j, i * j);
        }
        printf("\n");
    }

    return 0;
}



// 3. C program to count number of digits in an integer.
#include <stdio.h>

int main() {
    int num, count = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);

        // Count the number of digits in the integer
        while (num != 0) 
    {
        // Remove the last digit by dividing by 10
        num /= 10;
        // Increment the digit count
        count++;
    }
    printf("Number of digits : %d\n", count);

    return 0;
}


  
/* 4. Write a program in C to display the pattern like right angle triangle with a number
 1234
 123 
 12 */
 #include<stdio.h>
 
 int main(){
     int i ,j;

     for ( i = 4 ; i >= 1 ; i--)  // Outer loop iterates from 4 down to 1
     {
         for ( j = 1 ; j <= i ; j++) // Inner loop iterates from 1 up to the current value of i
         {
         printf("%d",j);
         }
         printf("\n");
     }

     return(0);
 }






// Functions

// 1. Write a function that takes an integer and return 1 if it's even or 0 it's odd. 
#include <stdio.h>

int is_even(int num) 
{
    // Returns 1 if the number is even (divisible by 2 without remainder), otherwise returns 0
    return num % 2 == 0;
}

int main() {
    int number;

    // Prompt the user to enter an integer
    printf("Enter an integer: ");

    // Read the integer from the user
    scanf("%d", &number);

    // Check if the number is even using the is_even function
    if (is_even(number)) {
        printf("%d is even\n", number);
    } else {
        printf("%d is odd\n", number);
    }

    return 0;
}



// 2. Write a function that takes 3 integers and return the biggest one. 
#include <stdio.h>

int biggest_number(int a, int b, int c);

int main() {
    // Call the biggest_number function with arguments 1, 2, and 3
    // and print the returned result (the biggest number)
    printf("%d\n", biggest_number(1, 2, 3));
    return 0;
}
// Function to find the biggest number among three
int biggest_number(int a, int b, int c) {
    // If a is greater than both b and c, return a
    if (a > b && a > c) {
        return a;
    }
    // If b is greater than c, return b
    else if (b > c) {
        return b;
    }
    // Otherwise, c is the biggest
    else {
        return c;
    }
}



/* 3. Write a program in C to find the sum of the series 1!/1+2!/2+3!/3+4!/4+5!/5
 using the function. */

 #include <stdio.h>

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

float sum_series(int n) {
    float sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (float)factorial(i) / i;
    }
    return sum;
}

int main() {
    int n = 5; // You can change this value to calculate the sum for different n
    float result = sum_series(n);
    printf("Sum of the series: %.2f\n", result);
    return 0;
}



// 4. Write a function in C to check whether a number is a prime number or not. 
# include <stdio.h>
int Prime(int num) {
    if (num <= 1) {
        return 0; 
    }
      // Check for divisibility by numbers from 2 to the square root of num
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1; 
}
int main() {
    int num;
    printf("Please enter a positive integer:\n ");
    scanf("%d", &num);
      if (Prime(num)) {
        printf("%d is a prime number\n", num);
    } else {
        printf("%d is not a prime number\n", num);
    }
    return 0;
}



// 5. Write a function in C to convert decimal number to binary number.  
#include <stdio.h>
long long decimalToBinary(int num)
    {
    long long binaryNumber = 0;
    while (num != 0) {
        binaryNumber = binaryNumber * 10 + num % 2;
        num /= 2;
    }
    return binaryNumber;
}
int main() {
    int decimalNumber;
    printf("Please enter a decimal number: ");
    scanf("%d", &decimalNumber);
    long long binaryEquivalent = decimalToBinary(decimalNumber);
    printf("Binary equivalent is  %lld\n", binaryEquivalent);
    return 0;
}



/* 6. Write a function that takes an integer n (>1) and print all numbers from 1 to n one in each
line ex
Numbers that divide by 3 it prints Fizz.
Numbers that divide by 5 it prints Buzz.
And if the number divides by 3 and 5 it prints FizzBuzz */
#include <stdio.h>

void fizzbuzz(int n) {
    for (int i = 1; i <= n; i++) {
        // Check if the number is divisible by both 3 and 5
        if (i % 3 == 0 && i % 5 == 0) {
            printf("FizzBuzz\n");
        } else if (i % 3 == 0) { // Check if the number is divisible by 3
            printf("Fizz\n");
        } else if (i % 5 == 0) { // Check if the number is divisible by 5
            printf("Buzz\n");
        } else { // Otherwise, print the number
            printf("%d\n", i);
        }
    }
}

int main() {
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Call the fizzbuzz function to print the numbers
    fizzbuzz(num);

    return 0;
}



                 // "TASK ONE"
// 1- Write a C code that will ask the user to enter a value then print it
#include<stdio.h>
int main(){
     int num;
     printf("Please enter a number: \n");
     scanf("%i",&num);
     printf("The value is: %i",num);
     return 0;
}  

// 2- Scan a character and print its value and ASCII value
#include<stdio.h>
int main(){
    char x;
    printf("Please enter a character:\n ");
    scanf("%c",&x);
    printf("The charachter is: %c\n",x);
    printf("The charachter's ASCII value is: %i\n",x);
    return 0;
}

// 3- Write C code that will ask the user to enter 2 integer values and print their summation ,
// subtraction , multiplication , division and reminder

#include <stdio.h>
int main()
{
    int num1, num2, summation, subtraction, multiplication, remainder;
    float division;
    printf("Please enter two integer numbers\nThe first number:\n");
    scanf("%i",&num1);
    printf("The second number:\n");
    scanf("%i", &num2);
    summation = num1 + num2;
    subtraction = num1 - num2;
    multiplication =num1 * num2;
    printf("The summation is: %i\n", summation);

    if (num2 != 0)
    {

        division = (float)num1 / num2;
        remainder = num1 % num2;
        printf("The division is: %.2f\n", division);
        printf("The remainder is: %i\n", remainder);
    }
    else
    {
        printf("error in division & remainder\n");
    }

    return (0);
}
                 // "TASK TWO"
// 1- Write a program to ask user for a radius r then calculate
// a- Area = pi*r^2
// b- Circumference = 2*pi*r

#include <stdio.h>
int main()
{
    float radius, area, cicumfernce;
    float pi = 3.14;
    printf("Please enter the radius\n");
    scanf("%f", &radius);

    area = pi * radius * radius;
    cicumfernce = 2 * pi * radius;

    printf("The area is %f\n", area);
    printf("The cicumfernce is %f\n", cicumfernce);
    return 0 ;
}

// 2- Solve these examples in a paper and confirm the that your answers are correct
// by writing a code printing the result
// X = 7 Y = 4
// Z = X & Y    
// K = X | Y     
// M = X ^ Y     
// L = X >> 1
// N = Y << 2

#include<stdio.h>
int main(){
    int X=7; //111
    int Y=4; //100
    int Z, K, L, M ,N;
    Z=X&Y;      //100
    K=X|Y;      //111
    L=X>>1;     //111
    M=X^Y;      //011
    N=Y<<2;
    printf("Z = %d\n",Z);
    printf("K = %d\n",K);
    printf("L = %d\n",L);
    printf("M = %d\n",M);
    printf("N = %d\n",N);
    return(0);
}

// 3- Write a C code to ask the user to input the following 3 integer values :
// 6 , 2, 5
// And store each value in a different variable then set the first bit in the first
// variable and clear the second bit in second variable and then toggle the third bit
// in the third variable
// Finally print the result

#include<stdio.h>
unsigned char x,y,z;
int main(){

    printf("Enter three integer: ");
    scanf("%d%d%d",&x,&y,&z);       // Seperated by spaces
    x |=(1<<0);          // Set the least significant bit of x to 1
    y &=~(1<<1);        // Clear the second least significant bit of y
    z ^=(1<<2);         // Toggle the third least significant bit of z
    printf("x= %d\ny= %d\nz= %d",x,y,z);
    return(0);
}

// 4- Write a C code and ask the user to enter 2 numbers and print the largest one of
// the two numbers if they not are equal
// And print " num1 = num2 " in case of the numbers are equal

#include<stdio.h>
int main(){

    float num1, num2, largest_number;
    printf("Please enter two numbers:\n");
    scanf("%f",&num1);
    scanf("%f",&num2);
    largest_number= num1>num2 ?num1:num2;
    printf("The largest number is %f",largest_number);
    return(0);
}
               // "TASK THREE"
//1- Write a c code that ask the user to enter a number and print if it is an odd or even number

#include <stdio.h>
int main() {

    int num;
    printf("Please enter a positive number: ");  
    scanf("%i", &num);                        

    if (num > 0) {
        if (num % 2 == 0) {
         printf("The number is even\n");
        }
         else {
         printf("The number is odd\n");
        }
    } 
    else {
         printf("The number is not positive\n");
    }
         return 0;
}

// 2- Write a C code to check whether a given positive number is a multiple of a 3 or multiple of 7

#include<stdio.h>
int main(){

    int num;
    printf("Please enter a positive number:\n ");
    scanf("%i",&num);
    if (num > 0){
    if(num%3==0 && num%7==0){
        printf("The number is multiple of 3 and 7");
    }
    else if(num%3==0) {
        printf("The number is multiple of 3 ");
    }
    else if(num%7==0)
    {
        printf("The number is multiple of 7 ");
    }
    else
    {
        printf("The number is not multiplied by 3 or 7");
    }
    }
    else{
        printf("The number is not positive");
    }
    return(0);
}

/* 3- Write a C code to calculate employee salary in a week based on the his
working hours, hour rate is 50. The program will ask the user to enter the
working hours, then it will print his salary. But if the working hours are
less than 40 hours, a 10% deduction will be applied*/


#include <stdio.h>
int main() {

    float hrs, salary, deduction_salary;
    int hour_rate = 50;
    printf("Enter the employee's working hours:\n ");
    scanf("%f", &hrs);
    salary = hrs * hour_rate ; 
    deduction_salary = salary - (0.1 * salary);

    if (hrs >= 40){
        printf("Your salary is %f",salary);
    }
    else{
        printf("Your salary is %f",deduction_salary);
    }
    return 0;
}

/* 4- Write a C code to ask the user to enter his grade and the program will
print his rating.
0 <= grade < 50 ------> Failed
50 <= grade < 65 ------> Normal
65 <= grade < 75 ------> Good
75 <= grade < 85 ------> Very Good
85 <= grade ------> Excellen*/

#include<stdio.h>
int main()
       {
       int grade;
       printf("Enter your grade \n");
       scanf(" %i",&grade);
        if (grade >= 0 && grade <50){
        printf("failed");}
        else if (grade>=50 && grade <65){
        printf("Normal");}
        else if (grade>=65 && grade <75){
        printf("Good");}
        else if (grade>=75 && grade < 85){
        printf("Very Good");}
        else {
        printf("Excellent");}
        return 0;
        }

/*5- Use sizeof() operator to determine the number of byte occupied in
memory to different data types*/

#include<stdio.h>
int main()
{
  
    printf("Size of float is %i ",sizeof(float));
    printf(" bytes");
    printf("\nSize of int is %i",sizeof(int));
    printf(" bytes");

    printf("\nSize of double  is %i",sizeof(double));
    printf(" bytes");
    printf("\nSize of long double int is %i",sizeof(long double));
    printf(" bytes");

    printf("\nSize of unsigned char is %i",sizeof(unsigned char));
    printf(" bytes");
    printf("\nSize of signed char is %i",sizeof(signed char));
    printf(" bytes");

    printf("\nSize of signed long is %i",sizeof(signed long));
    printf(" bytes");
    printf("\nSize of unsigned long is %i",sizeof( unsigned long ));
    printf(" bytes");
    return 0;
}


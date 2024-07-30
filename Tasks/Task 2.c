                    //TASK ONE (Conditional Statements)
/* 1- Write a C program that asks the user to enter his ID and if the ID is correct print a hello
message with his name IDs:
a. Amr's ID: 1234
b. Maha's ID: 5678
c. Ahmed's ID: 9101 2)*/ 

#include <stdio.h>
int main(){

int ID;
printf("Please enter your ID: \n\n");
scanf("%d",&ID);

switch(ID){

case 1234 : printf("\nHello Amr, Your ID is 1234\n");
break;

case 5678 : printf("\nHello Maha, Your ID is 5678\n");
break;

case 9101 : printf("\nHello Ahmed, Your ID is 9101\n ");
break;

default : printf("\nInvalid ID");
}

return 0;
}



/* 2- Write a C program that asks the user to enter his basic salary and then calculate the gross
salary according to his marital status:
a. Single: +0%
b. Married without kids: +%1
c. Married with kids: +%2*/

#include <stdio.h>
int main() {

    int salary;
    char marital_status;
    float  T,W,S;

    printf("Please enter your salary: \n");
    scanf("%d", &salary);

    printf("Please enter your marital status (S for Single, T for Married without kids, W for Married with kids)\n");
    scanf(" %c", &marital_status); // added space before %c to skip white space characters

    switch (marital_status) {
        case 'S':
            printf("Your salary is %i\n", salary);
            break;
        case 'T':
            T = salary + (0.01 * salary);
            printf("Your salary is %f\n", T);
            break;
        case 'W':
            W = salary + (0.02 * salary);
            printf("Your salary is %f\n", W);
            break;
        default:
            printf("Invalid marital status\n");
    }

    return 0;
}



// 3- Write a C program to check positive, negative or zero using switch case

#include <stdio.h>
int main() {
    
  int number;
  printf("Enter a number: ");
  scanf("%d", &number);

     switch (number > 0) { // Check if number is positive (non-zero and positive)
     case 1:
     printf("The number %d is positive.\n", number);
     break;
      
      case 0: 
      // Nested switch to check for zero or negative
     switch (number < 0) { // Check if number is negative
     case 1:
     printf("The number %d is negative.\n", number);
     break;
          
     case 0:
     printf("The number %d is zero.\n", number);
     break;
      }
     break;
  }

  return 0;
}



/* 4- Write a C program to print the day of week according to its respective number (eg sat = 1,
sun = 2, fr = 7)*/

#include <stdio.h>
int main(){

int num_day;
printf("Please enter the number of the day (1 = saturday , 2 = sunday,...) \n");
scanf("%d",&num_day);

switch(num_day){

case 1 : printf("The day is Saturday");
break;

case 2 : printf("The day is Sunday");
break;

case 3 : printf("The day is Monday");
break;

case 4 : printf("The day is Tuesday");
break;

case 5 : printf("The day is Wednesday");
break;

case 6 : printf("The day is Thursday");
break;

case 7 : printf("The day is Friday");
break;
}


return 0;
}





                       //TASK TWO (Loops)
// 1- Print even numbers from 2 to 99. Also, calculate the sum of even numbers from 2 to 99 

#include <stdio.h>
int main(){

int i, sum=0;
for (i = 2; i < 99; i=i+2){   
 printf("%d\t",i);
 sum = sum + i;
}
printf("\n\nThe sum of the numbers is %i",sum);

return 0;
}



/* 2- Write a c program that ask the user for an integer and print its factorial of any positive
integer. Ex: 5! 1*2*3*4*5  */

#include <stdio.h>
int main(){

int i, num, factorial=1;
printf("Please enter a number: \n");
scanf("%d",&num);

for (i = 1; i <= num; i++){
 factorial = factorial * i;
}
printf("The factorial of %d is %d",num,factorial);

return 0;
}
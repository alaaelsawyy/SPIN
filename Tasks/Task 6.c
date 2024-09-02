/* Write a c program to ask the user to:

1.enter the names, grades and id of 10 student and store this data in
array of structures using a function called get_data
2.then using one functions called average_highest_lowest_grade: that
takes the address of the array and return the average grade, the info of
the student with highest grad, and the info of the student with lowest
grade.
3.The printing should happen in main function and the passing should
be by reference.*/

#include <stdio.h>
#include <string.h>

struct data {
    char name[100];  
    int grade;     
    int id;        
};

  void get_data(struct data *students) {
    for (int i = 0; i < 10; i++) {
        printf("Enter name for student %d: ", i + 1);
        fgets(students[i].name, 100, stdin);

  // removing the trailing newline character from the name string
  //  after it's read using fgets
        students[i].name[strcspn(students[i].name, "\n")] = 0;
          
        printf("Enter grade for student %d: ", i + 1);
        scanf("%d", &students[i].grade);

            getchar();
        printf("Enter ID for student %d: ", i + 1);
        scanf("%d", &students[i].id);
           getchar();
    }
}

  void average_highest_lowest_grade(struct data *students, float *avg, struct data *highest, struct data *lowest) {
      
    int total_grade = 0;
    *highest = students[0];
    *lowest = students[0];

    for (int i = 0; i < 10; i++) {
        total_grade += students[i].grade;

        if (students[i].grade > highest->grade) {
            *highest = students[i];
        }

        if (students[i].grade < lowest->grade) {
            *lowest = students[i];
        }
    }
    
    *avg = (float)total_grade / 10;
}

  int main() {
    
    struct data students[10]; 
    float average;                     
    struct data highest, lowest;         

    get_data(students);

    average_highest_lowest_grade(students, &average, &highest, &lowest);

    printf("\nAverage grade: %.2f\n", average);
    printf("\nStudent with highest grade:\n");
    printf("Name: %s\n", highest.name);
    printf("Grade: %d\n", highest.grade);
    printf("ID: %d\n", highest.id);
    printf("\nStudent with lowest grade:\n");
    printf("Name: %s\n", lowest.name);
    printf("Grade: %d\n", lowest.grade);
    printf("ID: %d\n", lowest.id);

    return 0;
}

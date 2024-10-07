// employee.h
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

// Structure to hold employee details
struct employee {
    char name[50];      
    int age;           
    float salary;     
    char title[50];    
    int ID;           
};

// Node structure for the linked list
struct node {
    struct employee data;
    struct node *next;    
};

// Function declarations
void display_menu(void);
void add_employee(void);
void delete_employee(int id);
void modify_employee(int id);
void display_employee(void);
void display_all(void);
void exit_program(void);

#endif // EMPLOYEE_H

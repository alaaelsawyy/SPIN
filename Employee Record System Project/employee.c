// employee.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

// Global head pointer for the linked list
struct node *head = NULL;

/**************************************
 * Function to display the menu options
 **************************************/
void display_menu() {
    printf("\nSelect an Action: \n");
    printf("\n 1. Add a new employee.\n");
    printf(" 2. Delete an employee.\n");
    printf(" 3. Modify an employee.\n");
    printf(" 4. View an employee.\n");
    printf(" 5. View all employees.\n");
    printf(" 6. Exit.\n");
    printf("\nPlease Enter Your Selection: ");
}

/**************************************
 * Function to create a new node
 **************************************/
struct node *add_new_node(const struct employee *ptr) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    new_node->data = *ptr; 
    new_node->next = NULL; 
    return new_node;
}

/**************************************
 * Function to check if an employee ID exists
 **************************************/
int employee_id_exists(int id) {
    struct node *current = head;
    while (current != NULL) {
        if (current->data.ID == id) {
            return 1; // ID exists
        }
        current = current->next; 
    }
    return 0; // ID does not exist
}

/**************************************
 * Function to add a new employee
 **************************************/
void add_employee() {
    struct employee newEmployee;
    printf("\n==== Add a New Employee ====\n");

    printf("\nEnter Name: ");
    fgets(newEmployee.name, sizeof(newEmployee.name), stdin);
    newEmployee.name[strcspn(newEmployee.name, "\n")] = 0;

    printf("Enter Age: ");
    while (scanf("%d", &newEmployee.age) != 1 || newEmployee.age <= 0) {
        printf("Invalid input. Please enter a valid age: ");
        while(getchar() != '\n'); 
    }
    getchar();

    printf("Enter Salary: ");
    while (scanf("%f", &newEmployee.salary) != 1 || newEmployee.salary < 0) {
        printf("Invalid input. Please enter a valid salary: ");
        while(getchar() != '\n'); 
    }
    getchar();

    printf("Enter Title: ");
    fgets(newEmployee.title, sizeof(newEmployee.title), stdin);
    newEmployee.title[strcspn(newEmployee.title, "\n")] = 0;

    printf("Enter ID: ");
    while (scanf("%d", &newEmployee.ID) != 1) {
        printf("Invalid input. Please enter a valid ID: ");
        while(getchar() != '\n');
    }
    getchar(); 

    if (employee_id_exists(newEmployee.ID)) {
        printf("\nAn employee with ID %d already exists.\n", newEmployee.ID);
        return;
    }

    struct node *new_node = add_new_node(&newEmployee);
    if (new_node == NULL) return;

    new_node->next = head;
    head = new_node;
    printf("\nEmployee added successfully\n");
}

/**************************************
 * Function to delete an employee by ID
 **************************************/
void delete_employee(int id) {
    struct node *current = head, *prev = NULL;

    if (head == NULL) {
        printf("\nNo employees are present.\n");
        return;
    }

    printf("\nPlease enter the Employee ID to delete: ");
    while (scanf("%d", &id) != 1) {
        printf("Invalid input. Please enter a valid ID: ");
        while(getchar() != '\n'); 
    }

    while (current != NULL && current->data.ID != id) {      
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("\nEmployee with ID %d not found.\n", id);
        return;
    }

    if (prev == NULL) {
        head = head->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("\nEmployee with ID %d deleted successfully\n", id);
}

/**************************************
 * Function to modify an employee's details
 **************************************/
void modify_employee(int id) {
    struct node *current = head;

    printf("\nPlease enter the Employee ID to modify: ");
    while (scanf("%d", &id) != 1) {
        printf("Invalid input. Please enter a valid ID: ");
        while(getchar() != '\n'); 
    }

    while (current != NULL) {
        if (current->data.ID == id) {
            printf("\nEnter new details for employee with ID %d\n", id);
            printf("Enter new Name: ");
            fgets(current->data.name, sizeof(current->data.name), stdin);
            current->data.name[strcspn(current->data.name, "\n")] = 0;

            printf("Enter new Age: ");
            while (scanf("%d", &current->data.age) != 1 || current->data.age <= 0) {
                printf("Invalid input. Please enter a valid age: ");
                while(getchar() != '\n'); 
            }
            getchar();

            printf("Enter new Salary: ");
            while (scanf("%f", &current->data.salary) != 1 || current->data.salary < 0) {
                printf("Invalid input. Please enter a valid salary: ");
                while(getchar() != '\n'); 
            }
            getchar();

            printf("Enter new Title: ");
            fgets(current->data.title, sizeof(current->data.title), stdin);
            current->data.title[strcspn(current->data.title, "\n")] = 0;

            printf("\nEmployee with ID %d modified successfully\n", id);
            return;
        }
        current = current->next; 
    }

    printf("\nEmployee with ID %d not found.\n", id);
}

/**************************************
 * Function to display an employee's details
 **************************************/
void display_employee() {
    int id;
    struct node *temp = head;

    printf("\nEnter employee ID to view: ");
    while (scanf("%d", &id) != 1) {
        printf("Invalid input. Please enter a valid ID: ");
        while(getchar() != '\n'); 
    }
    getchar();

    while (temp != NULL && temp->data.ID != id) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nEmployee not found.\n");
        return;
    }

    printf("\nEmployee ID: %d\n", temp->data.ID);
    printf("Employee Name: %s\n", temp->data.name);
    printf("Employee Age: %d\n", temp->data.age);
    printf("Employee Salary: %.2f\n", temp->data.salary);
    printf("Employee Title: %s\n", temp->data.title);
}

/**************************************
 * Function to display all employees' data 
 **************************************/
void display_all() {
    if (head == NULL) {
        printf("\nNo employees found in the list.\n");
        return;
    }

    printf("\n=== Employee List ===\n");
    printf("------------------------------------------------------\n");
    printf("| %-8s | %-12s | %-4s | %-8s | %-10s |\n", "ID", "Name", "Age", "Salary", "Title");
    printf("------------------------------------------------------\n");

    struct node *current = head;
    while (current != NULL) {
        printf("| %-8d | %-12s | %-4d | %-8.2f | %-10s |\n",
               current->data.ID, current->data.name, current->data.age,
               current->data.salary, current->data.title);
        current = current->next;
    }
}

/**************************************
 * Function to exit the program
 **************************************/
void exit_program() {
    printf("\nExiting the Program...\n");
    while (head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
    exit(0);
}

/*
 ==========================================================
 Name        : C_Project_Alaa Elsawy.c
 Description : Employee record management system.
 Date        : 18 - 9 - 2024
 ==========================================================
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold employee details
struct employee {
    char name[50];      
    int age;           
    float salary;     
    char title[50];    
    int ID;           
};

// Node structure for linked list
struct node {
    struct employee data;
    struct node *next;    
};

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
    new_node->data = *ptr; // Copy employee data into the new node
    new_node->next = NULL; 
    return new_node;
}

/**************************************
 * Function to check if an employee ID exists
 **************************************/
int employee_id_exists(int id) {
    struct node *current = head; // Start from the head of the list
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
    printf("\n==== Add a New Employee ====\n");
    struct employee newEmployee; // Structure to hold new employee data

    printf("\nEnter Name: ");
    fgets(newEmployee.name, sizeof(newEmployee.name), stdin);
    newEmployee.name[strcspn(newEmployee.name, "\n")] = 0; // Remove newline

    printf("Enter Age: ");
    while (scanf("%d", &newEmployee.age) != 1 || newEmployee.age <= 0) {
        printf("Invalid input. Please enter a valid age: ");
        while(getchar() != '\n'); // Clear input buffer
    }
    getchar(); 

    printf("Enter Salary: ");
    while (scanf("%f", &newEmployee.salary) != 1 || newEmployee.salary < 0) {
        printf("Invalid input. Please enter a valid salary: ");
        while(getchar() != '\n'); // Clear input buffer
    }
    getchar();

    printf("Enter Title: ");
    fgets(newEmployee.title, sizeof(newEmployee.title), stdin);
    newEmployee.title[strcspn(newEmployee.title, "\n")] = 0; // Remove newline

    printf("Enter ID: ");
    while (scanf("%d", &newEmployee.ID) != 1) {
        printf("Invalid input. Please enter a valid ID: ");
        while(getchar() != '\n'); // Clear input buffer
    }
    getchar(); 

    // Check if the employee ID already exists
    if (employee_id_exists(newEmployee.ID)) {
        printf("\nAn employee with ID %d already exists.\n", newEmployee.ID);
        return;
    }

    struct node *new_node = add_new_node(&newEmployee); // Create a new node
    if (new_node == NULL) return;

    new_node->next = head; // Link the new node to the head
    head = new_node; // Update head to point to the new node
    printf("\nEmployee added successfully\n");
    printf("==============================");
}

/**************************************
 * Function to delete an employee by ID
 **************************************/
void delete_employee(int id) {
     printf("\n==== Remove an Employee ====\n");
     printf("\nPlease enter the Employee ID to delete: ");
    while (scanf("%d", &id) != 1) {
            printf("Invalid input. Please enter a valid ID: ");
    while(getchar() != '\n'); // Clear input buffer
    }
    getchar(); 
    struct node *current = head; // Pointer to traverse the list
    struct node *prev = NULL; // Pointer to keep track of the previous node

    if (head == NULL) {
        printf("\nNo employees are present.\n");
        return;
    }

    // Search for the employee by ID
    while (current != NULL && current->data.ID != id) {      
        prev = current;
        current = current->next;
    }

    // If the employee is not found
    if (current == NULL) {
        printf("\nEmployee with ID %d not found.\n", id);
        return;
    }

    // Remove the employee node from the list
    if (prev == NULL) { // Deleting head
        head = head->next;
    } else {
        prev->next = current->next; // Bypass the current node
    }
    free(current); // Free the memory allocated for the node
    printf("\nEmployee with ID %d deleted successfully\n", id);
    printf("==============================");
}

/**************************************
 * Function to modify an employee's details
 **************************************/
void modify_employee(int id) {
    printf("\n==== Update Employee Information ====\n");
        printf("\nPlease enter the Employee ID to modify: ");
    while (scanf("%d", &id) != 1) {
        printf("Invalid input. Please enter a valid ID: ");
    while(getchar() != '\n'); // Clear input buffer
    }
    getchar(); 
    struct node *current = head; 

    if (head == NULL) {
        printf("\nNo employees are present.\n");
        return;
    }

    // Search for the employee by ID
    while (current != NULL) {
        if (current->data.ID == id) {
            printf("\nEnter new details for the employee with ID %d\n", id);
            printf("Enter new Name: ");
            fgets(current->data.name, sizeof(current->data.name), stdin);
            current->data.name[strcspn(current->data.name, "\n")] = 0; // Remove newline

            printf("Enter new Age: ");
            while (scanf("%d", &current->data.age) != 1 || current->data.age <= 0) {
                printf("Invalid input. Please enter a valid age: ");
                while(getchar() != '\n'); // Clear input buffer
            }
            getchar(); 

            printf("Enter new Salary: ");
            while (scanf("%f", &current->data.salary) != 1 || current->data.salary < 0) {
                printf("Invalid input. Please enter a valid salary: ");
                while(getchar() != '\n'); // Clear input buffer
            }
            getchar(); 

            printf("Enter new Title: ");
            fgets(current->data.title, sizeof(current->data.title), stdin);
            current->data.title[strcspn(current->data.title, "\n")] = 0; // Remove newline

            printf("\nEmployee with ID %d modified successfully\n", id);
            printf("==============================");
            return;
        }
        current = current->next; 
    }

    printf("\nEmployee with ID %d not found.\n", id);
    printf("==============================");
}

/**************************************
 * Function to display an employee's details
 **************************************/
void display_employee() {
    printf("\n==== View Employee Details ====\n");
    int id;
    struct node *temp = head; 

    printf("\nEnter employee ID to view: ");
    while (scanf("%d", &id) != 1) {
        printf("Invalid input. Please enter a valid ID: ");
        while(getchar() != '\n'); // Clear input buffer
    }
    getchar(); 

    // Search for the employee by ID
    while (temp != NULL && temp->data.ID != id) {
        temp = temp->next;
    }

    // If the employee is not found
    if (temp == NULL) {
        printf("\nEmployee not found.\n");
        printf("==============================");
        return;
    }

    // Display employee details
    printf("\nEmployee ID: %d\n", temp->data.ID);
    printf("Employee Name: %s\n", temp->data.name);
    printf("Employee Age: %d\n", temp->data.age);
    printf("Employee Salary: %.2f\n", temp->data.salary);
    printf("Employee Title: %s\n", temp->data.title);
    printf("==============================");
}

/**************************************
 * Function to display all employees' data 
 **************************************/
void display_all(void) {
    printf("\n==== View All Employees ====\n");
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
    printf("\n==== Exiting the Program ====\n");
    printf("Thank you for using our services.\n");
    // Free memory allocated for the employee list
    while (head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
    exit(0); 
}

/**************************************
 * Main Function
 **************************************/
int main() {
    int choice, id; 
    printf("\t\t\t\t\t==== EMPLOYEE MANAGEMENT SYSTEM ====\n");

    while (1) {
        display_menu();  // Call the display menu function
        while (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number (1-6): ");
            while(getchar() != '\n'); // Clear input buffer
        }
        getchar();

        switch (choice) {
            case 1:     
                system("cls");
                add_employee(); 
                break;
            case 2:
                system("cls");
                delete_employee(id); 
                break;
            case 3:
                system("cls");
                modify_employee(id); 
                break;
            case 4:
                system("cls");
                display_employee(); 
                break;
            case 5:
                system("cls");
                display_all(); 
                break;
            case 6:
                system("cls");
                exit_program(); 
                break;
            default:
                system("cls");
                printf("Invalid selection. Please choose a valid option from the menu.\n");
        }
    }

    return 0; 
}

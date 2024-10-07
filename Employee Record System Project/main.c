#include <stdio.h>
#include <stdlib.h>
#include "employee.h"

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
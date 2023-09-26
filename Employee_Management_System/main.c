#include <stdio.h>
#include "employee.h"
int main() {
    int numEmployees = 1000, choice;
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);
    struct Employee employees[1000];
    for (int i = 0; i < numEmployees; i++) {
        printf("\nEnter data for Employee %d:\n", i + 1);
        acceptEmployeeData(&employees[i]);
        calculateNetPay(&employees[i]);
    }
    while (1) {
        printf("\nOptions:\n");
        printf("1. Display all employee data\n");
        printf("2. Update employee data\n");
        printf("3. Delete employee data\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEmployee Data:\n");
            for (int i = 0; i < numEmployees; i++) {
                printf("\nEmployee %d:\n", i + 1);
                showEmployeeData(employees[i]);
            }
            break;
        case 2:
            printf("Enter the Employee Number to update: ");
            int empNumberToUpdate;
            scanf("%d", &empNumberToUpdate);
            for (int i = 0; i < numEmployees; i++) {
                if (employees[i].empNumber == empNumberToUpdate) {
                    printf("Updating data for Employee %d:\n", i + 1);
                    acceptEmployeeData(&employees[i]);
                    calculateNetPay(&employees[i]);
                    printf("Data updated successfully.\n");
                    break;
                }
            }
            break;
        case 3:
            printf("Enter the Employee Number to delete: ");
            int empNumberToDelete;
            scanf("%d", &empNumberToDelete);
            for (int i = 0; i < numEmployees; i++) {
                if (employees[i].empNumber == empNumberToDelete) {
                    for (int j = i; j < numEmployees - 1; j++) {
                        employees[j] = employees[j + 1];
                    }
                    numEmployees--;
                    printf("Employee data deleted successfully.\n");
                    break;
                }
            }
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}


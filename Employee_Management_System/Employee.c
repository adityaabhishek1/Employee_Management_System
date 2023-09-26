#include "employee.h"
#include <stdio.h>
#include <string.h>
bool validateEmployeeID(int empID) {
    return empID >= 1000 && empID <= 9999;
}
bool validateEmployeeName(const char* name) {
    return strlen(name) > 0;
}

void acceptEmployeeData(struct Employee* emp) {
    printf("Enter Employee Number (1000-9999): ");
    scanf("%d", &emp->empNumber);
    while (!validateEmployeeID(emp->empNumber)) {
        printf("Invalid Employee Number. Enter again (1000-9999): ");
        scanf("%d", &emp->empNumber);
    }
    printf("Enter Employee Name: ");
    scanf("%s", emp->empName);
    while (!validateEmployeeName(emp->empName)) {
        printf("Invalid Employee Name. Enter again: ");
        scanf("%s", emp->empName);
    }
    printf("Enter Hire Date (dd mm yyyy): ");
    scanf("%d %d %d", &emp->hireDate.dd, &emp->hireDate.mm, &emp->hireDate.yy);
    printf("Enter Basic Salary: ");
    scanf("%f", &emp->basicSalary);

}
void calculateNetPay(struct Employee* emp) {
    float da = 0.4 * emp->basicSalary; 
    float ta = 0.1 * emp->basicSalary;
    float pf = 0.05 * emp->basicSalary;
    emp->netSalary = emp->basicSalary + da + ta - pf;
}
void showEmployeeData(struct Employee emp) {
    printf("Employee Number: %d\n", emp.empNumber);
    printf("Employee Name: %s\n", emp.empName);
    printf("Hire Date: %02d/%02d/%04d\n", emp.hireDate.dd, emp.hireDate.mm, emp.hireDate.yy);
    printf("Basic Salary: %.2f\n", emp.basicSalary);
    printf("Net Salary: %.2f\n", emp.netSalary);
}


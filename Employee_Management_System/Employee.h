#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <stdbool.h>
struct Date {
	int dd, mm, yy;
};
struct Employee {
	int empNumber;
	char empName[100];
	struct Date hireDate;
	float basicSalary;
	float netSalary;
};
bool validateEmployeeID(int empID);
bool validateEmployeeName(const char* name);
void acceptEmployeeData(struct Employee* emp);
void calculateNetPay(struct Employee* emp);
void showEmployeeData(struct Employee emp);
#endif


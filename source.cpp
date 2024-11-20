#include <iostream>
#include <string>
using namespace std;

class Salary {
public:
	virtual double calculateSalary() const = 0;
	virtual ~Salary() = default;
};

class SalaryForHours : public Salary {
public:
	double hoursWorked;
	double hourlyRate;

	SalaryForHours(double hours, double rate) : hoursWorked(hours), hourlyRate(rate) {}

	double calculateSalary() const override {
		return hoursWorked * hourlyRate;
	}
		 
};

class SalaryForWork : public Salary {
public:
	double amountOfWork;
	double workRate;

	SalaryForWork(double amount, double rate) : amountOfWork(amount), workRate(rate) {}

	double calculateSalary() const override {
		return amountOfWork * workRate;
	}
};


class Employee {
public:
	string name;
	string position;
	Salary& salary;

	Employee(const string& n, const string& p, Salary& s)
		: name(n), position(p), salary(s) {}


	virtual void displayInfo() const {
		cout << "Name: " << name << "\n"
			<< "Position: " << position << "\n"
			<< "Salary: " << salary.calculateSalary() << " UAH\n";
	}

	virtual ~Employee() = default;
};


class Developer : public Employee {
public:

	Developer(const string& n, Salary& s)
		: Employee(n, "Developer", s) {}

};

class Singer : public Employee {
public:

	Singer(const string& n, Salary& s)
		: Employee(n, "Singer", s) {}

};


int main() {

	SalaryForHours hourlySalaryWhole(160, 150); 
	SalaryForHours hourlySalaryHalf(100, 140); 
	SalaryForWork workSalary(200, 50);

	Developer dev("Maria", hourlySalaryWhole);
	Developer dev2("Vika", hourlySalaryHalf);
	Singer mgr("Anna", workSalary);


	cout << "Salary (by hours) for developer who work whole day\n";
	dev.displayInfo();
	cout << "------------------------\n";
	cout << "Salary (by hours) for developer who work half day\n";
	dev2.displayInfo();
	cout << "------------------------\n";
	cout << "Salary (by work) for singer\n";
	mgr.displayInfo();

	return 0;
}
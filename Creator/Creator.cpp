#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct employee
{
	int num;        // идентификационный номер сотрудника
    char name[15];  // имя сотрудника
    double hours;   // количество отработанных часов
};

int main(int argc, char** argv)

{
	string filename = argv[1];
	string amount_string = argv[2];
	int amount = stoi(amount_string);

	ofstream file(filename, ios::binary);

	while (amount != 0) {
		employee emp;

		cout << "Enter employee id: " << endl;
		cin >> emp.num;
		cout << "Enter employee name: " << endl;
		cin >> emp.name;
		cout << "Enter employee work hours: " << endl;
		cin >> emp.hours;

		file.write((char*)&emp.num, sizeof(emp.num));
		file.write((char*)&emp.name, sizeof(emp.name));
		file.write((char*)&emp.hours, sizeof(emp.hours));

		amount--;
	}
}
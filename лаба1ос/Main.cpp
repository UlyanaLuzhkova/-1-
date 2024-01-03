#include <windows.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;



int main()
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(STARTUPINFO));

	int amount;
	wstring filename;
	wstring creator = L"Creator.exe";

	wchar_t* creatorchar = new wchar_t[100];
	wcscpy_s(creatorchar, 100, creator.c_str());

	cout << "Enter binary file name: " << endl;
	wcin >> filename;
	cout << "Enter the amount of employees: " << endl;
	cin >> amount;

	wstring amount_string = to_wstring(amount);
	wchar_t filename_char[100];
	wchar_t amount_char[100];

	wcscpy_s(filename_char, filename.c_str()); 
	wcscpy_s(amount_char, amount_string.c_str());
	wcscat_s(filename_char, L" ");
	wcscat_s(filename_char, amount_char);
	wcscat_s(creatorchar, 100, L" ");
	wcscat_s(creatorchar, 100, filename_char);

	if (!CreateProcess(NULL, creatorchar, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
		printf("%d", GetLastError());
	}

	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hProcess);

	ifstream in(filename, ios::binary);

	while (amount != 0) {
		int x;
		in.read((char*)&x, sizeof(x));
		cout << "Id is: " << x << endl;

		char name[10];
		in.read((char*)&name, sizeof(name));
		cout << "Name is: " << name << endl;

		double hours;
		in.read((char*)&hours, sizeof(hours));
		cout << "Hours are: " << hours << endl;

		amount--;
	}

    wstring otchet; 
	double moneyPerHour;

	cout << "Enter report name: " << endl;
	wcin >> otchet;
    cout << "Enter money per hour: " << endl;
    wcin >> moneyPerHour;

    wstring report = L"Reporter.exe";
    wchar_t* reporterChar = new wchar_t[100]; 
	wstring moneyPerHour_string = to_wstring(moneyPerHour);
    wstring reporterCommand = report + L" " + filename + L" " + otchet + L" " + moneyPerHour_string;
	wchar_t reporterCommandChar[100];
	wcscpy_s(reporterCommandChar, reporterCommand.c_str());

	if (!CreateProcess(NULL, reporterCommandChar, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
	}

    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);

	string str;
	ifstream input(otchet);

    while (getline(input, str)) {
		cout << str << endl;
    } 
	std::system("pause");
}
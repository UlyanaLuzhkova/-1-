#include <iostream>
#include <fstream>
#include <string> 

using namespace std;

ifstream::pos_type filesize(const char* filename)
{
	ifstream in(filename, ifstream:: ate | ifstream :: binary);
	return in.tellg();
}

int main(int argc, char** argv) {
	string otchetName = argv[2];
    ofstream out(otchetName);
	string moneyPerHour = argv[3];
    double doubleMoneyPerHour = stod(moneyPerHour);
	string filename = argv[1];

	ifstream in(filename, ios::binary);

	out << filename << endl;

    while (!in.eof()) {
        int x; 
		in.read((char*)&x, sizeof(x));
		if (in.fail()) {
			break;
		}
		out << x << " ";

		char name[15]; 
		in.read((char*)&name, sizeof(name));
		out << name << " ";

		double hours;
		in.read((char*)&hours, sizeof(hours));
		out << hours << " " << doubleMoneyPerHour*hours << endl;
	}
}
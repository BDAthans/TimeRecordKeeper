
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

string version = "1.0";

int shour;
int lhour;
int minute;
string day;
string month;
string year;

bool debug = true;

void header();
void getDateTime();

int main() {
	header();
	getDateTime();





	system("pause");
	return 0;
}

void header() {
	cout << left << setw(10) << "Time Record Keeper v" << version << " by Brian Athans" << endl;
}

void getDateTime() {

	SYSTEMTIME sysTime, localTime;

	GetSystemTime(&sysTime);
	GetLocalTime(&localTime);

	if (localTime.wHour > 12) {
		lhour = localTime.wHour;
		lhour = lhour - 12;
	}

	if (localTime.wHour > 12) {
		shour = localTime.wHour;
		shour = shour - 12;
	}


	 if (debug == true) {
		cout << right << setw(15) << "System time: " << shour << ":" << sysTime.wMinute << endl;
		cout << right << setw(15) << "Local time: " << lhour << ":" << localTime.wMinute << endl;
		cout << right << setw(15) << "Month: " << localTime.wMonth << endl;
		cout << right << setw(15) << "Day: " << localTime.wDay << endl;
		cout << right << setw(15) << "Year: " << localTime.wYear << endl;
	}





}


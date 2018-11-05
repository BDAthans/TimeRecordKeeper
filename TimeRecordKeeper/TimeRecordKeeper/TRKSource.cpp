
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

string version = "1.0.1";

int shour;
int lhour;
int sminute;
int lminute;
int lday;
int lmonth;
int lyear;

string day;
string month;
string year;
string lAMPM = "AM";
string curDir();

//Change debugOn to FALSE to remove debug info.
bool debugOn = FALSE;

//Do Not Change outputSuccess
bool outputSuccess = TRUE;
string outputString;


void header();
void getDateTime();
void debugInfo();
void outputFile();
void pause();
void exit();

int main() {
	header();
	getDateTime();
	outputFile();
	debugInfo();
	exit();
	return 0;
}

void header() {
	cout << left << setw(10) << " Time Record Keeper v" << version << " by Brian Athans" << string(2, '\n');

}

void getDateTime() {

	SYSTEMTIME sysTime, localTime;

	GetSystemTime(&sysTime);
	GetLocalTime(&localTime);

	lhour = localTime.wHour;
	lminute = localTime.wMinute;
	lday = localTime.wDay;
	lmonth = localTime.wMonth;
	lyear = localTime.wYear;
	if (localTime.wHour > 12) {
		lhour = lhour - 12;
	}
	else if (lhour < 1)
	{
		lhour++;
	}

	shour = sysTime.wHour;
	sminute = sysTime.wMinute;

	if (shour > 12) {
		shour = shour - 12;
		lAMPM = "PM";
	}


}

void outputFile()
{	
	fstream myHours;
	string myHoursTxt = curDir() + "\\myHours.txt";
	myHours.open(myHoursTxt, fstream::app);

	if (!myHours.is_open())
	{
		outputSuccess = FALSE;
		cout << " Error Opening myHours.txt";
		myHours.close();
	}
	
	if (lminute < 10)
	{ 
		outputString = " -- CLOCK PUNCH - " + to_string(lmonth) + "-" + to_string(lday) + "-" + to_string(lyear) + " -- " + to_string(lhour) + ":0" + to_string(lminute) + lAMPM + " -- \n";
	}
	else
	{
		outputString = " -- CLOCK PUNCH - " + to_string(lmonth) + "-" + to_string(lday) + "-" + to_string(lyear) + " -- " + to_string(lhour) + ":" + to_string(lminute) + lAMPM + " -- \n";
	}

	myHours << outputString;
	cout << right << setw(30) << outputString << endl;

	myHours.close();
}

void pause() 
{
	char a;
	cout << string(1, '\n') << " Press any Key to Continue... ";
	a = _getch();
}

void debugInfo()
{
	if (debugOn == true) {
		int x = 30;
		

		cout << string(1, '\n');
		cout << right << setw(x) << "System Up-time: " << shour << ":" << sminute << endl;
		cout << right << setw(x) << "Local time: " << lhour << ":" << lminute << endl;
		cout << right << setw(x) << "Month: " << lmonth << endl;
		cout << right << setw(x) << "Day: " << lday << endl;
		cout << right << setw(x) << "Year: " << lyear << endl;
		cout << string(1, '\n');
		cout << right << setw(x) << "Current Directory: " << curDir() << endl;
		cout << right << setw(x) << "Output Success: " << outputSuccess << endl;

		pause();
	}
}

string curDir() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}

void exit()
{	
	cout << endl << " Finished operation, closing file..." << endl;
	Sleep(2000);
}
#pragma once
#ifdef _WIN32
#include <Windows.h>
#endif
#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

void setColor(int color) {
	//ChatGPT.
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void inputFile(std::ofstream& newFile, std::string b, const std::filesystem::directory_entry& dd) {
	time_t now;
	struct tm nowlocal;
	now = time(NULL);
	localtime_s(&nowlocal, &now);
	//
	newFile << setfill('0')
		<< "Filename: " << b << "\n"
		<< "Path: " << dd.path() << "\n"
		<< "Date: "
		<< setw(2) << nowlocal.tm_mday << "."
		<< setw(2) << nowlocal.tm_mon + 1 << "."
		<< nowlocal.tm_year + 1900 << "\n"
		<< "Time: "
		<< setw(2) << nowlocal.tm_hour << ":"
		<< setw(2) << nowlocal.tm_min << ":"
		<< setw(2) << nowlocal.tm_sec << "\n" << std::endl;
	Sleep(2500);
	cout << "\n";
}
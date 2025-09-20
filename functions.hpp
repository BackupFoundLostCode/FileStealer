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
void inputFile(std::ofstream& newFile, std::string b, const std::filesystem::directory_entry& dd,bool status) {
	time_t now;
	struct tm nowlocal;
	now = time(NULL);
	localtime_s(&nowlocal, &now);

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
		<< setw(2) << nowlocal.tm_sec << "\n" 
		<< "Status: "<< status <<"\n"
		<< std::endl;
	Sleep(1000);
	cout << "\n";
}
void caseNumOne(std::string filenameWhichGetCopy,std::string deviceLetter,std::string fusion, bool status, std::ofstream& newFile) {
	std::cin.ignore(50, '\n');
	std::cout << "Name for File to Copy:\n";
	std::getline(std::cin, filenameWhichGetCopy);

	std::filesystem::path PathCopyTo(deviceLetter);
	std::filesystem::path p(fusion);
	try {
		if (filesystem::exists(p)) {
			cout << "\nPath on Device exists! Path is:\n";
			cout << "\n";
			for (const auto& path : p) {
				cout << path << std::endl;
			}
			system("pause");
			try {
				setColor(10);
				for (const auto& dd : std::filesystem::recursive_directory_iterator("C:\\", std::filesystem::directory_options::skip_permission_denied | std::filesystem::directory_options::follow_directory_symlink)) {
					//cout << dd << std::endl; //faster without.
					if (dd.path().string().find(filenameWhichGetCopy) != std::string::npos) {
						cout << "\nFOUND FILE!\n";
						cout << dd.path() << std::endl;
						try {
							status = true;
							std::filesystem::copy_file(dd.path(), PathCopyTo / dd.path().filename());
							cout << "COPY SUCCESS!\n";
							inputFile(newFile, filenameWhichGetCopy, dd, status);
						}
						catch (const std::exception&) {
							status = false;
							setColor(12);
							cout << "Copy failed! Find information in FileStealer.txt!\n";
							inputFile(newFile, filenameWhichGetCopy, dd, status);
						}
						break;
					}
				}
			}
			catch (const std::exception&) {
				setColor(12);
				cout << "Search failed or file does not exist.\n";
				system("pause");
				std::cout << "\n";
			}
		}
		else {
			setColor(12);
			std::cout << "Path does not exist!\n";
			system("pause");
		}
	}
	catch (const std::exception&) {
		setColor(12);
		std::cout << "Search failed - fatal error!\n";
		system("pause");
	}
}
void caseNumbTow(std::filesystem::path forShowInfos) {
	std::cin.ignore(50, '\n');
	std::ifstream dataTXT{ forShowInfos };//Path for Output on console.
	if (dataTXT.fail() || !dataTXT.is_open()) {
		setColor(12);
		std::cout << "Fail open FileStealerInfo.txt!\n";
		setColor(10);
		std::cout << "Back to Menue in 2 Seconds.\n";
		std::cout << "\n";
		Sleep(2000);
		//continue;
	}
	else {
		std::string output;
		setColor(10);
		while (getline(dataTXT, output)) {
			std::cout << output << std::endl;
		}
		dataTXT.close();
		system("pause");
	}
}
void caseNumbThree(std::filesystem::path ListOnDevice,std::string deviceLetter, std::string stealerTXT,bool status, std::ofstream& newFile) {
	std::cin.ignore(50, '\n');
	std::cout << "Edit the List." << "\n" << std::endl;
	std::ifstream dataList{ ListOnDevice };
	std::string output;
	
	std::filesystem::path PathCopyTo(deviceLetter);
	std::filesystem::path p(deviceLetter + stealerTXT);
	setColor(10);
	while (getline(dataList, output)) {
		try {
			setColor(10);
			for (const auto& lol : std::filesystem::recursive_directory_iterator("C:/", std::filesystem::directory_options::skip_permission_denied | std::filesystem::directory_options::follow_directory_symlink)) {
				//cout << lol << std::endl; //faster without.
				if (lol.path().string().find(output) != std::string::npos) {
					cout << "\nFOUND FILE!\n";
					cout << lol.path() << std::endl;
					try {
						status = true;
						std::filesystem::copy_file(lol.path(), PathCopyTo / lol.path().filename());
						cout << "COPY SUCCESS!\n";
						inputFile(newFile, output, lol, status);
					}
					catch (const std::exception&) {
						status = false;
						setColor(12);
						cout << "Copy failed! Find information in FileStealer.txt!\n";
						inputFile(newFile, output, lol, status);
					}
					break;
				}
			}
		}
		catch (const std::exception&) {
			setColor(10);
			std::cout << output << std::endl;
			setColor(12);
			cout << "Search failed or file does not exist.\n";
			Sleep(2500);
			std::cout << "\n";
		}
	}
	dataList.close();
	system("pause");
}
int caseNumbFour() {
	std::cin.ignore(50, '\n');
	setColor(10);
	std::cout << "Exit Program in 3 Seconds.";
	Sleep(3000);
	return 0;
}

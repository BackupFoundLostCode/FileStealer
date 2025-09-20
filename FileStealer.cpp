#ifdef _WIN32
#include <Windows.h>
#endif
#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <ctime>
#include "functions.hpp"
using namespace std;
int main() {
	int option;
	int* aRev = &option;
	bool status = false;
	std::string filenameWhichGetCopy;
	std::string  stealerTXT= "FileStealerInfo.txt";//a
	std::string nameList = "NameList.txt";
	std::string deviceLetter = "D:\\"; //D: ?
	std::string fusion = deviceLetter + stealerTXT;
	std::string createNameList = deviceLetter + nameList;
	std::ofstream listFile(createNameList, ios::app);
	std::ofstream newFile(fusion, ios::app);
	std::filesystem::path forShowInfos(fusion);
	std::filesystem::path ListOnDevice(createNameList);

	while (true){
		setColor(10);
		std::cout << "1. Searching File." << std::endl << "2. for read FileStealerInfo.txt." << std::endl << "3. Search all from NameList.txt." << std::endl << "4. Exit Program." << std::endl;
		std::cin >> *aRev;
		std::cout << "\n";
		if (std::cin.fail()){
			setColor(12);
			std::cout << "Your input is not a Number!" << "\n";
			std::cin.clear();
			std::cin.ignore(50, '\n');
			continue;
		}
		else {
			switch (*aRev) {
			case 1: {
				caseNumOne(filenameWhichGetCopy,deviceLetter,fusion,status,newFile);
			}
				break;
			case 2: {
				caseNumbTow(forShowInfos);
			}
				break;
			case 3: {
				caseNumbThree(ListOnDevice, deviceLetter,stealerTXT,status,newFile);
			}
				break;
			case 4: {
				if (caseNumbFour() == 0) {
					return 0;
				}
			}
				break;
			default: setColor(12);
				std::cout << "Wrong Number!\n";
				std::cout << "\n";
			}
		}
	}
	return EXIT_SUCCESS;
}

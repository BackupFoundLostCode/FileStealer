#ifdef _WIN32
#include <Windows.h>
#endif
#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <ctime>
//IDEEN: das eine als methode schreiben.
//Nicht nur files ganze Ordner kopieren.
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
int main() {
	int option;
	int* aRev = &option;
	std::string filenameWhichGetCopy;
	std::string a = "FileStealerInfo.txt";
	std::string nameList = "NameList.txt";
	std::string deviceLetter = "D:/";//D: ?
	std::string fusion = deviceLetter + a;
	std::string createNameList = deviceLetter + nameList;
	std::ofstream listFile(createNameList, ios::app);
	std::ofstream newFile(deviceLetter + a, ios::app);//eventuell duch fusion ersetzen.
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
				std::cin.ignore(50, '\n');
				std::cout << "Name for File to Copy:\n";
				std::getline(std::cin, filenameWhichGetCopy);
				//
				std::filesystem::path PathCopyTo(deviceLetter);
				std::filesystem::path p(deviceLetter + a);
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
							for (const auto& dd : std::filesystem::recursive_directory_iterator("C:/", std::filesystem::directory_options::skip_permission_denied | std::filesystem::directory_options::follow_directory_symlink)) {
								//cout << dd << std::endl;
								if (dd.path().string().find(filenameWhichGetCopy) != std::string::npos) {
									cout << "\nFOUND FILE!\n";
									cout << dd.path() << std::endl;
									try {
										std::filesystem::copy_file(dd.path(), PathCopyTo / dd.path().filename());
										cout << "COPY SUCCESS!\n";
										inputFile(newFile ,filenameWhichGetCopy,dd);
									}
									catch (const std::exception&) {
										setColor(12);
										cout << "Copy failed! Find information in FileStealer.txt!\n";
										inputFile(newFile,filenameWhichGetCopy,dd);
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
				break;
			case 2: {
				std::cin.ignore(50, '\n');
				std::ifstream dataTXT{ forShowInfos };//Path for Output on console.
				if (dataTXT.fail() || !dataTXT.is_open()) {
					setColor(12);
					std::cout << "Fail open FileStealerInfo.txt!\n";
					setColor(10);
					std::cout << "Back to Menue in 2 Seconds.\n";
					std::cout << "\n";
					Sleep(2000);
					continue;
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
				break;
			case 3: {
				std::cin.ignore(50, '\n');
				std::cout << "Edit the List." << "\n" << std::endl;
				std::ifstream dataList{ ListOnDevice };
				std::string output;
				//
				std::filesystem::path PathCopyTo(deviceLetter);
				std::filesystem::path p(deviceLetter + a);
				setColor(10);
				while (getline(dataList, output)) {
					try {
						setColor(10);
						for (const auto& lol : std::filesystem::recursive_directory_iterator("C:/", std::filesystem::directory_options::skip_permission_denied | std::filesystem::directory_options::follow_directory_symlink)) {
							//cout << lol << std::endl; //fester without.
							if (lol.path().string().find(output) != std::string::npos) {
								cout << "\nFOUND FILE!\n";
								cout << lol.path() << std::endl;
								try {
									std::filesystem::copy_file(lol.path(), PathCopyTo / lol.path().filename());
									cout << "COPY SUCCESS!\n";
									inputFile(newFile,output,lol);
								}
								catch (const std::exception&) {
									setColor(12);
									cout << "Copy failed! Find information in FileStealer.txt!\n";
									inputFile(newFile,output,lol);
								}
								break;
							}
						}
					}
					catch (const std::exception&) {
						setColor(12);
						cout << "Search failed or file does not exist.\n";
						Sleep(2500);
						std::cout << "\n";
					}
				}
				dataList.close();
				system("pause");
			}
				break;
			case 4: {
				std::cin.ignore(50, '\n');
				setColor(10);
				std::cout << "Exit Program in 3 Seconds.";
				Sleep(3000);
				return 0;
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

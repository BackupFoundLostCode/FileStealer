#ifdef _WIN32
#include <Windows.h>
#endif
#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;
int main() {
	system("color 02");
	int option;
	std::string a = "FileStealerInfo.txt";
    std::string deviceLetter = "D:/";//D: ?
	std::string fusion = deviceLetter+a;
	//
	std::filesystem::path forShowInfos(fusion);
	while (true) { //i wish there were a loop...
		std::string filenameWhichGetCopy;
		std::cout << "1 searching File." << std::endl <<"2 for read FileStealerInfo.txt." << std::endl << "3 for EXIT Program." << std::endl;
		std::cin >> option;
		std::cout << "\n";
		if (option==1){
			std::ofstream newFile("D:" + a, ios::app);
			std::cout << "Name for File to Copy:\n";
			std::cin >> filenameWhichGetCopy;
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
						std::filesystem::recursive_directory_iterator d("C:/", std::filesystem::directory_options::skip_permission_denied);
						for (const auto& dd : std::filesystem::recursive_directory_iterator("C:/", std::filesystem::directory_options::skip_permission_denied)) {
							cout << dd << std::endl;
							if (dd.path().filename() == filenameWhichGetCopy) {
								cout << "\nFOUND FILE!\n";
								cout << dd.path() << std::endl;
								try {
									std::filesystem::copy_file(dd.path(), PathCopyTo / dd.path().filename());
									cout << "COPY SUCCESS!\n";
									//
									time_t now;
									struct tm nowlocal;
									now = time(NULL);
									localtime_s(&nowlocal, &now);
									//
									newFile << setfill('0')
										<< "Filename: " << filenameWhichGetCopy << "\n"
										<< "Path: " << dd.path() << "\n"
										<< "Date: "
										<< setw(2) << nowlocal.tm_mday << "."
										<< setw(2) << nowlocal.tm_mon + 1 << "."
										<< nowlocal.tm_year + 1900 << "\n"
										<< "Time: "
										<< setw(2) << nowlocal.tm_hour << ":"
										<< setw(2) << nowlocal.tm_min << ":"
										<< setw(2) << nowlocal.tm_sec << "\n" << std::endl; 
									system("pause");
									cout << "\n";
								}
								catch (const std::exception&) {
									cout << "Copy failed! Find information in FileStealer.txt!\n";
									time_t now;
									struct tm nowlocal;
									now = time(NULL);
									localtime_s(&nowlocal, &now);
									//
									newFile << setfill('0')
										<< "Filename: " << filenameWhichGetCopy << "\n"
										<< "Path: " << dd.path() << "\n"
										<< "Date: "
										<< setw(2) << nowlocal.tm_mday << "."
										<< setw(2) << nowlocal.tm_mon + 1 << "."
										<< nowlocal.tm_year + 1900 << "\n"
										<< "Time: "
										<< setw(2) << nowlocal.tm_hour << ":"
										<< setw(2) << nowlocal.tm_min << ":"
										<< setw(2) << nowlocal.tm_sec << "\n" << std::endl;
									system("pause");
									cout << "\n";
								}
								break;
							}
						}
					}
					catch (const std::exception&) {
						cout << "Search failed or file does not exist.\n";
						system("pause");
						std::cout << "\n";
					}
				}
				else {
					std::cout << "Path does not exist!\n";
					system("pause");
				}
			}
			catch (const std::exception&) {
				std::cout << "Search failed - fatal error!\n";
				system("pause");
			}
		}
		else if (option==2){
			std::ifstream dataTXT{forShowInfos};//Path for Output on console.
			if (dataTXT.fail() || !dataTXT.is_open()){
				std::cout << "Fail open FileStealerInfo.txt!\n";
				Sleep(1000);
				std::cout << "Back to Menue in 2 Seconds.\n";
				std::cout << "\n";
				Sleep(2000);
				continue;
			}
			else {
				std::string output;
				while (getline(dataTXT, output)) {
					std::cout << output << std::endl;
				}
				dataTXT.close();
				system("pause");
			}
		}
		else if (option == 3) {
			std::cout << "Exit Program in 3 Seconds.";
			Sleep(3000);
			return 0;

		}
		else {
			std::cout << "Wrong Nuber!\n";
			std::cout << "\n";
			Sleep(2000);
		}
	}
	return EXIT_SUCCESS;
}


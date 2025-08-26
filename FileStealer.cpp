#ifdef _WIN32
#include <Windows.h>
#endif
#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std;


int main(){
	system("color 02");
		while (true) {

			std::string filenameWhichGetCopy;
			std::string a = "FileStealerInfo.txt";
			std::string nameUSB;

			std::cout << "Name (Letter) of your USB Device:\n";
			std::cin >> nameUSB;
			std::ofstream newFile(nameUSB + ":" + a, ios::app);
			std::cout << "Name for File to Copy:\n";
			std::cin >> filenameWhichGetCopy;

			std::filesystem::path dr(nameUSB + ":/");
			std::filesystem::path p(nameUSB + ":" + a);

			try {
				if (filesystem::exists(p)) {
					cout << "\nPath on Device exists! Path is:\n";
					cout << "\n";
					for (const auto& path : p) {
						cout << path << endl;
					}
					system("pause");
					try {
						std::filesystem::recursive_directory_iterator d("C:/", std::filesystem::directory_options::skip_permission_denied);
						for (const auto& dd : std::filesystem::recursive_directory_iterator("C:/", std::filesystem::directory_options::skip_permission_denied)) {
							cout << dd << endl;
							if (dd.path().filename() == filenameWhichGetCopy) {
								cout << "\nFOUND FILE!\n";
								cout << dd.path() << endl;
								try {
									std::filesystem::copy_file(dd.path(), dr / dd.path().filename());
									cout << "Copy Success!\n";

									time_t now;
									struct tm nowlocal;
									now = time(NULL);
									localtime_s(&nowlocal, &now);

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
										<< setw(2) << nowlocal.tm_sec << "\n" << endl;
									system("pause");
									cout << "\n";
								}
								catch (const std::exception&) {
									cout << "Copy failed! Find information in FileStealer.txt!\n";
									time_t now;
									struct tm nowlocal;
									now = time(NULL);
									localtime_s(&nowlocal, &now);

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
										<< setw(2) << nowlocal.tm_sec << "\n" << endl;
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
		return EXIT_SUCCESS;
}




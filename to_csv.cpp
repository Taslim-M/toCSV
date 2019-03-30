#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <filesystem>
#include <stdio.h>
using namespace std;
namespace fs = std::filesystem;

void main() {
	bool check = true;
	while (check) {
		string sys;
		cout << "Enter directory: ";
		getline(cin, sys);
		int length = sys.length();
		if (!SetCurrentDirectory(sys.c_str())) {
			cout << "Error accesing directory\n"; break;
		}
		const int bufferSize = MAX_PATH;
		char newDir[bufferSize];
		GetCurrentDirectory(bufferSize, newDir);
		cout << "Working on:" << newDir << endl;
		string fname;
		for (const auto & entry : fs::directory_iterator(sys.c_str())) {
			fname.clear();
			fname = entry.path().u8string();
			ifstream fin;
			fin.open(fname);
			ofstream fout(fname + ".csv");
			string temp; int loc, loc2;
			while (getline(fin, temp)) {
				while (temp[0] == ' ') {
					temp.erase(0, 1);
				}
				loc = temp.find(" ");
				while (loc > -1) {
					temp.replace(loc, 1, ",");
					loc2 = temp.find(" ");
					while (loc2 - loc == 1) {
						temp.erase(loc2, 1);
						loc2 = temp.find(" ");
					}
					loc = temp.find(" ");
				}
				fout << temp << endl;
			}
			fout.close();
			fin.close();
			remove(fname.c_str());
		}
		cout << "Convert another Directory? Y/N :";
		getline(cin,fname);
		if (fname == "Y" or fname == "y")
			check = true;
		else check = false;
	}
	system("pause");
}
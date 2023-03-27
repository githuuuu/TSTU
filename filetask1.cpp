#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeFile(string);
void readFile(string);
void readFile2(string);
int min(string);
int max(string);
int findeven(string);

int main() {
	string filename = "Z:/p/shite3/filename.txt";
	writeFile(filename);
	readFile(filename);
	readFile2(filename);
}

void writeFile(string filename) {
	fstream Myfile(filename);
	if (!Myfile.is_open()) {
		cout << "Unable to open file";
	}
	else
		for (int i = 0; i < 20; i++) {
			Myfile << rand() % 20 << "\n";
		}
	Myfile.close();
}

void readFile(string filename) {
	string Text;
	int num = 0, res = 0;
	fstream Myfile(filename);
	if (!Myfile.is_open()) {
		cout << "Unable to open file";
	}
	else {
		while (getline(Myfile, Text)) {
			num = atoi(Text.c_str());
			if (num > res) {
				res = num;
			}
		}
		cout << "Max: " << res << endl;
		Myfile.clear();
		getline(Myfile, Text);
		res = atoi(Text.c_str());
		Myfile.clear();
		while (getline(Myfile, Text)) {
			num = atoi(Text.c_str());
			if (num < res) res = num;
		}
		cout << "min: " << res << endl;
		res = 0;
		Myfile.clear();
		while (getline(Myfile, Text)) {
			num = atoi(Text.c_str());
			if (num % 2 == 0) res++;
		}
		cout << res << " even numbers" << endl;
	}
	Myfile.close();
}
void readFile2(string filename) {
	string Text;
	fstream Myfile(filename);
	if (!Myfile.is_open()) {
		cout << "Unable to open file";
	}
	else 
		while (getline(Myfile, Text)) {
			cout << Text << endl;
		}
	Myfile.close();
}

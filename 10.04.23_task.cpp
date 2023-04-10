#include <iostream>
#include <fstream>
#include<string>

using namespace std;
void writeFile(string,string);
void readFile(string);
void findxyz(string);

int main() {
	string str="xxyyyzzyxxzyxyzyxzxyzyx";
	string filename = "C:\\Users\\tstu_student2\\Desktop\\myfile.txt";
	writeFile(filename,str);
	readFile(filename);
}

void writeFile(string filename, string text) {
	fstream Myfile(filename);
	if (!Myfile.is_open()) {
		cout << "Unable to open file";
	}
	else
	Myfile << text;
	Myfile.close();
}

void readFile(string filename) {
	string Text;
	fstream Myfile(filename);
	if (!Myfile.is_open()) {
		cout << "Unable to open file";
	}
	else
		/*while (getline(Myfile, Text)) {
			cout << Text << endl;
		}*/
		getline(Myfile, Text);
		cout << Text << endl;
		findxyz(Text);
		Myfile.close();
}
void findxyz(string text) {
	int num = 0,sum = 0;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == 'x' && (num==0 || num==1)) {
			num = 1;
		}
		if (text[i] == 'y' && (num == 1 || num == 2)) {
			num = 2;
		}
		if (text[i] == 'z' && num == 2) {
			num = 0;
			sum++;
		}
	}
	cout << endl << sum << " substrings in alphabetic order";
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;



int main() {
	// openFile();
	
	/*
	ofstream file("output.txt");

	if (!file) {
		cout << "�t�@�C�����J���܂���ł���\n";
		return 1;
	}
	
	file << "Hello, File!";
	file.close();

	cout << "�t�@�C�����쐬���A�f�[�^���������݂܂���\n";
	*/

	/*
	ifstream file("output.txt");
	string line;

	while (getline(file, line)) {
		cout << line << "\n";
	}
	file.close();

	//cout << system("cd");


	return 0;
	*/

	stringstream ss("100 apples");
	int num;
	string item;
	ss >> num >> item;

}
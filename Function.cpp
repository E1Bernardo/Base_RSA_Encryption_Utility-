#include <iostream>
#include <vector>
#include<fstream>
#include<string>
#include"Header_function.h"

using namespace std;

void check_console_input(Console_key& console_input, int argc, char* argv[])//int argc, char* argv[],
{
	string file_name_console = argv[1];
	string key_console = argv[2];
	int count_key_console = argc;

	fstream checking_opening;
	checking_opening.open((file_name_console), fstream::binary | ios::in);
	if (!checking_opening.is_open()) {
		cout << "\nFile not found, please re-enter\n";

		while (!checking_opening.is_open()) {
			cout << "\nEnter file name:  ";
			cin >> file_name_console;

			checking_opening.open((file_name_console), fstream::binary | ios::in);
			if (checking_opening.is_open()) {
				cout << "\n>>> The file is found <<<\n";
				break;
			}
			std::cin.clear();
			std::cin.ignore(3000, '\n');
			cout << "\nFile not found, please re-enter \n";
		}
	}
	else {
		cout << "\n>>> The file is found <<<\n";
	}
	system("pause");
	system("cls");

	if (key_console != "rsa" && key_console != "RSA") {
		int hint = 0;
		while (key_console != "rsa" && key_console != "RSA") {
			cout << "Error, entering a nonexistent key: \n\n";
			cout << "Enter the key: ";
			cin >> key_console;
			std::cin.clear();
			std::cin.ignore(3000, '\n');
			hint++;
			if (hint == 3) {
				cout << "\nThere is only one key in this program - [RSA] or [rsa]\n";
			}
		}
		cout << "\n>>> Key accepted <<<\n";
	}
	else {
		cout << "\n>>> Key accepted <<<\n";
	}

	console_input.file_name = file_name_console;
	console_input.optional_key = key_console;
	system("pause");
	system("cls");
}

int verification_encryption_decryption(string file_name)
{
	char mark;
	fstream check_mark;
	check_mark.open((file_name), fstream::binary | ios::in);

	if (!check_mark.is_open()) {
		cerr << "Error, the file didn't open";
		exit(1);
	}
	else
	{
		check_mark.read((char*)&mark, sizeof(unsigned __int8));
		mark = ((unsigned __int64)pow(mark, 5)) % 35; // числа для расшифровки маркера . см. (encryption_and_recording)
		if (mark == '!') {
			return 1;
		}
		else {
			return 0;
		}
	}
	check_mark.close();
}

void reading_simple_file(string file_name, vector <unsigned __int8> &simple_text)
{
	ifstream in;
	in.open((file_name), fstream::binary | ios::in); 
	int count_char = 0;
	char sign;
	if (!in.is_open()) {
		cerr << "Error, the file didn't open";
		exit(2);
	}
	else
	{
		while (!in.eof()) {
			sign = in.get();
			//in.read((char*)&sign, sizeof(char));
			simple_text.insert(simple_text.end(), sign);
			//in.read((char*)&sign, sizeof(wchar_t));
			count_char++;
		}
	}
	in.close();
}

void reading_encrypted_file(string file_name, vector <string> &encrypted_text)
{
	ifstream in;
	in.open((file_name), fstream::binary | ios::in);
	int count_char = 0;
	string number{};
	if (!in.is_open()) {
		cerr << "Error, the file didn't open";
		exit(3);
	}
	else
	{
		while (!in.eof()) {
			string number{};
			//getline(in, number);
			in >> number;
			encrypted_text.insert(encrypted_text.end(), number);
			//in.read((char*)&sign, sizeof(wchar_t));
			count_char++;
		}
	}
	in.close();
}

void string_to_number(vector <string> & encrypted_text, vector <int> &encrypted_digit_text)
{
	int number_from_string;
	for (size_t i = 0; i < encrypted_text.size(); i++)
	{
		number_from_string = atoi(encrypted_text[i].c_str());
		encrypted_digit_text.insert(encrypted_digit_text.end(), number_from_string);
	}
}
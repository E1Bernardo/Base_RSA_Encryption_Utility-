#include <iostream>
#include <vector>
#include<fstream>
#include<cmath>
#include"Header_function.h"
#include <boost/multiprecision/cpp_int.hpp>


using namespace std;
using namespace boost::multiprecision;


void decryption_and_recording(vector <int> encrypted_digit_text, string file_name)
{
	setlocale(LC_ALL, "rus");
	unsigned __int64 p = 17, q = 19;
	unsigned __int64 module = p * q;
	unsigned short int public_exhibitor = 151, private_exhibitor = 103;
	int F = 52, E = 51; // разделение  private_exhibitor
	int1024_t first_half, second_half, data_digit, res;

	fstream cipher_text;
	cipher_text.open((file_name), fstream::binary | ios::out | ios::trunc);
	if (!cipher_text.is_open()) {
		cerr << "error";
		exit(5);
	}
	else
	{
		for (size_t i = 1; i < encrypted_digit_text.size(); i++) {
			
			data_digit = encrypted_digit_text[i];
			first_half = pow(data_digit, F);
			first_half = first_half % module;

			second_half = pow(data_digit, E);
			second_half = second_half % module;

			res = first_half * second_half;
			res = res % module;
			cipher_text << (char)res;
		}
	}
	cipher_text.close();
	cout << "\n\n>>>  The text is decoded  <<<\n\n";
	system("pause");
}
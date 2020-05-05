#include <iostream>
#include <vector>
#include<fstream>
#include<ctime>
#include<cmath>
#include"Header_function.h"
#include <boost/multiprecision/cpp_int.hpp>
#define BOOST_ATOMIC_INT128_LOCK_FREE

using namespace std;
using namespace boost::multiprecision;


void decryption_and_recording(vector <unsigned short int>& cipher_text_vector, string file_name)
{
	unsigned __int64 p = 17, q = 19;
	unsigned __int64 module = p * q;  
	unsigned __int64 public_exhibitor = 151;
	unsigned __int64 private_exhibitor = 103;

	fstream cipher_text;
	cipher_text.open((file_name), fstream::binary | ios::out | ios::trunc);
	if (!cipher_text.is_open()) {
		cerr << "error";
		exit(1);
	}
	else
	{
		for (size_t i = 1; i < cipher_text_vector.size(); i++) {
			int1024_t res;
			res = (int1024_t)cipher_text_vector[i];
			res = pow(res, private_exhibitor);
			res = res % module;
			cipher_text.write((char*)&res, sizeof(unsigned __int8));
		}
	}
	cipher_text.close();
	cout << "\n\n>>>  The text is decoded  <<<\n\n";
	system("pause");
}
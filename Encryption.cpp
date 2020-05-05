#include <iostream>
#include <vector>
#include<fstream>
#include<ctime>
#include<cmath>
#include <boost/multiprecision/cpp_int.hpp>
#define BOOST_ATOMIC_INT128_LOCK_FREE

using namespace std;
using namespace boost::multiprecision;


void encryption_and_recording(vector <unsigned __int8>& simple_text, string file_name)
{
	unsigned __int64 p = 17, q = 19;
	unsigned __int64 module = p * q;  
	unsigned __int64 public_exhibitor = 151;
	unsigned __int64 private_exhibitor = 103;

	fstream encrypted_text;
	encrypted_text.open((file_name), fstream::binary | ios::out | ios::trunc);
	if (!encrypted_text.is_open()) {
		cerr << "Error, the file didn't open";
		exit(1);
	}
	else
	{
		char mark = '!';
		mark = ((unsigned __int64)pow(mark, 5)) % 35;// числа дл€ шифровани€ метки, примен€ютс€ только в функции verification_encryption_decryption и в этой функции
		encrypted_text.write((char*)&mark, sizeof(unsigned __int8));

		for (size_t i = 0; i < simple_text.size(); i++) {
			
			int1024_t  res;
			res  = (int1024_t)simple_text[i];
			res = pow(res, public_exhibitor);
			res = res % module;
			encrypted_text.write((char*)&res, sizeof(unsigned short int));
		}
	}
	encrypted_text.close();
	cout << "\n\n>>>  The text is encrypted  <<< \n\n";
	system("pause");
	
}




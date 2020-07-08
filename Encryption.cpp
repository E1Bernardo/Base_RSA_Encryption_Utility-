#include <iostream>
#include <vector>
#include<fstream>
#include<cmath>
#include <boost/multiprecision/cpp_int.hpp>


using namespace std;
using namespace boost::multiprecision;


void encryption_and_recording(vector <unsigned __int8>& simple_text, string file_name)
{
	setlocale(LC_ALL, "rus");
	unsigned __int64 p = 17, q = 19;
	unsigned __int64 module = p * q;
	unsigned short int public_exhibitor = 151, private_exhibitor = 103;
	int F = 76, E = 75; // разделение  public_exhibitor
	int1024_t first_half, second_half, data_digit, res;

	fstream encrypted_text;
	encrypted_text.open((file_name), fstream::binary | ios::out | ios::trunc);
	if (!encrypted_text.is_open()) {
		cerr << "Error, the file didn't open";
		exit(4);
	}
	else
	{
		char mark = '!';
		mark = ((unsigned __int64)pow(mark, 5)) % 35;// числа дл€ шифровани€ метки, примен€ютс€ только в функции verification_encryption_decryption и в этой функции
		encrypted_text.write((char*)&mark, sizeof(unsigned __int8));
		encrypted_text << " ";

		for (size_t i = 0; i < simple_text.size()-1; i++) {

			data_digit = simple_text[i];
			first_half = pow(data_digit, F);
			first_half = first_half % module;

			second_half = pow(data_digit, E);
			second_half = second_half % module;
	
			res = first_half* second_half;
			res = res % module;
			encrypted_text << res ;
			encrypted_text << " ";
		}
	}
	encrypted_text.close();
	cout << "\n\n>>>  The text is encrypted  <<< \n\n";
	system("pause");

}
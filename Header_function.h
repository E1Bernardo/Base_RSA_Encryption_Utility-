#ifndef RSA
#define RSA

#include <iostream>
#include <vector>

using namespace std;

struct Console_key
{
    string file_name;
    string optional_key; // выбор типа шифрования 
};

void check_console_input(Console_key& console_input, int argc, char* argv[]);//int argc, char* argv[]

int verification_encryption_decryption(string file_name);

int count_char_text(string file_name);

void reading_file(vector <unsigned __int8>& text, string file_name);

void encryption_and_recording(vector <unsigned __int8>& simple_text, string file_name);

void decryption_and_recording(vector <unsigned short int>& cipher_text_vector, string file_name);

void reading_file_encrypted_version(vector <unsigned short int>& text, string file_name);

#endif
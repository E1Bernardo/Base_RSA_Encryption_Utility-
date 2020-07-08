#ifndef RSA
#define RSA

using namespace std;

struct Console_key
{
    string file_name;
    string optional_key; // выбор типа шифрования 
};

void check_console_input(Console_key& console_input, int argc, char* argv[]);

int verification_encryption_decryption(string file_name);

void reading_simple_file(string file_name, std::vector <unsigned __int8> &simple_text);

void encryption_and_recording(std::vector <unsigned __int8>& simple_text, string file_name);

void reading_encrypted_file(string file_name, std::vector <string> &simple_text);

void string_to_number(std::vector <string>& encrypted_text, std::vector <int> &encrypted_digit_text);

void decryption_and_recording(std::vector <int> encrypted_digit_text, string file_name);

#endif
#include <iostream>
#include <vector>
#include"Header_function.h"
 

using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus");

    system("cls");
    cout << "Hello, this is a file encryption program !\n";
    Console_key console_input;
    check_console_input(console_input, argc, argv);

    int ñhecking_file_status = verification_encryption_decryption(console_input.file_name); // 1 - ôàéë çàøèôðîâàí  0 - ôàéë ïðîñòîé

    if (ñhecking_file_status == 0) {
        vector <unsigned __int8>simple_text;

        int choice_encryption;
        cout << "Warning, the file will now be encrypted\n\nIf you want to continue, press 1. To exit, press 0\n>>>   ";
        cin >> choice_encryption;

        if (choice_encryption == 1) {
            reading_simple_file(console_input.file_name, simple_text);
            encryption_and_recording(simple_text, console_input.file_name);
        }
        else if (choice_encryption == 0) {
            exit;
        }
    }
    else if (ñhecking_file_status == 1) {
        vector <string> encrypted_text;
        vector <int> encrypted_digit_text;

        int choice_decryption;
        cout << "Warning, the file will now be decrypted\n\nIf you want to continue, press 1. To exit, press 0\n>>>   ";
        cin >> choice_decryption;

        if (choice_decryption == 1) {
            reading_encrypted_file(console_input.file_name, encrypted_text);
            string_to_number(encrypted_text, encrypted_digit_text);

            decryption_and_recording(encrypted_digit_text, console_input.file_name);
        }
        else if (choice_decryption == 0) {
            exit;
        }
    }
}
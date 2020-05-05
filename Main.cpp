#include <iostream>
#include <vector>
#include"Header_function.h"


using namespace std;
// Аргумены 1- имя файла  2- ключ шифрования

int main(int argc, char* argv[]) 
{
    system("cls");
   cout << "Hello, this is a file encryption program !\n";
   Console_key console_input;

   check_console_input(console_input, argc, argv);

   int сhecking_file_status = verification_encryption_decryption(console_input.file_name); // 1 - файл зашифрован  0 - файл простой

    if (сhecking_file_status == 0){
        vector <unsigned __int8>simple_text(count_char_text(console_input.file_name));

        int choice_encryption;
        cout << "Warning, the file will now be encrypted\n\nIf you want to continue, press 1. To exit, press 0\n>>>   ";
        cin >> choice_encryption;

        if (choice_encryption == 1) {
            reading_file(simple_text, console_input.file_name);
            encryption_and_recording(simple_text, console_input.file_name);
        }
        else if(choice_encryption == 0) {
            exit;
        }
    }
    else if (сhecking_file_status == 1){
       // vector <unsigned __int8>cipher_text(count_char_text(console_input.file_name));
        vector <unsigned short int>cipher_text(count_char_text(console_input.file_name));
        int choice_decryption;
        cout << "Warning, the file will now be decrypted\n\nIf you want to continue, press 1. To exit, press 0\n>>>   ";
        cin >> choice_decryption;

        if (choice_decryption == 1) {
            //reading_file(cipher_text, console_input.file_name);
            reading_file_encrypted_version(cipher_text, console_input.file_name);
            decryption_and_recording(cipher_text, console_input.file_name);
        }
        else if (choice_decryption == 0) {
            exit;
        }
    }
}
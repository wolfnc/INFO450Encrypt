//
//  main.cpp
//  a5
//
//  Created by Noah Wolf on 12/7/19.
//  Copyright © 2019 Noah Wolf. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

void encrypt(char* ifile, char* ofile);
void decrypt(char* ifile, char* ofile);
char cipher(char ch, int key);
char decipher(char ch, int key);

//Displays menu and checks if user wants to re-run the program or exit after first run
int main()
{
         int procede;
         int again;
         char inputFile[40];
         char outputFile[40];
    
         do
         {
              cout << "---------------------------------------------\n";
              cout << "Please enter a 1 or 2 to select from the menu\n";
              cout << "---------------------------------------------\n";
              cout << "1) Encrypt a file\n";
              cout << "2) Decrypt a file\n";
              cout << "3) Press any key besides 1 or 2 to exit\n";
              cin >> procede;

              if (procede == 1)
              {
                  cout << "\n";
                  cout << "Enter the input file path with file extension ('.txt')\n";
                  cin >> inputFile;
                  cout << "Enter the output file path with file extension\n";
                  cin >> outputFile;
                  encrypt(inputFile, outputFile);
                  cout << "Your file was successfully encrypted!\n";
              }
              else if (procede == 2)
              {
                  cout << "\n";
                  cout << "Enter the input file path with file extension ('.txt')\n";
                  cin >> inputFile;
                  cout << "Enter the output file path with file extension ('.txt')\n";
                  cin >> outputFile;
                  decrypt(inputFile, outputFile);
                  cout << "Your file was successfully decrypted!\n";
              }
              else
              {
                  return 0;
              }

              cout << "Please enter a 1 or an 2\n\n";
              cout << "1) Encrypt/Decrypt more files\n";
              cout << "2) Exit\n";
              cin >> again;

         } while (again != 2);
    
     return 0;
}

//Function checks if files open and uses cipher function to encrypt input file
void encrypt(char* ifile, char* ofile)
{
     int key;
     char ch;
     ofstream out(ofile);
     ifstream in(ifile);
     
     cout << "Enter the key (number) you would like to encrypt your file with\n";
     cin >> key;

     if (!out)
     {
          cout << "ERROR: Cannot open output file!\n";
          return;
     }

     if (!in)
     {
          cout << "ERROR: Cannot open input file!\n";
          return;
     }

     while (in)
     {
              in.get(ch);
              if (in)
              {
                   ch = cipher(ch, key);
                   out << ch;
              }
          }
}

//Function checks if files can open and uses decipher function to decrypt input file
void decrypt(char* ifile, char* ofile)
{
     int key;
     char ch;
     ofstream out(ofile);
     ifstream in(ifile);
     

     cout << "For decryption, please enter the same key used to encrypt your file\n";
     cin >> key;

     if (!out)
     {
          cout << "ERROR: Cannot open output file!\n";
          return;
     }

     if (!in)
     {
          cout << "ERROR: Cannot open input file!\n";
          return;
     }

     while (in)
     {
          in.get(ch);

              if (in)
              {
                   ch = decipher(ch, key);
                   out << ch;
              }
     }
}

//Cipher function to encrypt the file by character
char cipher(char ch, int key)
{
        if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'A') && (ch <= 'Z')))
        {
            ch = (ch - 'A' + key) % 26 + 'A';
        }
     
    return ch;
}

//Function to decrypt the file by character
char decipher(char ch, int key)
{
     cout << ch;

        if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'A') && (ch <= 'Z')))
        {
            ch = 'Z' - ('Z' - ch + key) % 26;
        }
    
    return ch;
}

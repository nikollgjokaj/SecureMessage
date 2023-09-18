# SecureMessage
Communicate encrypted and decrypt messages with SecureMessage (XOR method)


# Encryption/Decryption Program

This is a simple command-line program for encrypting and decrypting text files using the XOR operation. The program offers a basic user interface and allows you to choose between encryption and decryption operations. It is written in C++ and can be compiled and executed on Unix/Linux systems. Here's how to use it:
Features

    Encrypt and decrypt text files using XOR encryption.
    User-friendly command-line interface.
    Ability to specify input and output file names.
    Securely clear the screen for a clean look.

Prerequisites

    A Unix/Linux environment.
    C++ compiler (e.g., g++).

Installation

Clone this repository:
            
    git clone git@github.com:nixknameee/SecureMessage.git




Compile the program:


    g++ securemessage.cpp

Usage

    Run the program:


    ./a.out

    Choose your operation:
        Enter E or e to encrypt a file.
        Enter D or d to decrypt a file.
        Enter Q or q to quit the program.

    Provide the requested information:
        Input file name (the file you want to encrypt or decrypt).
        Output file name (the resulting file after encryption or decryption).
        Encryption key (a string to use for encryption/decryption).

    The program will perform the selected operation and display a success message.

Example

Here's an example of how to use the program:


Welcome to the Encryption/Decryption Program

Do you want to encrypt (E) or decrypt (D), or quit (Q)? E
Enter the input file name: input.txt
Enter the output file name: encrypted.txt
Enter an encryption key: mysecretkey
Operation completed.

Notes

    The program clears the screen for a clean look using the system("clear") command. If you're using Windows, you can uncomment system("cls") and comment out system("clear").

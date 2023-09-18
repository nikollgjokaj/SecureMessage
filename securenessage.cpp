#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function for encryption
string encrypt(const string& input, const string& key) {
    string output = input;
    for (size_t i = 0; i < input.size(); ++i) {
        output[i] = input[i] ^ key[i % key.size()];
    }
    return output;
}

// Function for decryption
string decrypt(const string& input, const string& key) {
    return encrypt(input, key); // Decryption is identical to encryption in XOR.
}

int main() {
    string inputFileName, outputFileName, key;
    char choice;

    do {
        cout << "Do you want to encrypt (E) or decrypt (D)? ";
        cin >> choice;
        cin.ignore(); // Ignore any extra characters, including newlines

        if (choice == 'E' || choice == 'e' || choice == 'D' || choice == 'd') {
            break; // Valid choice, exit the loop.
        } else {
            cerr << "Invalid choice. Please choose 'E' for encryption or 'D' for decryption." << endl;
        }
    } while (true);

    cout << "Enter the input file name: ";
    getline(cin, inputFileName); // Use getline to read the entire line

    cout << "Enter the output file name: ";
    getline(cin, outputFileName);

    cout << "Enter an encryption key: ";
    getline(cin, key);

    // Read file
    ifstream inputFile(inputFileName);
    if (!inputFile) {
        cerr << "Error opening the input file." << endl;
        return 1;
    }

    string fileContents((istreambuf_iterator<char>(inputFile)), (istreambuf_iterator<char>()));
    inputFile.close();

    string resultText;

    if (choice == 'E' || choice == 'e') {
        // Encrypt
        resultText = encrypt(fileContents, key);
    } else if (choice == 'D' || choice == 'd') {
        // Decrypt
        resultText = decrypt(fileContents, key);
    } else {
        cerr << "Invalid choice. Please choose 'E' for encryption or 'D' for decryption." << endl;
        return 1;
    }

    // Write text to output file
    ofstream outputFile(outputFileName);
    if (!outputFile) {
        cerr << "Error opening the output file." << endl;
        return 1;
    }

    outputFile << resultText;
    outputFile.close();

    cout << "Operation completed." << endl;

    return 0;
}

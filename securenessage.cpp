#include <iostream>
#include <fstream>
#include <string>
#include <limits> // Für die Eingabeüberprüfung
#include <cstdlib> // Für das Löschen des Bildschirms

using namespace std;

// Funktion für die Verschlüsselung
string encrypt(const string& input, const string& key) {
    string output = input;
    for (size_t i = 0; i < input.size(); ++i) {
        output[i] = input[i] ^ key[i % key.size()];
    }
    return output;
}

// Funktion für die Entschlüsselung
string decrypt(const string& input, const string& key) {
    return encrypt(input, key); // Entschlüsselung ist identisch mit Verschlüsselung in XOR.
}

// Funktion, um den Bildschirm zu löschen
void clearScreen() {
    system("clear"); // Für Unix/Linux
    // system("cls"); // Für Windows
}

int main() {
    string inputFileName, outputFileName, key;
    char choice;

    clearScreen(); // Löschen Sie den Bildschirm, um einen "sauberen" Look zu erhalten

    cout << "\033[1;32mWelcome to the Encryption/Decryption Program\033[0m" << endl; // Verwenden Sie grüne Schriftfarbe für die Überschrift

    do {
        cout << "Do you want to \033[1;34mencrypt (E)\033[0m or \033[1;34mdecrypt (D)\033[0m, or \033[1;31mquit (Q)\033[0m? ";
        cin >> choice;
        cin.ignore(); // Ignorieren Sie zusätzliche Zeichen, einschließlich Zeilenumbrüchen

        if (choice == 'Q' || choice == 'q') {
            cout << "\033[1;31mOperation canceled.\033[0m" << endl;
            return 0;
        } else if (choice == 'E' || choice == 'e' || choice == 'D' || choice == 'd') {
            break; // Gültige Auswahl, die Schleife verlassen.
        } else {
            cout << "\033[1;31mInvalid choice. Please enter \033[1;34m'E'\033[0m for encryption, \033[1;34m'D'\033[0m for decryption, or \033[1;31m'Q'\033[0m to quit.\n";
        }
    } while (true);

    cout << "Enter the input file name: ";
    getline(cin, inputFileName);

    cout << "Enter the output file name: ";
    getline(cin, outputFileName);

    cout << "Enter an encryption key: ";
    getline(cin, key);

    ifstream inputFile(inputFileName);
    if (!inputFile) {
        cerr << "\033[1;31mError opening the input file.\033[0m" << endl;
        return 1;
    }

    string fileContents((istreambuf_iterator<char>(inputFile)), (istreambuf_iterator<char>()));
    inputFile.close();

    string resultText;

    if (choice == 'E' || choice == 'e') {
        resultText = encrypt(fileContents, key);
    } else if (choice == 'D' || choice == 'd') {
        resultText = decrypt(fileContents, key);
    }

    ofstream outputFile(outputFileName);
    if (!outputFile) {
        cerr << "\033[1;31mError opening the output file.\033[0m" << endl;
        return 1;
    }

    outputFile << resultText;
    outputFile.close();

    clearScreen(); // Löschen Sie den Bildschirm, um einen "sauberen" Look zu erhalten
    cout << "\033[1;32mOperation completed.\033[0m" << endl;

    return 0;
}


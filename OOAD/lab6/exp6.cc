#include <iostream>
#include <string>

using namespace std;

string encryptRot13(const string& text) {
    string result = text;

    for (char& ch : result) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            ch = (ch - base + 13) % 26 + base;
        }
    }

    return result;
}

string decryptRot13(const string& text) {
    return encryptRot13(text);
}

int main() {

    string inputMessage = "OOAD lab";

    cout << "Original message: " << inputMessage << endl;

    string encryptedMessage = encryptRot13(inputMessage);
    cout << "Encrypted message: " << encryptedMessage << endl;

  
    string decryptedMessage = decryptRot13(encryptedMessage);
    cout << "Decrypted message: " << decryptedMessage << endl;

    return 0;
}
	

#include <bits/stdc++.h>
using namespace std;

string encrypt(string plain, int k) {
    stringstream cipher;
    for (int i = 0; i < plain.length(); i++) {
        if (plain[i] != ' ') {
            cipher << char((plain[i] - 'a' + k) % 26 + 'a');
        } else {
            cipher << ' ';
        }
    }
    return cipher.str();
}

string decrypt(string cipher, int k) {
    stringstream plain;
    for (int i = 0; i < cipher.length(); i++) {
        if (cipher[i] != ' ') {
            plain << char((cipher[i] - 'a' - k + 26) % 26 + 'a');
        }
    }
    return plain.str();
}

int main() {

    int choice;

    cout << "Enter choice: \n1. Decrypt \n2. Encrypt\n";

    cin >> choice;
    cin.get();
    string plain, cipher;
    int k;
    if (choice == 1) {
        cout << "Enter Encrypted text: ";
        getline(cin, cipher);
        cout << "Enter K: ";
        cin >> k;
        string plain = decrypt(cipher, k);
        cout << "Decrypted text is: " << plain << endl;
    } else if (choice == 2) {
        cout << "Enter Plain text: ";
        getline(cin, plain);
        cout << "Enter K: ";
        cin >> k;
        string cipher = encrypt(plain, k);
        cout << "\nEncrypted text is: " << cipher << endl;
    }

    return 0;
}
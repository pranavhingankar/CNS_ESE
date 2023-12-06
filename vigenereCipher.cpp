#include <bits/stdc++.h>
using namespace std;

string format(string &str) {
    stringstream res;
    for (auto &ch : str) {
        if (ch != ' ') {
            res << (char)tolower(ch);
        }
    }
    return res.str();
}

string encrypt(string &plain, string &key) {
    stringstream cipher;
    for (int i = 0; i < plain.size(); i++) {
        int val = plain[i] - 'a' + key[i % (key.size())] - 'a';
        cipher << (char)('a' + (val % 26));
    }
    return cipher.str();
}

string decrypt(string &cipher, string &key) {
    stringstream plain;
    for (int i = 0; i < cipher.size(); i++) {
        int val = cipher[i] - 'a' - (key[i % (key.size())] - 'a');
        plain << (char)('a' + (val + 26) % 26);
    }
    return plain.str();
}

int main() {
    int choice;
    cout << "1. Encrypt\n2. Decrypt\nEnter your choice: ";
    cin >> choice;
    cin.get();

    if (choice == 1) {
        string plain, key;
        cout << "\nEnter plain text: ";
        getline(cin, plain);
        plain = format(plain);

        cout << "\nEnter key: ";
        getline(cin, key);

        string cipher = encrypt(plain, key);

        cout << "\nEncrypted text is : " << cipher << endl;
    } else if (choice == 2) {
        string cipher, key;
        cout << "\nEnter cipher text: ";
        getline(cin, cipher);
        cipher = format(cipher);

        cout << "\nEnter key: ";
        getline(cin, key);

        string plain = decrypt(cipher, key);

        cout << "\nDecrypted text is : " << plain << endl;
    }

    return 0;
}

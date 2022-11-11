#include <iostream>
using namespace std;

// encode to caesar cipher 
string encode(string text, int key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i])) {
            result += char(int(text[i] + key - 65) % 26 + 65);
        } else {
            result += char(int(text[i] + key - 97) % 26 + 97);
        }
    }
    return result;
}

// decode from caesar cipher
string decode(string text, int key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i])) {
            result += char(int(text[i] - key - 65) % 26 + 65);
        } else {
            result += char(int(text[i] - key - 97) % 26 + 97);
        }
    }
    return result;
}

int main() {
    int shift = 3;

    // get actual username and password
    string user, pass;
    cout << "Enter username: ";
    cin >> user; // get username
    cout << "Enter password: ";
    cin >> pass; // get password
    cout << "Encrypted password: " << encode(pass, shift) << endl; // display encrypted password

    // login with 3 attempts
    string uname, upass;
    int tries = 3;
    while (tries--) {
        cout << "Enter username: ";
        cin >> uname; // get username
        cout << "Enter password: ";
        cin >> upass; // get password
        if (uname == user && decode(upass, shift) == pass) { // check if username and password are correct
            cout << "Login successful!" << endl; // display login successful
            break; // break out of loop
        } else if (tries == 0) { // check if tries is 0
            cout << "Login failed!" << endl; // display login failed
            exit(0); // exit program
        } else {
            cout << "Login failed! " << tries << " tries left." << endl; // display login failed and tries left
        }
    }
}
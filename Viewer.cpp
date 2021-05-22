#include "Viewer.h"

void Viewer::login(string& username, string& password)
{
	cout << "  _                _" << endl;
	cout << " | |  ___    __ _ (_) _ __" << endl;
	cout << " | | / _ \\ /  _  || ||  _ \\" << endl;
	cout << " | || (_) || (_| || || | | |" << endl;
	cout << " |_| \\___/ \\__,  ||_||_| |_|" << endl;
	cout << "           |___ /" << endl;
	cout << "\nUsername: ";
	cin >> username;
	cout << "Password: ";
    char pass[32];
    char tmp;
    int i = 0;
    for (i = 0;;) {
        tmp = _getch();
        if ((tmp >= 'a' && tmp <= 'z') || (tmp >= 'A' && tmp <= 'Z') || (tmp >= '0' && tmp <= '9')) {
            pass[i] = tmp;
            ++i;
            cout << "*";
        }
        if (tmp == '\b' && i >= 1) { //if user typed backspace (i should be greater than 1)
            cout << "\b \b";//rub the character behind the cursor
            --i;
        }
        if (tmp == '\r') { //if enter is pressed
            pass[i] = '\0';//null means end of string
            break;
        }
    }
    password = pass;
}

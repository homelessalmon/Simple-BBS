#include "Viewer.h"

int Viewer::menu()
{
    cout << " _ __ ___    ___  _ __   _   _" << endl;
    cout << "| '_ ` _ \\  / _ \\| '_ \\ | | | |" << endl;
    cout << "| | | | | ||  __/| | | || |_| |" << endl;
    cout << "|_| |_| |_| \\___||_| |_| \\__,_|\n" << endl;
    cout << "1. Log in" << endl;
    cout << "2. Sign up" << endl;
    cout << "3. Guest" << endl;
    cout << "0. Exit\n" << endl;
    cout << ">";
    int n;
    cin >> n;
    return n;
}

int Viewer::login(string& username, string& password)
{
    cout << "  _                _" << endl;
    cout << " | |  ___    __ _ (_) _ __" << endl;
    cout << " | | / _ \\ /  _  || ||  _ \\" << endl;
    cout << " | || (_) || (_| || || | | |" << endl;
    cout << " |_| \\___/ \\__,  ||_||_| |_|" << endl;
    cout << "           |___ /\n" << endl;
    cout << "Back to menu: 0\n>";
    char n;
    cin >> n;
    if (n == '0') return 0;
    while ((n = getchar()) != '\n'); //clear the buffer

    system("cls");
    cout << "  _                _" << endl;
    cout << " | |  ___    __ _ (_) _ __" << endl;
    cout << " | | / _ \\ /  _  || ||  _ \\" << endl;
    cout << " | || (_) || (_| || || | | |" << endl;
    cout << " |_| \\___/ \\__,  ||_||_| |_|" << endl;
    cout << "           |___ /\n" << endl;
    cout << "Username: ";
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
    return 1;
}

int Viewer::signup(string& username, string& password)
{
    cout << "       _                                " << endl;
    cout << "      (_)                               " << endl;
    cout << "  ___  _   __ _  _ __      _   _  _ __  " << endl;
    cout << " / __|| | / _` || '_ \\    | | | || '_ \\ " << endl;
    cout << " \\__ \\| || (_| || | | |   | |_| || |_) |" << endl;
    cout << " |___/|_| \\__, ||_| |_|    \\__,_|| .__/ " << endl;
    cout << "           __/ |                 | |    " << endl;
    cout << "          |___/                  |_|    \n" << endl;
    cout << "Back to menu: 0\n>";
    char n;
    cin >> n;
    if (n == '0') return 0;
    while ((n = getchar()) != '\n'); //clear the buffer

    system("cls");
    cout << "       _                                " << endl;
    cout << "      (_)                               " << endl;
    cout << "  ___  _   __ _  _ __      _   _  _ __  " << endl;
    cout << " / __|| | / _` || '_ \\    | | | || '_ \\ " << endl;
    cout << " \\__ \\| || (_| || | | |   | |_| || |_) |" << endl;
    cout << " |___/|_| \\__, ||_| |_|    \\__,_|| .__/ " << endl;
    cout << "           __/ |                 | |    " << endl;
    cout << "          |___/                  |_|    \n" << endl; 
    cout << "Username: ";
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
    return 1;
}

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
	cin >> password;
}

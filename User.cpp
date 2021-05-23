#include "User.h"

Adiministrator::Adiministrator(string user_name, string user_password)
{
	ifstream fin("users/count.txt");
	int count; fin >> count; fin.close();

	ofstream fout("users/count.txt", ios::out || ios::trunc); fout << count + 1; fout.flush(); fout.close();
	system(("cd.>users/" + to_string(count + 1) + ".txt").c_str());

	fout.open("users/" + to_string(count + 1) + ".txt", ios::out || ios::trunc);
	fout << user_name << endl << user_password << endl << 2 << endl;
	fout.flush(); fout.close();
}

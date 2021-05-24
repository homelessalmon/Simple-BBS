#include "User.h"
#include<iostream>

Adiministrator::Adiministrator(string user_name, string user_password)
{
	ifstream fin("users/count.txt");
	int count; fin >> count; fin.close();

	user_id = count + 1;

	ofstream fout("users/count.txt", ios::out || ios::trunc); fout << count + 1; fout.flush(); fout.close();
	system(("cd.>users/" + to_string(count + 1) + ".txt").c_str());

	fout.open("users/" + to_string(count + 1) + ".txt", ios::out || ios::trunc);
	fout << user_name << endl << user_password << endl << user_id << endl << 2 << endl;
	fout.flush(); fout.close();
}

Member::Member(string user_name, string user_password)
{
	ifstream fin("users/count.txt");
	int count; fin >> count; fin.close();

	user_id = count + 1;

	ofstream fout("users/count.txt", ios::out || ios::trunc); fout << count + 1; fout.flush(); fout.close();
	system(("cd.>users/" + to_string(count + 1) + ".txt").c_str());

	fout.open("users/" + to_string(count + 1) + ".txt", ios::out || ios::trunc);
	fout << user_name << endl << user_password << endl << user_id << endl << 1 << endl;
	fout.flush(); fout.close();
}

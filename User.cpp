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

Adiministrator::Adiministrator(vector<int> _postsID, int _user_id)
{
	postsID = _postsID;
	user_id = _user_id;
	Permission_level = 2;
}

void Adiministrator::add_board(string board_name)
{
	ifstream fin("boards/count.txt");
	int count; fin >> count; fin.close();

	ofstream fout("boards/count.txt", ios::out || ios::trunc);
	fout << count + 1; fout.close();

	system(("cd.>boards/" + to_string(count) + ".txt").c_str());

	fout.open("boards/" + to_string(count) + ".txt", ios::trunc || ios::out);
	fout << board_name << endl;
	fout.close();
}

void Adiministrator::add_post(int current_board)
{
	ifstream fin("posts/count.txt");
	int count; fin >> count; fin.close();

	ofstream fout("posts/count.txt", ios::out || ios::trunc);
	fout << count + 1; fout.close();

	system(("cd.>posts/" + to_string(count) + "title.txt").c_str());
	system(("posts\\" + to_string(count) + "title.txt").c_str());

	system(("cd.>posts/" + to_string(count) + "content.txt").c_str());
	system(("posts\\" + to_string(count) + "content.txt").c_str());

	system(("cd.>posts/" + to_string(count) + "comment.txt").c_str());

	fout.open("users/" + to_string(user_id) + ".txt", ios::app);
	fout << count << endl; fout.close();

	fout.open("boards/" + to_string(current_board) + ".txt", ios::app);
	fout << count << endl; fout.close();
	
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

Member::Member(vector<int> _postsID, int _user_id)
{
	postsID = _postsID;
	user_id = _user_id;
	Permission_level = 1;
}

void Member::add_post(int current_board)
{
	ifstream fin("posts/count.txt");
	int count; fin >> count; fin.close();

	ofstream fout("posts/count.txt", ios::out || ios::trunc);
	fout << count + 1; fout.close();

	system(("cd.>posts/" + to_string(count) + "title.txt").c_str());
	system(("posts\\" + to_string(count) + "title.txt").c_str());

	system(("cd.>posts/" + to_string(count) + "content.txt").c_str());
	system(("posts\\" + to_string(count) + "content.txt").c_str());

	system(("cd.>posts/" + to_string(count) + "comment.txt").c_str());

	fout.open("users/" + to_string(user_id) + ".txt", ios::app);
	fout << count << endl; fout.close();

	fout.open("boards/" + to_string(current_board) + ".txt", ios::app);
	fout << count << endl; fout.close();
}

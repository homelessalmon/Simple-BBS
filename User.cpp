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

void Adiministrator::edit_board(int board_id, string new_name)
{
	ifstream fin("boards/" + to_string(board_id) + ".txt");
	if (fin.is_open())
	{
		vector<int> _post_list; string tmp1; int tmp2;
		fin >> tmp1;
		while (fin >> tmp2)
		{
			_post_list.push_back(tmp2);
		}

		ofstream fout("boards/" + to_string(board_id) + ".txt", ios::trunc);
		if (fout.is_open())
		{
			fout << new_name << endl;
			for (int i = 0; i < _post_list.size(); i++)
			{
				fout << _post_list[i] << endl;
			}
		}
		fout.close();
	}
	fin.close();
	
}

void Adiministrator::remove_board(int board_id)
{
	ifstream fin("board/" + to_string(board_id) + ".txt");
	if (fin.is_open())
	{
		fin.close();
		system(("del board\\" + to_string(board_id) + ".txt").c_str());
	}
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

void Adiministrator::edit_post(int post_id, int part_select)
{
	switch (part_select)
	{
	case 0:
		system(("posts\\" + to_string(post_id) + "title.txt").c_str());
		break;
	case 1:
		system(("posts\\" + to_string(post_id) + "content.txt").c_str());
		break;
	default:
		break;
	}
}

void Adiministrator::remove_post(int post_id)
{
	ifstream fin("posts/" + to_string(post_id) + "title.txt");
	if (fin.is_open())
	{
		system(("del post\\" + to_string(post_id) + "title.txt").c_str());
		system(("del post\\" + to_string(post_id) + "content.txt").c_str());
		system(("del post\\" + to_string(post_id) + "comment.txt").c_str());
	}
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

void Member::edit_post(int post_id, int part_select)
{
	switch (part_select)
	{
	case 0:
		system(("posts\\" + to_string(post_id) + "title.txt").c_str());
		break;
	case 1:
		system(("posts\\" + to_string(post_id) + "content.txt").c_str());
		break;
	default:
		break;
	}
}

void Member::remove_post(int post_id)
{
	ifstream fin("posts/" + to_string(post_id) + "title.txt");
	if (fin.is_open())
	{
		system(("del post\\" + to_string(post_id) + "title.txt").c_str());
		system(("del post\\" + to_string(post_id) + "content.txt").c_str());
		system(("del post\\" + to_string(post_id) + "comment.txt").c_str());
	}
}

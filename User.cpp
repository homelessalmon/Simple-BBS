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

void Adiministrator::remove_board(int board_id, string reason)
{
	ofstream fout("boards/" + to_string(board_id) + ".txt", ios::trunc);
	if (fout.is_open())
	{
		fout << REMOVE << endl << reason;
	}
	fout.close();
}

void Adiministrator::add_post(int current_board, string title_name)
{
	ifstream fin("posts/count.txt");
	int count; fin >> count; fin.close();

	ofstream fout("posts/count.txt", ios::trunc);
	fout << count + 1; fout.close();

	system(("cd.>posts/" + to_string(count) + "title.txt").c_str());
	fout.open("posts/" + to_string(count) + "title.txt", ios::trunc);
	fout << title_name;
	fout.close();

	system(("cd.>posts/" + to_string(count) + "content.txt").c_str());
	system(("posts\\" + to_string(count) + "content.txt").c_str());

	system(("cd.>posts/" + to_string(count) + "comment.txt").c_str());

	fout.open("users/" + to_string(user_id) + ".txt", ios::app);
	fout << count << endl; fout.close();

	fout.open("boards/" + to_string(current_board) + ".txt", ios::app);
	fout << count << endl; fout.close();
	
}

void Adiministrator::edit_post_title(int post_id, string new_title)
{
	ofstream fout("posts/" + to_string(post_id) + "title.txt", ios::trunc);
	if (fout.is_open())
	{
		fout << new_title;
	}
	fout.close();
}

void Adiministrator::edit_post_content(int post_id)
{
	system(("posts\\" + to_string(post_id) + "content.txt").c_str());
}

void Adiministrator::remove_post(int post_id, string reason)
{
	ofstream fout("posts/" + to_string(post_id) + "title.txt", ios::trunc);
	if (fout.is_open())
	{
		fout << REMOVE << endl;
	}
	fout.close();

	fout.open("posts/" + to_string(post_id) + "content.txt", ios::trunc);
	if (fout.is_open())
	{
		fout << "Sorry this post has been removed." << endl;
		fout << "Reason: " << reason;
	}
	fout.close();
	fout.open("posts/" + to_string(post_id) + "comment.txt", ios::trunc);
	fout.close();
}

void Adiministrator::add_comment(int post_id, int current_userID, string text)
{
	string name;

	ifstream fin("users/" + to_string(current_userID) + ".txt");
	if (fin.is_open())fin >> name;
	fin.close();

	ofstream fout("posts/" + to_string(post_id) + "comment.txt", ios::app);
	fout << name + " " + text << endl;
	fout.close();
}

void Adiministrator::remove_comment(int post_id, int order, string reason)
{
	vector<string> list;
	string tmp;
	ifstream fin("posts/" + to_string(post_id) + "comment.txt");
	while (getline(fin, tmp)) { list.push_back(tmp); }

	if (order < list.size())
	{
		list[order] = REMOVE + " " + reason;
	}

	ofstream fout("posts/" + to_string(post_id) + "comment.txt", ios::trunc);
	for (int i = 0; i < list.size(); i++)
	{
		fout << list[i] << endl;
	}
	fout.close();
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

void Member::add_post(int current_board, string title_name)
{
	ifstream fin("posts/count.txt");
	int count; fin >> count; fin.close();

	ofstream fout("posts/count.txt", ios::trunc);
	fout << count + 1; fout.close();

	system(("cd.>posts/" + to_string(count) + "title.txt").c_str());
	fout.open("posts/" + to_string(count) + "title.txt", ios::trunc);
	fout << title_name;
	fout.close();

	system(("cd.>posts/" + to_string(count) + "content.txt").c_str());
	system(("posts\\" + to_string(count) + "content.txt").c_str());

	system(("cd.>posts/" + to_string(count) + "comment.txt").c_str());

	fout.open("users/" + to_string(user_id) + ".txt", ios::app);
	fout << count << endl; fout.close();

	fout.open("boards/" + to_string(current_board) + ".txt", ios::app);
	fout << count << endl; fout.close();
}

void Member::edit_post_title(int post_id, string new_title)
{
	ofstream fout("posts/" + to_string(post_id) + "title.txt", ios::trunc);
	if (fout.is_open())
	{
		fout << new_title;
	}
	fout.close();
}

void Member::edit_post_content(int post_id)
{
	system(("posts\\" + to_string(post_id) + "content.txt").c_str());
}

void Member::remove_post(int post_id, string reason)
{
	ofstream fout("posts/" + to_string(post_id) + "title.txt", ios::trunc);
	if (fout.is_open())
	{
		fout << REMOVE << endl;
	}
	fout.close();

	fout.open("posts/" + to_string(post_id) + "content.txt", ios::trunc);
	if (fout.is_open())
	{
		fout << "Sorry this post has been removed." << endl;
		fout << "Reason:  " << reason;
	}
	fout.close();
	fout.open("posts/" + to_string(post_id) + "comment.txt", ios::trunc);
	fout.close();
}

void Member::add_comment(int post_id, int current_userID, string text)
{
	string name;

	ifstream fin("users/" + to_string(current_userID) + ".txt");
	if (fin.is_open())fin >> name;
	fin.close();

	ofstream fout("posts/" + to_string(post_id) + "comment.txt", ios::app);
	fout << name + " " + text << endl;
	fout.close();
}

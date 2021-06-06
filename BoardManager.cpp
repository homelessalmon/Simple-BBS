#include "BoardManager.h"

void BoardManager::load_user()
{
	ifstream fin("users/count.txt");
	int user_count; fin >> user_count; fin.close();

	users.clear();

	for (int i = 0; i < user_count + 1; i++)
	{
		fin.open("users/" + to_string(i) + ".txt");
		if (fin.is_open())
		{
			string u_name, u_password; int u_id, u_permission, tmp ; vector<int> u_post_id;
			fin >> u_name >> u_password >> u_id >> u_permission;
			while (fin >> tmp) { u_post_id.push_back(tmp); }
			if (u_permission == 2)
			{
				Adiministrator* tmp2 = new Adiministrator(u_post_id, u_id);
				users.push_back(tmp2);
			}
			else
			{
				Member* tmp2=new Member(u_post_id, u_id);
				users.push_back(tmp2);
			}
			u_post_id.clear();
		}
		fin.close();
	}
}

void BoardManager::load_board()
{
	ifstream fin("boards/count.txt");
	int board_count; fin >> board_count; fin.close();

	boards.clear();

	for (int i = 0; i < board_count; i++)
	{
		fin.open("boards/" + to_string(i) + ".txt");
		if (fin.is_open())
		{
			string _board_name; int tmp; vector<int> post_id;
			getline(fin, _board_name);
			if (_board_name != REMOVE)
			{
				while (fin >> tmp) { post_id.push_back(tmp); }

				Board* tmp2 = new Board(post_id, _board_name);
				boards.push_back(*(tmp2));
				post_id.clear();
			}
			else
			{
				getline(fin, _board_name);
				Board* tmp2 = new Board(post_id, _board_name);
				tmp2->is_removed = true;
				boards.push_back(*(tmp2));
				post_id.clear();
			}
		}
		fin.close();
	}
}

void BoardManager::load_mail()
{
	int mail_count = 0;
	ifstream fin("mails/count.txt");
	if (fin.is_open())
	{
		fin >> mail_count;
	}
	fin.close();

	for (int i = 0; i < mail_count; i++)
	{
		fin.open("mails/" + to_string(i) + "info.txt");
		if (fin.is_open())
		{
			string catch_string;
			int id;
			fin >> catch_string >> id;

			if (id == current_user)
			{
				fin >> catch_string;

				string tmp;
				vector<string> tmp_vector;
				ifstream fin2("mails/" + to_string(i) + "content.txt");
				if (fin2.is_open())
				{
					while (getline(fin2, tmp)) { tmp_vector.push_back(tmp); }
				}
				fin2.close();

				Mail aPost(catch_string, tmp_vector);
				users[current_user]->mail_list.push_back(aPost);
			}
		}
		fin.close();
	}
}

vector<pair<string, string>> BoardManager::return_name_and_password()
{
	vector<pair<string, string>> return_list;
	for (int i = 0; i < users.size(); i++)
	{
		ifstream fin("users/" + to_string(i) + ".txt");
		if (fin.is_open())
		{
			string name, password;
			fin >> name >> password;
			pair<string, string> tmp(name, password);
			return_list.push_back(tmp);
		}
		fin.close();
	}
	return return_list;
}

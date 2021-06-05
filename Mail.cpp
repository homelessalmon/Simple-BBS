#include "Mail.h"

Mail::Mail(string _from, vector<string> _content)
{
	from = _from;
	content = _content;
}

bool send_mail(string receiver_user_name, int sender_user_id)//return false if receiver not found
{
	ifstream fin("users/count.txt");
	int user_count, receiver_user_id = -1;
	fin >> user_count;
	fin.close();

	bool is_find = false;
	for (int i = 0; i <= user_count; i++)
	{
		fin.open("users/" + to_string(i) + ".txt");
		if (fin.is_open())
		{
			string name;
			fin >> name;
			if (name == receiver_user_name)
			{
				is_find = true;
				if (is_find)
				{
					receiver_user_id = i;
					fin.close();
					break;
				}
			}
		}
		fin.close();
	}

	if (!is_find)return false;
	else
	{
		fin.open("mails/count.txt");
		int mail_count = 0;
		if (fin.is_open())
		{
			fin >> mail_count;
		}
		fin.close();

		ofstream fout("mails/count.txt", ios::trunc);
		fout << mail_count + 1;
		fout.close();

		system(("cd.>mails/" + to_string(mail_count) + "info.txt").c_str());
		fin.open("users/" + to_string(sender_user_id) + ".txt");
		string sender_name;
		fin >> sender_name;
		fin.close();

		fout.open("mails/" + to_string(mail_count) + "info.txt", ios::trunc);
		if (fout.is_open())
		{
			fout << receiver_user_name << " " << receiver_user_id << endl;
			fout << sender_name << " " << sender_user_id;
		}
		fout.close();

		system(("cd.>mails/" + to_string(mail_count) + "content.txt").c_str());
		system(("mails\\" + to_string(mail_count) + "content.txt").c_str());

		return true;
	}
}



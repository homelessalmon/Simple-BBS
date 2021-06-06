#pragma once
#include<string>
#include<vector>
#include<fstream>

using namespace std;

class Mail
{
public:
	string from;
	string title;
	vector<string> content;

	Mail() { }
	Mail(string _from, string _title, vector<string> _content);
	
};

bool send_mail(string receiver_user_name, int sender_user_id, string title);//return false if receiver not found

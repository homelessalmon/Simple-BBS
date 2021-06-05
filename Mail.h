#pragma once
#include<string>
#include<vector>
#include<fstream>

using namespace std;

class Mail
{
public:
	string from;
	vector<string> content;

	Mail() { }
	Mail(string _from, vector<string> _content);
	
};

bool send_mail(string receiver_user_name, int sender_user_id);//return false if receiver not found

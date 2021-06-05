#pragma once
#include<string>
#include<vector>

using namespace std;

class Mail
{
public:
	string from;
	vector<string> content;

	Mail();
	Mail(string _from, vector<string> content);

	friend bool send_mail(string receiver_user_name, int sender_user_id);//return false if receiver not found
};


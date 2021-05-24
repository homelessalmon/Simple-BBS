#pragma once
#include <vector>
#include<fstream>
#include<string>

using namespace std;

class User
{
public:
	vector <int> postsID;	// 紀錄建立過的post
	int Permission_level = -1;	// 權限等級
	int user_id = -1;
	// Other infos, e.x. comment_nums, post_num, ….

	User(){}

};

class Adiministrator : public User
{
public:
	Adiministrator(string user_name, string user_password);
	void add_board();
	void add_post(int current_board);
};

class Member : public User
{
public:
	Member(string user_name, string user_password);
	void add_post(int current_board);
};

class Guest : public User
{
public:
	Guest() :User() {}
};

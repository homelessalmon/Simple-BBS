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
	virtual void add_board(string board_name) { return; }
	//virtual void edit_board();
	//virtual void remove_board();

	virtual void add_post(int current_board) { return; }
	//virtual void edit_post();
	//virtual void remove_post();
	

};

class Adiministrator : public User
{
public:
	Adiministrator(string user_name, string user_password);
	Adiministrator(vector<int> _postsID, int _user_id);
	void add_board(string board_name);
	void add_post(int current_board);
};

class Member : public User
{
public:
	Member(string user_name, string user_password);
	Member(vector<int> _postsID, int _user_id);
	virtual void add_post(int current_board);
};

class Guest : public User
{
public:
	Guest() :User() {}
};

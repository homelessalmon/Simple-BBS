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
	virtual void edit_board(int board_id, string new_name) { return; }
	virtual void remove_board(int board_id) { return; }

	virtual void add_post(int current_board) { return; }
	virtual void edit_post(int post_id,int part_select) { return; }
	virtual void remove_post(int post_id) { return; }
	

};

class Adiministrator : public User
{
public:
	Adiministrator(string user_name, string user_password);
	Adiministrator(vector<int> _postsID, int _user_id);
	void add_board(string board_name);
	void edit_board(int board_id, string new_name);
	void remove_board(int board_id);
	void add_post(int current_board);
	void edit_post(int post_id, int part_select);//0 title,1 content.
	void remove_post(int post_id);
};

class Member : public User
{
public:
	Member(string user_name, string user_password);
	Member(vector<int> _postsID, int _user_id);
	virtual void add_post(int current_board);
	void edit_post(int post_id, int part_select);
	void remove_post(int post_id);
};

class Guest : public User
{
public:
	Guest() :User() {}
};

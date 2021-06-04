#pragma once
#include <vector>
#include<fstream>
#include<string>
#include"Board.h"

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
	virtual void remove_board(int board_id, string reason) { return; }

	virtual void add_post(int current_board) { return; }
	virtual void edit_post(int post_id,int part_select) { return; }
	virtual void remove_post(int post_id, string reason) { return; }
	
	virtual void add_comment(int post_id, int current_userID, string text) { return; }
	virtual void remove_comment(int post_id, int order, string reason) { return; }//order是從頭開始數來第幾個comment,0開始

};

class Adiministrator : public User
{
public:
	Adiministrator(string user_name, string user_password);
	Adiministrator(vector<int> _postsID, int _user_id);

	void add_board(string board_name);
	void edit_board(int board_id, string new_name);
	void remove_board(int board_id, string reason);

	void add_post(int current_board);
	void edit_post(int post_id, int part_select);//0 title,1 content.
	void remove_post(int post_id, string reason);

	void add_comment(int post_id, int current_userID, string text);
	void remove_comment(int post_id, int order, string reason);
};

class Member : public User
{
public:
	Member(string user_name, string user_password);
	Member(vector<int> _postsID, int _user_id);

	void add_post(int current_board);
	void edit_post(int post_id, int part_select);
	void remove_post(int post_id, string reason);

	void add_comment(int post_id, int current_userID, string text);
};

class Guest : public User
{
public:
	Guest() :User() {}
};

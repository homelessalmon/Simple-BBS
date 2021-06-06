#pragma once
#include "Board.h"
#include "User.h"
#include "Viewer.h"

using namespace std;

enum BoardState {
	MENU,
	LOGIN,
	SIGNUP,
	MENU_PERSONAL,
	MAIL,
	SELECT_BOARD,
	ADD_BOARD,
	DELETE_BOARD,
	BOARD,
	POST,
	EDIT_BOARD,
	COMMENT
};


class BoardManager {
public:
	vector <User*> users;
	vector <Board> boards;
	int current_user = -1;
	int current_board = -1;
	int current_post = -1;

	BoardState state;
	Viewer viewer;

	void exe();
	void load_user();
	void load_board();
	void get_user_id(string account);
	void load_mail();//bound to current users,after calling this function,can use vector users[current_user]->mail
	vector<pair<string, string>> return_name_and_password();
	string return_post_author(int post_id);
	int post_id_to_index(int post_id, vector<Board> boards, int board_id);
};

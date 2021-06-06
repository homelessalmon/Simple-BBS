#include "BoardManager.h"
#include <windows.h>

void BoardManager::exe() {
	load_user();
	while (true) {
		switch (state) {
		case MENU: {
			current_user = -1;
			current_board = -1;
			current_post = -1;
			int op = viewer.menu1();
			switch (op) {
			case 0:
				return;// exit
				break;
			case 1: //login
				state = LOGIN;
				break;
			case 2: //signup
				state = SIGNUP;
				break;
			case 3: { //board 
				Guest guest;
				users.push_back(&guest);
				state = SELECT_BOARD;
			}break;
			}break;

		}break;

		case LOGIN: {
			string account, password;
			int op = viewer.login(account, password, return_name_and_password());
			switch (op) {
			case 1:
				get_user_id(account);
				state = MENU_PERSONAL;
				break;
			case -1:
				//MessageBox(NULL, L"Wrong ID or Password", NULL, MB_ICONHAND | MB_OK);
				state = MENU;
				break;
			}
		}break;

		case SIGNUP: {
			string account, password;
			switch (viewer.signup(account, password, return_name_and_password())) {
			case 1: {
				Member member(account, password);
				load_user();
				state = MENU;
			}break;
			case -1:
				//MessageBox(NULL, L"Duplicated ID", NULL, MB_ICONHAND | MB_OK);
				state = MENU;
				break;
			}
		}break;
		case MENU_PERSONAL: {
			int op = viewer.menu2();
			switch (op) {
			case 0:
				state = MENU;
				break;
			case 1:
				state = SELECT_BOARD;
				break;
			case 2:
				state = MAIL;
				break;
			}
		}break;
		case MAIL: {
			viewer.mailbox();
		}
		case SELECT_BOARD: {
			current_board = -1;
			load_board();
			int permission;
			if (current_user == -1) { //GUEST
				permission = 0;
			}
			else {
				permission = users[current_user]->Permission_level;
			}
			int op = viewer.board_select(boards, permission);
			switch (op) {
			case -1:
				state = permission == -1 ? MENU : MENU_PERSONAL;
				break;
			case -2:
				state = MENU;
				break;
			case -3:
				state = ADD_BOARD;
				break;
			case -4:
				state = DELETE_BOARD;
				break;
			default:
				current_board = op;
				state = BOARD;
				break;
			}
		}break;
		case ADD_BOARD: {
			string board_name;
			int op = viewer.board_add(boards, board_name);
			switch (op) {
			case 1:
				users[current_user]->add_board(board_name);
				load_board();
				state = SELECT_BOARD;
				break;
			case -1:
				MessageBox(NULL, L"Duplicated Board Name", NULL, MB_ICONHAND | MB_OK);
				state = SELECT_BOARD;
				break;
			}
		}break;

		case DELETE_BOARD: {
			string reason = "deleted";
			int op = viewer.board_delete(boards);
			switch (op) {
			case -1:
				//MessageBox(NULL, L"Board Doesn't Exist", NULL, MB_ICONHAND | MB_OK);
				state = SELECT_BOARD;
				break;
			default:
				users[current_user]->remove_board(op, reason);
				load_board();
				state = SELECT_BOARD;
				break;
			}
		}break;
		case BOARD: {
			boards[current_board].load_all_post();
			current_post = -1;
			int op = viewer.post_select(boards[current_board]);
			switch (op) {
			case -1:
				state = SELECT_BOARD;
				break;
			case -2:
				state = MENU;
				break;
			case -3: {
				string title;
				int boxop = viewer.window_txtbox("New post", "Please input the title", title, 28, 200, 90);
				if (boxop == 1) {
					users[current_user]->add_post(current_board, title);
					boards[current_board].load_all_post();
				}
			}break;
			default:
				current_post = op;
				state = POST;
				break;
			}
		}break;
		case POST: {
			int index = post_id_to_index(current_post, boards, current_board);
			int permission = 0;
			if (current_user == -1) {
				permission = 0;
			}
			else {
				permission = users[current_user]->Permission_level;
			}
			int op = viewer.view_post(boards[current_board].all_Post, return_post_author(current_post), index, current_board, current_user, permission);
			switch (op) {
			case -1:
				state = BOARD;
				break;
			case -2:
				state = MENU;
				break;
			case -3:
				state = COMMENT;
				break;
			case -4:
				users[current_user]->edit_post_content(current_post);
				boards[current_board].load_all_post();
				break;
			case -5: {
				string reason;
				int boxop = viewer.window_txtbox("Delete Post", "Please input the reason", reason, 28, 100, 90);
				if (boxop == 1) {
					users[current_user]->remove_post(current_post, "reason");
					boards[current_board].load_all_post();
				}
			}break;
			}
		}break;
		case COMMENT: {
			break;
		}

		default:
			break;
		}
	}
}

#include "BoardManager.h"

void BoardManager::load_user() {
	ifstream fin("users/count.txt");
	int user_count; fin >> user_count; fin.close();

	users.clear();

	for (int i = 0; i < user_count + 1; i++) {
		fin.open("users/" + to_string(i) + ".txt");
		if (fin.is_open()) {
			string u_name, u_password; int u_id, u_permission, tmp; vector<int> u_post_id;
			fin >> u_name >> u_password >> u_id >> u_permission;
			while (fin >> tmp) { u_post_id.push_back(tmp); }
			if (u_permission == 2) {
				Adiministrator* tmp2 = new Adiministrator(u_post_id, u_id);
				users.push_back(tmp2);
			}
			else {
				Member* tmp2 = new Member(u_post_id, u_id);
				users.push_back(tmp2);
			}
			u_post_id.clear();
		}
		fin.close();
	}
}

void BoardManager::load_board() {
	ifstream fin("boards/count.txt");
	int board_count; fin >> board_count; fin.close();

	boards.clear();

	for (int i = 0; i < board_count; i++) {
		fin.open("boards/" + to_string(i) + ".txt");
		if (fin.is_open()) {
			string _board_name; int tmp; vector<int> post_id;
			getline(fin, _board_name);
			if (_board_name != REMOVE) {
				while (fin >> tmp) { post_id.push_back(tmp); }

				Board* tmp2 = new Board(post_id, _board_name);
				boards.push_back(*(tmp2));
				post_id.clear();
			}
			else {
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

void BoardManager::load_mail() {
	int mail_count = 0;
	ifstream fin("mails/count.txt");
	if (fin.is_open()) {
		fin >> mail_count;
	}
	fin.close();

	for (int i = 0; i < mail_count; i++) {
		fin.open("mails/" + to_string(i) + "info.txt");
		if (fin.is_open()) {
			string catch_string;
			int id;
			fin >> catch_string >> id;

			if (id == current_user) {
				fin >> catch_string;

				string tmp, title;

				ifstream fin3("mails/" + to_string(i) + "title.txt");
				if (fin3.is_open()) {
					getline(fin3, title);
				}
				fin3.close();

				vector<string> tmp_vector;
				ifstream fin2("mails/" + to_string(i) + "content.txt");
				if (fin2.is_open()) {
					while (getline(fin2, tmp)) { tmp_vector.push_back(tmp); }
				}
				fin2.close();

				Mail aPost(catch_string, title, tmp_vector);
				users[current_user]->mail_list.push_back(aPost);
			}
		}
		fin.close();
	}
}

vector<pair<string, string>> BoardManager::return_name_and_password() {
	vector<pair<string, string>> return_list;
	for (int i = 0; i < users.size(); i++) {
		ifstream fin("users/" + to_string(i) + ".txt");
		if (fin.is_open()) {
			string name, password;
			fin >> name >> password;
			pair<string, string> tmp(name, password);
			return_list.push_back(tmp);
		}
		fin.close();
	}
	return return_list;
}

string BoardManager::return_post_author(int post_id) {
	for (int i = 0; i < users.size(); i++) {
		for (int j = 0; j < users[i]->postsID.size(); j++) {
			if (post_id == users[i]->postsID[j]) {
				vector<pair<string, string>> name_list = return_name_and_password();
				return name_list[i].first;
			}
		}
	}
}

int BoardManager::post_id_to_index(int post_id, vector<Board> boards, int board_id) {
	for (int i = 0; i < boards[board_id].post_id.size(); i++) {
		if (boards[board_id].post_id[i] == post_id) {
			return i;
		}
	}
	return -1;
}

void BoardManager::get_user_id(string account) {
	vector<pair<string, string>> list = return_name_and_password();
	for (int i = 0; i < list.size(); i++) {
		if (list[i].first == account) {
			current_user = i;
			break;
		}
	}
}

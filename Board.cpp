#include "Board.h"

Board::Board(vector<int> _post_id, string _board_name)
{
	post_id = _post_id;
	board_name = _board_name;
}

Post::Post(string _title, vector<string> _content, vector<Comment> _comments)
{
	title = _title;
	content = _content;
	comments = _comments;
}

vector<Comment> load_comment(int post_id)
{
	ifstream fin("posts/" + to_string(post_id) + "comment.txt");
	string name, com;
	stringstream ss;
	vector<Comment> list;
	while (getline(fin, name))
	{
		ss.str("");
		ss.clear();

		ss << name;
		ss >> name;
		getline(ss,com);

		Comment tmp(name, com);
		if (name == REMOVE)
		{
			name = "<deleted> Reason:";
			tmp.is_removed = true;
		}
		list.push_back(tmp);
	}
	fin.close();
	return list;
}

bool operator>(pair<string, int> left, pair<string, int> right)
{
	if (right.second > left.second)return false;
	else
	{
		int ll = left.first.length(), lr = right.first.length();
		int minl = ll < lr ? ll : lr;
		for (int i = 0; i < minl; i++)
		{
			if (left.first[i] > right.first[i])return true;
		}
		if (ll >= lr)return true;
		return false;
	}
}

void Post::load_post(int post_id)
{
	ifstream fin("posts/" + to_string(post_id) + "title.txt");
	getline(fin, title);
	fin.close();

	string tmp;
	fin.open("posts/" + to_string(post_id) + "content.txt");
	while (getline(fin, tmp)) { content.push_back(tmp); }
	fin.close();

	comments = load_comment(post_id);

	if (title == REMOVE)
	{
		is_removed = true;
	}
}

void Board::load_all_post()
{
	all_Post.clear();
	for (int i = 0; i < post_id.size(); i++)
	{
		Post tmp;
		tmp.load_post(post_id[i]);
		all_Post.push_back(tmp);
	}
}

void Game1::new_answer()
{
	srand(time(NULL));
	answer = rand() % 100 + 1;
}

int Game1::guess(int input_number, int current_user_id)
{
	if (input_number < 1 || input_number>1000)return -2;
	guess_count++;
	if (input_number > answer)return 1;
	else if (input_number < answer)return -1;
	else
	{
		bool is_find = false;
		ifstream fin("users/" + to_string(current_user_id) + ".txt");
		string name;
		fin >> name;
		
		for (int i = 0; i < lead_board.size(); i++)
		{
			if (lead_board[i].first == name)
			{
				if (lead_board[i].second > guess_count)
				{
					lead_board[i].second = guess_count;
					is_find = true;
					break;
				}
			}
		}
		if (!is_find)
		{
			pair<string, int> tmp(name, guess_count);
			lead_board.push_back(tmp);
		}

		this->sort_lead_bord();
		this->write_lead_board();
		guess_count = 0;
		return 0;
	}
}

void Game1::load_lead_board()
{
	lead_board.clear();
	ifstream fin("Game1_lead_board.txt");
	if (fin.is_open())
	{
		string s;
		while (getline(fin, s))
		{
			stringstream ss; ss.str(""); ss.clear();
			ss << s;
			pair<string, int> tmp;
			ss >> tmp.first >> tmp.second;
			lead_board.push_back(tmp);
		}
	}
	else
	{
		system("cd.>Game1_lead_board.txt");
	}
	fin.close();
}

void Game1::write_lead_board()
{
	ofstream fout("Game1_lead_board.txt", ios::trunc);
	if (fout.is_open())
	{
		for (int i = 0; i < lead_board.size(); i++)
		{
			if (i == lead_board.size() - 1)
			{
				fout << lead_board[i].first + " " << lead_board[i].second;
			}
			else
			{
				fout << lead_board[i].first + " " << lead_board[i].second << endl;
			}
		}
	}
	fout.close();
}

void Game1::sort_lead_bord()
{
	for (int i = 0; i < lead_board.size() - 1; i++)
	{
		for (int j = 0; j < lead_board.size() - 1; j++)
		{
			if (lead_board[j] > lead_board[j + 1])swap(lead_board[j], lead_board[j + 1]);
		}
	}
}

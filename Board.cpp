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
		ss >> name >> com;

		Comment tmp(name, com);
		if (name == REMOVE)
		{
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

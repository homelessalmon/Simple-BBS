#include "Board.h"

Board::Board(vector<int> _post_id, string _board_name)
{
	post_id = _post_id;
	board_name = _board_name;
}

Post::Post(vector<string> _title, vector<string> _content, vector<Comment> _comments)
{
	title = _title;
	content = _content;
	comments = _comments;
}

void Post::load_post(int post_id)
{
	ifstream fin("posts/" + to_string(post_id) + "title.txt");
	string tmp;
	while (getline(fin, tmp)) { title.push_back(tmp); }
	fin.close();

	fin.open("posts/" + to_string(post_id) + "content.txt");
	while (getline(fin, tmp)) { content.push_back(tmp); }
	fin.close();

	comments = load_comment(post_id);

	if (title[0] == REMOVE)
	{
		is_removed = true;
	}
}

vector<Comment> load_comment(int post_id)
{
	ifstream fin("posts/" + to_string(post_id) + "comment.txt");
	string name, com;
	stringstream ss;
	vector<Comment> list;
	while (getline(fin,name))
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

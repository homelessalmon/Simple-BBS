#pragma once
#include<string>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

const string REMOVE = "-1402834659875121315.1";

class Comment
{
public:
	string name;
	string com;//reason if removed
	bool is_removed = false;

	Comment(string _name, string _com) :name(_name), com(_com) { }
	friend vector<Comment> load_comment(int post_id);
};

class Post
{
public:
  vector<string> title;
  vector<string> content;
  vector<Comment> comments;
  bool is_removed = false;

  Post(vector<string> _title, vector<string> _content, vector<Comment> _comments);
  void load_post(int post_id);
};

class Board
{
public:
  vector<int> post_id;
  string board_name;//reason if removed;
  bool is_removed = false;

  Board(vector<int> _post_id, string board_name);
};

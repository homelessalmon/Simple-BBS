#pragma once
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<ctime>

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
  string title = REMOVE;
  vector<string> content;
  vector<Comment> comments;
  bool is_removed = false;

  Post() {  }
  Post(string _title, vector<string> _content, vector<Comment> _comments);
  void load_post(int post_id);
};

class Board
{
public:
  vector<int> post_id;
  vector<Post> all_Post;
  string board_name;//reason if removed;
  bool is_removed = false;

  Board(vector<int> _post_id, string board_name);
  void load_all_post();
};

class Game1
{
public:
	vector<pair<string, int>> lead_board;
	int answer = 0;
	int guess_count = 0;
	Game1() { }
	
	void new_answer();
	int guess(int input_number, int current_user_id);//-1 lower than answer, 0 right, 1 higher than answer, -2 for any exception.
	void load_lead_board();
	void write_lead_board();
	void sort_lead_bord();
};

bool operator>(pair<string, int> left, pair<string, int> right);

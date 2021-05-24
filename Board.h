#pragma once
#include<string>
#include<vector>

using namespace std;

class Post
{
public:
  vector<string> title;
  vector<string> content;
  vector<string> comment;
};
class Board
{
public:
  vector<int> post_id;
  string board_name;

  Board(vector<int> _post_id, string board_name);
};

#pragma once
#include<string>
#include<vector>
class Post
{
  vector<string> title;
  vector<string> string content;
  vector<string> comment;
};
class Board
{
  vector<int> post_id;
  int permission;
  string board_name;
};


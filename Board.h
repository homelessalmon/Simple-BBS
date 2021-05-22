#pragma once
#include<string>
#include<vector>
class Post
{
  string title;
  string content;
  vector<string> comment;
};
class Board
{
  vector<int> post_id;
  int permission;
  string board_name;
};


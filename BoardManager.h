#pragma once
#include "Board.h"
#include "User.h"
#include "Viewer.h"

using namespace std;

enum BoardState
{
    MENU,
    SELECT_BOARD,
    BOARD,
    POST
};


class BoardManager
{
public:
    vector <User*> users;
    vector <Board> boards;
    int current_user = -1;
    int current_board = -1;
    int current_post = -1;

    BoardState state;
    Viewer viewer;

    void load_user();
    void load_board();
};

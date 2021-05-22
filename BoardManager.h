#pragma once
#include <iostream>
#include <vector>
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
    vector <User*> users;
    vector <Board> boards;
    int current_user;

    BoardState state;
    Viewer viewer;

};
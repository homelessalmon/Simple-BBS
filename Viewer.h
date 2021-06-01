#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>

using namespace std;

class Viewer
{
public:
	int menu();
	int login(string&, string&);
	int signup(string&, string&);
};

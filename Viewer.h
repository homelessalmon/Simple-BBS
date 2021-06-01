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
	void login(string&, string&);
	void signup(string&, string&);
};

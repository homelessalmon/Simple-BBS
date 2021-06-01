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
	int login(string&, string&); //0:back to menu 1: end successfully 
	int signup(string&, string&); //0:back to menu 1: end successfully 
};

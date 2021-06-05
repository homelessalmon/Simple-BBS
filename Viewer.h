#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <stdlib.h>
#include "Board.h"

using namespace std;

class Viewer
{
public:
	int menu1(); //0.Exit; 1.Log in; 2.Sign up; 3.Guest
	int menu2(); //0.Logout; 1.View Boards; 2.Mailbox
	int login(string&, string&, int check); //0.back to menu; 1.end successfully //check: -1.Username not exist; -2.Wrong Password
	int signup(string&, string&, int check); //0.back to menu; 1.end successfully //check: -1.Username existed;
	void mailbox();
	int board_select(vector<Board>, int permission_lv); //-1.back; -2.logout; -3.add board(admin); -4.del board(admin); 0~n.board ID
	string board_add();
	int board_delete(vector<Board>); // -1.back(no delete); 0~n.board to be deleted
	int post_select(Board); //-1.back; -2.logout; 0~n.post ID
	int view_post();
	int view_comment();
	string leave_comment();
};

class Button
{
public:
	bool buttonOn;
	Button(string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor) {
		text.setString(t);
		text.setFillColor(textColor);
		text.setCharacterSize(charSize);
		button.setSize(size);
		button.setFillColor(bgColor);
		buttonOn = true;
	}

	void btnOn() { buttonOn = true; }

	void btnOff() { buttonOn = false; }

	void setFont(sf::Font& font) {
		text.setFont(font);
	}

	void setText(string txt) {
		text.setString(txt);
	}

	void setBgColor(sf::Color color) {
		button.setFillColor(color);
	}

	void setTxtColor(sf::Color color) {
		text.setFillColor(color);
	}

	void setPos(sf::Vector2f pos) {
		button.setPosition(pos);
		float x = (pos.x + button.getGlobalBounds().width / 3) - (text.getGlobalBounds().width / 4);
		float y = (pos.y + button.getGlobalBounds().height / 4) - (text.getGlobalBounds().height / 4);
		text.setPosition({ x, y });
	}

	void drawTo(sf::RenderWindow& window) {
		window.draw(button);
		window.draw(text);
	}

	bool isMouseOver(sf::RenderWindow& window) {
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;
		float buttonX = button.getPosition().x;
		float buttonY = button.getPosition().y;
		float buttonW = button.getPosition().x + button.getLocalBounds().width;
		float buttonH = button.getPosition().y + button.getLocalBounds().height;
		if (mouseX < buttonW && mouseX > buttonX && mouseY < buttonH && mouseY > buttonY) {
			return true;
		}
		return false;
	}
private:
	sf::RectangleShape button;
	sf::Text text;
};

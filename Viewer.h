#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Board.h"
#include "Mail.h"

#define DEL_KEY 8
#define ENTER_KEY 13
#define ESC_KEY 27

using namespace std;


class Viewer
{
public:
	bool isValid(string, string, vector<pair<string, string>>, int); //1.login; 2.signup
	int menu1(); //0.Exit; 1.Log in; 2.Sign up; 3.Guest
	int menu2(int permission_lv); //0.Logout; 1.View Boards; 2.Mailbox; 3.game; 99.add admin
	int login(string&, string&, vector<pair<string, string>>); //1.success; -1.back
	int signup(string&, string&, vector<pair<string, string>>); //1.success; -1.back
	void mailbox(); //todo
	void sendMail(); //todo
	int board_select(vector<Board>, int permission_lv); //-1.back; -2.logout; -3.add board(admin); -4.del board(admin); 0~n.board ID
	int board_add(vector<Board>, string&); // -1.back(no add); 1.add successfully
	int board_delete(vector<Board>); //-1.back(no delete); 0~n.board to be deleted
	int post_select(Board, int permission_lv); //-1.back; -2.logout; -3.add; 0~n.post ID
	int view_post(vector<Post> posts, string author, int authorID, int postID, int boardID, int userID, int permission_lv); //-1.back; -2.logout; -3.view comment; -4.edit; -5.del_post;
	int view_comment(vector<Post> posts, int postID, int userID, int permission_lv); //-1.back; -100.leave comment; 0~n.comment to be deleted
	int edit_title(string& cur_title); //-1.cancel; 1.enter successfully
	int window_txtbox(string title, string info, string& input, int limit, float posX, float posY); //to input one non-empty string
	//-1.cancel; 1.enter successfully
	//posX & posY is for adjusting title's position, posY = 90 is recommended, posX: 0 ~ 700
	void game(Game1& game, int userID); //just simply return
};


class Button
{
public:
	
	Button() { }
	Button(string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor) {
		text.setString(t);
		text.setFillColor(textColor);
		text.setCharacterSize(charSize);
		button.setSize(size);
		button.setFillColor(bgColor);
		buttonOn = true;
	}

	bool isOn() {
		if (buttonOn) return true;
		else return false;
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
	bool buttonOn;
};


class Textbox
{
public:
	Textbox() { }
	Textbox(int size, sf::Color color, bool sel) {
		textbox.setCharacterSize(size);
		textbox.setFillColor(color);
		bg.setFillColor(sf::Color::White);
		bg.setSize({500, (float)(size + 7)});
		isSelected = sel;
		limit = 20;
		if (sel) {
			textbox.setString("_");
		}
		else {
			textbox.setString("");
		}
	}

	bool isSel() {
		if (isSelected) return true;
		else return false;
	}

	void setFont(sf::Font& font) {
		textbox.setFont(font);
	}

	void setPos(sf::Vector2f pos) {
		textbox.setPosition(pos);
		bg.setPosition(pos);
	}

	void setBoxColor(sf::Color color) {
		bg.setFillColor(color);
	}

	void setBoxSize(sf::Vector2f size) {
		bg.setSize(size);
	}

	void setLimit(bool ToF) {
		haslimit = ToF;
	}

	void setLimit(bool ToF, int lim) {
		haslimit = ToF;
		limit = lim - 1;
	}

	void setSelected(bool sel) {
		bool prev_stat = isSelected;
		isSelected = sel;

		if (!prev_stat && isSelected) {
			inputLogic(65);
			inputLogic(DEL_KEY);
		}
		if (!sel) {
			string t = text.str();
			string newstr = "";
			for (int i = 0; i < t.length(); i++) {
				newstr += t[i];
			}
			text.str("");
			text << newstr;
			textbox.setString(text.str());
			setBoxColor(sf::Color(150, 150, 150));
		}
		else {
			setBoxColor(sf::Color::White);
		}
	}

	void pwd_setSelected(bool sel) {
		bool prev_stat = isSelected;
		isSelected = sel;

		if (!prev_stat && isSelected) {
			input4password(65);
			input4password(DEL_KEY);
		}
		if (!sel) {
			string t = text.str();
			string newstr = "";
			for (int i = 0; i < t.length(); i++) {
				newstr += t[i];
			}
			text.str("");
			text << newstr;
			string tmp = "";
			for (int i = 0; i < text.str().length(); i++) {
				tmp += "*";
			}
			textbox.setString(tmp);
			setBoxColor(sf::Color(150, 150, 150));
		}
		else {
			setBoxColor(sf::Color::White);
		}
	}

	void typedOn(sf::Event input) {
		if (isSelected) {
			int charTyped = input.text.unicode;
			if (charTyped < 128) {
				if (haslimit) {
					if (text.str().length() <= limit) {
						inputLogic(charTyped);
					}
					else if (text.str().length() > limit && charTyped == DEL_KEY) {
						delLastChar();
					}
				}
				else {
					inputLogic(charTyped);
				}
			}
		}
	}

	void typedPassword(sf::Event input) {
		if (isSelected) {
			int charTyped = input.text.unicode;
			if (charTyped < 128) {
				if (haslimit) {
					if (text.str().length() <= limit) {
						input4password(charTyped);
					}
					else if (text.str().length() > limit && charTyped == DEL_KEY) {
						pwd_delLastChar();
					}
				}
				else {
					input4password(charTyped);
				}
			}
		}
	}

	bool isMouseOver(sf::RenderWindow& window) {
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;
		float boxX = bg.getPosition().x;
		float boxY = bg.getPosition().y;
		float boxW = bg.getPosition().x + bg.getLocalBounds().width;
		float boxH = bg.getPosition().y + bg.getLocalBounds().height;
		if (mouseX < boxW && mouseX > boxX && mouseY < boxH && mouseY > boxY) {
			return true;
		}
		return false;
	}

	string getText() {
		return text.str();
	}

	void drawTo(sf::RenderWindow& window) {
		window.draw(bg);
		window.draw(textbox);
	}

	void pre_enter(string str) {
		textbox.setString(str);
		text.str("");
		text << str;
	}

private:
	sf::Text textbox;
	sf::RectangleShape bg;
	ostringstream text;
	bool isSelected = false;
	bool haslimit = false;
	int limit;

	void inputLogic(int charTyped) {
		if (charTyped != DEL_KEY && charTyped != ENTER_KEY && charTyped != ESC_KEY) {
			text << static_cast<char>(charTyped);
		}
		else if (charTyped == DEL_KEY && text.str().length() > 0) {
			delLastChar();
		}
		textbox.setString(text.str() + "_");
	}

	void input4password(int charTyped) {
		if (charTyped != DEL_KEY && charTyped != ENTER_KEY && charTyped != ESC_KEY) {
			text << static_cast<char>(charTyped);
		}
		else if (charTyped == DEL_KEY && text.str().length() > 0) {
			pwd_delLastChar();
		}
		string tmp = "";
		for (int i = 0; i < text.str().length(); i++) {
			tmp += "*";
		}
		textbox.setString(tmp + "_");
	}

	void delLastChar() {
		string t = text.str();
		string newstr = "";
		for (int i = 0; i < t.length() - 1; i++) {
			newstr += t[i];
		}
		text.str("");
		text << newstr;
		textbox.setString(text.str());
	}

	void pwd_delLastChar() {
		string t = text.str();
		string newstr = "";
		for (int i = 0; i < t.length() - 1; i++) {
			newstr += t[i];
		}
		text.str("");
		text << newstr;

		string tmp = "";
		for (int i = 0; i < text.str().length(); i++) {
			tmp += "*";
		}
		textbox.setString(tmp);
	}
};

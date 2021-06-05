#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <stdlib.h>

using namespace std;

class Viewer
{
public:
	int menu1(); //0.Exit; 1.Log in; 2.Sign up; 3.Guest
	int menu2(); //0.Logout; 1.View Boards; 2.Mailbox
	int login(string&, string&, int check); //0.back to menu; 1.end successfully //check: -1.Username not exist; -2.Wrong Password
	int signup(string&, string&, int check); //0.back to menu; 1.end successfully //check: -1.Username existed;
	void board_select(); //-1.back; -2.menu; -3.add board(admin); 0~n.board ID
	void post_select();
};

class Button
{
public:
	Button() {};
	Button(string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor) {
		text.setString(t);
		text.setFillColor(textColor);
		text.setCharacterSize(charSize);
		button.setSize(size);
		button.setFillColor(bgColor);
	}

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

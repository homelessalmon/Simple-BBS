#include "Viewer.h"

bool Viewer::isValid(string username, string password, vector<pair<string, string>> userdata, int mode)
{
    if (username == "" || password == "") return false;
    bool ToF = false;
    for (int i = 0; i < userdata.size(); i++) {
        if (userdata[i].first == username) {
            if (mode == 2) 
                return false;
            if (mode == 1) {
                ToF = true;
                break;
            }
        }
    }
    for (int i = 0; i < userdata.size(); i++) {
        if (userdata[i].second == password) {
            if (mode == 1 && ToF)
                return true;
        }
    }
    if (mode == 2) return true;
    return false;
}

int Viewer::menu1()
{
    sf::RenderWindow window(sf::VideoMode(700, 800), "Welcome!", sf::Style::Default ^ sf::Style::Resize);
    sf::Font font;
    font.loadFromFile("consola.ttf");

    sf::Text title;
    title.setFont(font);
    title.setFillColor(sf::Color::Red);
    title.setCharacterSize(100);
    title.setString("MENU");
    title.setPosition({ 225, 75 });

    Button login("Log in", { 400, 70 }, 50, sf::Color::Black, sf::Color::White);
    login.setFont(font);
    login.setPos({ 150, 245 });
    Button signup("Signup", { 400, 70 }, 50, sf::Color::Black, sf::Color::White);
    signup.setFont(font);
    signup.setPos({ 150, 345 });
    Button guest("Guest", { 400, 70 }, 50, sf::Color::Black, sf::Color::White);
    guest.setFont(font);
    guest.setPos({ 150, 445 });
    Button exit("Exit", { 400, 70 }, 50, sf::Color::Black, sf::Color::White);
    exit.setFont(font);
    exit.setPos({ 150, 545 });

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseMoved:
                if (login.isMouseOver(window)) {
                    login.setBgColor(sf::Color::White);
                    login.setTxtColor(sf::Color::Black);
                }
                else if (signup.isMouseOver(window)) {
                    signup.setBgColor(sf::Color::White);
                    signup.setTxtColor(sf::Color::Black);
                }
                else if (guest.isMouseOver(window)) {
                    guest.setBgColor(sf::Color::White);
                    guest.setTxtColor(sf::Color::Black);
                }
                else if (exit.isMouseOver(window)) {
                    exit.setBgColor(sf::Color::White);
                    exit.setTxtColor(sf::Color::Black);
                }
                else {
                    login.setBgColor(sf::Color::Black);
                    login.setTxtColor(sf::Color::White);
                    signup.setBgColor(sf::Color::Black);
                    signup.setTxtColor(sf::Color::White);
                    guest.setBgColor(sf::Color::Black);
                    guest.setTxtColor(sf::Color::White);
                    exit.setBgColor(sf::Color::Black);
                    exit.setTxtColor(sf::Color::White);
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (login.isMouseOver(window)) {
                    return 1;
                }
                if (signup.isMouseOver(window)) {
                    return 2;
                }
                if (guest.isMouseOver(window)) {
                    return 3;
                }
                if (exit.isMouseOver(window)) {
                    return 0;
                }
                break;
            }
        }

        login.drawTo(window);
        signup.drawTo(window);
        guest.drawTo(window);
        exit.drawTo(window);
        window.draw(title);
        window.display();
    }
}

int Viewer::login(string& username, string& password, vector<pair<string, string>> userdata)
{
    sf::RenderWindow window(sf::VideoMode(700, 800), "login", sf::Style::Default ^ sf::Style::Resize);
    sf::Font font;
    font.loadFromFile("consola.ttf");

    sf::Text title, txt_username, txt_password;
    title.setFont(font);
    title.setCharacterSize(100);
    title.setFillColor(sf::Color::Red);
    title.setString("LOGIN");
    title.setPosition({ 205, 80});
    txt_username.setFont(font);
    txt_username.setCharacterSize(30);
    txt_username.setFillColor(sf::Color::White);
    txt_username.setString("Username:");
    txt_username.setPosition({ 100, 250 });
    txt_password.setFont(font);
    txt_password.setCharacterSize(30);
    txt_password.setFillColor(sf::Color::White);
    txt_password.setString("Password:");
    txt_password.setPosition({ 100, 380 });
    sf::Text errormsg;
    errormsg.setFont(font);
    errormsg.setCharacterSize(20);
    errormsg.setFillColor(sf::Color::Black);
    errormsg.setString("Invalid Input");
    errormsg.setPosition({ 265, 510 });

    Textbox txtbox_username(30, sf::Color::Black, false);
    txtbox_username.setFont(font);
    txtbox_username.setPos({ 100, 300 });
    txtbox_username.setLimit(true, 20);
    Textbox txtbox_password(30, sf::Color::Black, false);
    txtbox_password.setFont(font);
    txtbox_password.setPos({ 100, 430 });
    txtbox_password.setLimit(true, 20);

    Button enter("Enter", { 130, 65 }, 30, sf::Color::White, sf::Color::Black);
    enter.setFont(font);
    enter.setPos({ 150, 570 });
    Button cancel("Cancel", { 130, 65 }, 30, sf::Color::White, sf::Color::Black);
    cancel.setFont(font);
    cancel.setPos({ 400, 570 });

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::TextEntered:
                if (txtbox_username.isSel()) {
                    txtbox_username.typedOn(event);
                }
                if (txtbox_password.isSel()) {
                    txtbox_password.typedPassword(event);
                }
                break;
            case sf::Event::MouseMoved:
                if (enter.isMouseOver(window)) {
                    enter.setTxtColor(sf::Color::White);
                    enter.setBgColor(sf::Color(0, 204, 0));
                }
                else if (cancel.isMouseOver(window)) {
                    cancel.setTxtColor(sf::Color::White);
                    cancel.setBgColor(sf::Color::Red);
                }
                else {
                    enter.setTxtColor(sf::Color::Black);
                    enter.setBgColor(sf::Color::White);
                    cancel.setTxtColor(sf::Color::Black);
                    cancel.setBgColor(sf::Color::White);
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (txtbox_username.isMouseOver(window)) {
                    txtbox_username.setSelected(true);
                    txtbox_password.pwd_setSelected(false);
                }
                else if (txtbox_password.isMouseOver(window)) {
                    txtbox_password.pwd_setSelected(true);
                    txtbox_username.setSelected(false);
                }
                else if (enter.isMouseOver(window)) {
                    username = txtbox_username.getText();
                    password = txtbox_password.getText();
                    cout << username << " " << password << endl;
                    if (isValid(username, password, userdata, 1)) {
                        errormsg.setFillColor(sf::Color::Black);
                        cout << "success" << endl;
                        return 1;
                    }
                    else {
                        errormsg.setFillColor(sf::Color::Red);
                    }
                    txtbox_username.setSelected(false);
                    txtbox_password.pwd_setSelected(false);
                }
                else if (cancel.isMouseOver(window)) {
                    //cout << "cancel" << endl;
                    txtbox_username.setSelected(false);
                    txtbox_password.pwd_setSelected(false);
                    return -1;
                }
                else {
                    txtbox_username.setSelected(false);
                    txtbox_password.pwd_setSelected(false);
                }
                break;
            }
        }

        window.clear();
        window.draw(title);
        window.draw(txt_username);
        window.draw(txt_password);
        window.draw(errormsg);
        txtbox_username.drawTo(window);
        txtbox_password.drawTo(window);
        enter.drawTo(window);
        cancel.drawTo(window);
        window.display();
    }
}

int Viewer::signup(string& username, string& password, vector<pair<string, string>> userdata)
{
    sf::RenderWindow window(sf::VideoMode(700, 800), "signup", sf::Style::Default ^ sf::Style::Resize);
    sf::Font font;
    font.loadFromFile("consola.ttf");

    sf::Text title, txt_username, txt_password;
    title.setFont(font);
    title.setCharacterSize(100);
    title.setFillColor(sf::Color::Red);
    title.setString("SIGN UP");
    title.setPosition({ 155, 80 });
    txt_username.setFont(font);
    txt_username.setCharacterSize(30);
    txt_username.setFillColor(sf::Color::White);
    txt_username.setString("Username:");
    txt_username.setPosition({ 100, 250 });
    txt_password.setFont(font);
    txt_password.setCharacterSize(30);
    txt_password.setFillColor(sf::Color::White);
    txt_password.setString("Password:");
    txt_password.setPosition({ 100, 380 });
    sf::Text errormsg;
    errormsg.setFont(font);
    errormsg.setCharacterSize(20);
    errormsg.setFillColor(sf::Color::Black);
    errormsg.setString("Invalid Input");
    errormsg.setPosition({ 265, 510 });

    Textbox txtbox_username(30, sf::Color::Black, false);
    txtbox_username.setFont(font);
    txtbox_username.setPos({ 100, 300 });
    txtbox_username.setLimit(true, 10);
    Textbox txtbox_password(30, sf::Color::Black, false);
    txtbox_password.setFont(font);
    txtbox_password.setPos({ 100, 430 });
    txtbox_password.setLimit(true, 20);

    Button enter("Enter", { 130, 65 }, 30, sf::Color::White, sf::Color::Black);
    enter.setFont(font);
    enter.setPos({ 150, 570 });
    Button cancel("Cancel", { 130, 65 }, 30, sf::Color::White, sf::Color::Black);
    cancel.setFont(font);
    cancel.setPos({ 400, 570 });

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::TextEntered:
                if (txtbox_username.isSel()) {
                    txtbox_username.typedOn(event);
                }
                if (txtbox_password.isSel()) {
                    txtbox_password.typedPassword(event);;
                }
                break;
            case sf::Event::MouseMoved:
                if (enter.isMouseOver(window)) {
                    enter.setTxtColor(sf::Color::White);
                    enter.setBgColor(sf::Color(0, 204, 0));
                }
                else if (cancel.isMouseOver(window)) {
                    cancel.setTxtColor(sf::Color::White);
                    cancel.setBgColor(sf::Color::Red);
                }
                else {
                    enter.setTxtColor(sf::Color::Black);
                    enter.setBgColor(sf::Color::White);
                    cancel.setTxtColor(sf::Color::Black);
                    cancel.setBgColor(sf::Color::White);
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (txtbox_username.isMouseOver(window)) {
                    txtbox_username.setSelected(true);
                    txtbox_password.setSelected(false);
                }
                else if (txtbox_password.isMouseOver(window)) {
                    txtbox_password.setSelected(true);
                    txtbox_username.setSelected(false);
                }
                else if (enter.isMouseOver(window)) {
                    username = txtbox_username.getText();
                    password = txtbox_password.getText();
                    //cout << username << " " << password << endl;
                    if (isValid(username, password, userdata, 2)) {
                        errormsg.setFillColor(sf::Color::Black);
                        //cout << "success" << endl;
                        return 1;
                    }
                    else {
                        errormsg.setFillColor(sf::Color::Red);
                    }
                    txtbox_username.setSelected(false);
                    txtbox_password.setSelected(false);
                }
                else if (cancel.isMouseOver(window)) {
                    //cout << "cancel" << endl;
                    txtbox_username.setSelected(false);
                    txtbox_password.setSelected(false);
                    return -1;
                }
                else {
                    txtbox_username.setSelected(false);
                    txtbox_password.setSelected(false);
                }
                break;
            }
        }

        window.clear();
        window.draw(title);
        window.draw(txt_username);
        window.draw(txt_password);
        window.draw(errormsg);
        txtbox_username.drawTo(window);
        txtbox_password.drawTo(window);
        enter.drawTo(window);
        cancel.drawTo(window);
        window.display();
    }
}

int Viewer::menu2()
{
    sf::RenderWindow window(sf::VideoMode(700, 800), "Welcome!", sf::Style::Default ^ sf::Style::Resize);
    sf::Font font;
    font.loadFromFile("consola.ttf");

    sf::Text title;
    title.setFont(font);
    title.setFillColor(sf::Color::Red);
    title.setCharacterSize(100);
    title.setString("BBS");
    title.setPosition({ 255, 50 });

    Button board("View Boards", { 400, 70 }, 50, sf::Color::Black, sf::Color::White);
    board.setFont(font);
    board.setPos({ 150, 220 });
    Button mailbox("Mailbox", { 400, 70 }, 50, sf::Color::Black, sf::Color::White);
    mailbox.setFont(font);
    mailbox.setPos({ 150, 320 });
    Button logout("Log out", { 400, 70 }, 50, sf::Color::Black, sf::Color::White);
    logout.setFont(font);
    logout.setPos({ 150, 420 });

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseMoved:
                if (board.isMouseOver(window)) {
                    board.setBgColor(sf::Color::White);
                    board.setTxtColor(sf::Color::Black);
                }
                else if (mailbox.isMouseOver(window)) {
                    mailbox.setBgColor(sf::Color::White);
                    mailbox.setTxtColor(sf::Color::Black);
                }
                else if (logout.isMouseOver(window)) {
                    logout.setBgColor(sf::Color::White);
                    logout.setTxtColor(sf::Color::Black);
                }
                else {
                    board.setBgColor(sf::Color::Black);
                    board.setTxtColor(sf::Color::White);
                    mailbox.setBgColor(sf::Color::Black);
                    mailbox.setTxtColor(sf::Color::White);
                    logout.setBgColor(sf::Color::Black);
                    logout.setTxtColor(sf::Color::White);
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (logout.isMouseOver(window)) {
                    return 0;
                }
                if (board.isMouseOver(window)) {
                    return 1;
                }
                if (mailbox.isMouseOver(window)) {
                    return 2;
                }
                break;
            }
        }

        board.drawTo(window);
        mailbox.drawTo(window);
        logout.drawTo(window);
        window.draw(title);
        window.display();
    }
}

void Viewer::mailbox()
{

}

int Viewer::board_select(vector<Board> boards, int permission_lv)
{
    sf::RenderWindow window(sf::VideoMode(700, 800), "Boards", sf::Style::Default ^ sf::Style::Resize);
    sf::Font font;
    font.loadFromFile("consola.ttf");

    sf::Text title;
    title.setFont(font);
    title.setFillColor(sf::Color::Red);
    title.setCharacterSize(50);
    title.setString("Boards");
    title.setPosition({40, 30});
    
    //boards
    int current = 0;
    int board_amount = boards.size();
    //bool btnOn[8] = { true, true, true, true, true, true, true, true };
    vector<Button>board_btn;
    for (int i = 0; i < 8; i++) {
        if (i < board_amount) {
            Button btn(boards[i].board_name, { 660, 50 }, 30, sf::Color::Black, sf::Color::White);
            board_btn.push_back(btn);
            board_btn[i].setFont(font);
            board_btn[i].setPos({ 20, (float)(130 + (70 * i)) });
        }
        else if (i >= board_amount) {
            Button btn("", { 660, 50 }, 30, sf::Color::Black, sf::Color::White);
            board_btn.push_back(btn);
            board_btn[i].setFont(font);
            board_btn[i].setPos({ 20, (float)(130 + (70 * i)) });
            board_btn[i].btnOff();
        }
    }
    //functional buttons
    Button back("Back", { 100, 40 }, 25, sf::Color::White, sf::Color::Black);
    back.setFont(font);
    back.setPos({ 50, 730 });
    Button logout("Logout", { 100, 40 }, 24, sf::Color::White, sf::Color::Black);
    logout.setFont(font);
    logout.setPos({ 180, 730 });
    Button prev("<<Prev", { 100, 40 }, 22, sf::Color::White, sf::Color::Black);
    prev.setFont(font);
    prev.setPos({ 420, 730 });
    Button next("Next>>", { 100, 40 }, 22, sf::Color::White, sf::Color::Black);
    next.setFont(font);
    next.setPos({ 550, 730 });
    Button add_board("Add", { 100, 40 }, 25, sf::Color::White, sf::Color::Black);
    add_board.setFont(font);
    add_board.setPos({ 420, 40 });
    Button del_board("Delete", { 100, 40 }, 25, sf::Color::White, sf::Color::Black);
    del_board.setFont(font);
    del_board.setPos({ 550, 40 });
    if (permission_lv != 2) {
        add_board.btnOff();
        del_board.btnOff();
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseMoved:
                if (board_btn[0].isOn() && board_btn[0].isMouseOver(window)) {
                    board_btn[0].setBgColor(sf::Color::White);
                    board_btn[0].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[1].isOn() && board_btn[1].isMouseOver(window)) {
                    board_btn[1].setBgColor(sf::Color::White);
                    board_btn[1].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[2].isOn() && board_btn[2].isMouseOver(window)) {
                    board_btn[2].setBgColor(sf::Color::White);
                    board_btn[2].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[3].isOn() && board_btn[3].isMouseOver(window)) {
                    board_btn[3].setBgColor(sf::Color::White);
                    board_btn[3].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[4].isOn() && board_btn[4].isMouseOver(window)) {
                    board_btn[4].setBgColor(sf::Color::White);
                    board_btn[4].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[5].isOn() && board_btn[5].isMouseOver(window)) {
                    board_btn[5].setBgColor(sf::Color::White);
                    board_btn[5].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[6].isOn() && board_btn[6].isMouseOver(window)) {
                    board_btn[6].setBgColor(sf::Color::White);
                    board_btn[6].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[7].isOn() && board_btn[7].isMouseOver(window)) {
                    board_btn[7].setBgColor(sf::Color::White);
                    board_btn[7].setTxtColor(sf::Color::Black);
                }
                else if (back.isMouseOver(window)) {
                    back.setBgColor(sf::Color::Red);
                    back.setTxtColor(sf::Color::White);
                }
                else if (logout.isMouseOver(window)) {
                    logout.setBgColor(sf::Color::Blue);
                    logout.setTxtColor(sf::Color::White);
                }
                else if (prev.isMouseOver(window)) {
                    prev.setBgColor(sf::Color::Yellow);
                }
                else if (next.isMouseOver(window)) {
                    next.setBgColor(sf::Color::Yellow);
                }
                else if (add_board.isOn() && add_board.isMouseOver(window)) {
                    add_board.setBgColor(sf::Color::Green);
                }
                else if (del_board.isOn() && del_board.isMouseOver(window)) {
                    del_board.setBgColor(sf::Color::Red);
                    del_board.setTxtColor(sf::Color::White);
                }
                else {
                    for (int i = 0; i < 8; i++) {
                        board_btn[i].setBgColor(sf::Color::Black);
                        board_btn[i].setTxtColor(sf::Color::White);
                    }
                    back.setBgColor(sf::Color::White);
                    back.setTxtColor(sf::Color::Black);
                    logout.setBgColor(sf::Color::White);
                    logout.setTxtColor(sf::Color::Black);
                    prev.setBgColor(sf::Color::White);
                    next.setBgColor(sf::Color::White);
                    add_board.setBgColor(sf::Color::White);
                    del_board.setBgColor(sf::Color::White);
                    del_board.setTxtColor(sf::Color::Black);
                }
                break;
            case sf::Event::MouseButtonPressed:
#if DEBUG
                if (board_btn[0].isOn() && board_btn[0].isMouseOver(window)) {
                    cout << "Board " << current << endl;
                }
                if (board_btn[1].isOn() && board_btn[1].isMouseOver(window)) {
                    cout << "Board " << current + 1 << endl;
                }
                if (board_btn[2].isOn() && board_btn[2].isMouseOver(window)) {
                    cout << "Board " << current + 2 << endl;
                }
                if (board_btn[3].isOn() && board_btn[3].isMouseOver(window)) {
                    cout << "Board " << current + 3 << endl;
                }
                if (board_btn[4].isOn() && board_btn[4].isMouseOver(window)) {
                    cout << "Board " << current + 4 << endl;
                }
                if (board_btn[5].isOn() && board_btn[5].isMouseOver(window)) {
                    cout << "Board " << current + 5 << endl;
                }
                if (board_btn[6].isOn() && board_btn[6].isMouseOver(window)) {
                    cout << "Board " << current + 6 << endl;
                }
                if (board_btn[7].isOn() && board_btn[7].isMouseOver(window)) {
                    cout << "Board " << current + 7 << endl;
                }
                if (back.isMouseOver(window)) {
                    cout << "back" << endl;
                }
                if (logout.isMouseOver(window)) {
                    cout << "Logout" << endl;
                }
                if (prev.isMouseOver(window)) {
                    cout << "Prev" << endl;
                    if (current > 0) current -= 8;
                    for (int i = 0; i < 8; i++) {
                        if (i + current < board_amount) {
                            board_btn[i].btnOn();
                            board_btn[i].setText(boards[i + current].board_name);
                        }
                        else if (i + current >= board_amount) {
                            board_btn[i].btnOff();
                            board_btn[i].setText("");
                        }
                    }
                }
                if (next.isMouseOver(window)) {
                    cout << "Next " << endl;
                    if (current + 8 < board_amount) current += 8;
                    for (int i = 0; i < 8; i++) {
                        if (i + current < board_amount) {
                            board_btn[i].btnOn();
                            board_btn[i].setText(boards[i + current].board_name);
                        }
                        else if (i + current >= board_amount) {
                            board_btn[i].btnOff();
                            board_btn[i].setText("");
                        }
                    }
                }
                if (add_board.isOn() && add_board.isMouseOver(window)) {
                    cout << "add board" << endl;
                }
                if (del_board.isOn() && del_board.isMouseOver(window)) {
                    cout << "delete board" << endl;
                }
#else
                if (board_btn[0].isOn() && board_btn[0].isMouseOver(window)) {
                    return current;
                }
                if (board_btn[1].isOn() && board_btn[1].isMouseOver(window)) {
                    return current + 1;
                }
                if (board_btn[2].isOn() && board_btn[2].isMouseOver(window)) {
                    return current + 2;
                }
                if (board_btn[3].isOn() && board_btn[3].isMouseOver(window)) {
                    return current + 3;
                }
                if (board_btn[4].isOn() && board_btn[4].isMouseOver(window)) {
                    return current + 4;
                }
                if (board_btn[5].isOn() && board_btn[5].isMouseOver(window)) {
                    return current + 5;
                }
                if (board_btn[6].isOn() && board_btn[6].isMouseOver(window)) {
                    return current + 6;
                }
                if (board_btn[7].isOn() && board_btn[7].isMouseOver(window)) {
                    return current + 7;
                }
                if (back.isMouseOver(window)) {
                    return -1;
                }
                if (logout.isMouseOver(window)) {
                    return -2;
                }
                if (prev.isMouseOver(window)) {
                    //cout << "Prev" << endl;
                    if (current > 0) {
                        current -= 8;
                        for (int i = 0; i < 8; i++) {
                            if (i + current < board_amount) {
                                board_btn[i].btnOn();
                                board_btn[i].setText(boards[i + current].board_name);
                            }
                            else if (i + current >= board_amount) {
                                board_btn[i].btnOff();
                                board_btn[i].setText("");
                            }
                        }
                    }
                }
                if (next.isMouseOver(window)) {
                    //cout << "Next " << endl;
                    if (current + 8 < board_amount) {
                        current += 8;
                        for (int i = 0; i < 8; i++) {
                            if (i + current < board_amount) {
                                board_btn[i].btnOn();
                                board_btn[i].setText(boards[i + current].board_name);
                            }
                            else if (i + current >= board_amount) {
                                board_btn[i].btnOff();
                                board_btn[i].setText("");
                            }
                        }
                    }
                }
                if (add_board.isOn() && add_board.isMouseOver(window)) {
                    return -3;
                }
                if (del_board.isOn() && del_board.isMouseOver(window)) {
                    return -4;
                }
#endif
                break;
            }
        }

        window.clear();
        for (int i = 0; i < 8; i++) {
            board_btn[i].drawTo(window);
        }
        back.drawTo(window);
        logout.drawTo(window);
        prev.drawTo(window);
        next.drawTo(window);
        if (permission_lv == 2) {
            add_board.drawTo(window);
            del_board.drawTo(window);
        }
        window.draw(title);
        window.display();
    }
}

int Viewer::board_add(vector<Board> boards, string& name)
{
    sf::RenderWindow window(sf::VideoMode(700, 800), "add board", sf::Style::Default ^ sf::Style::Resize);
    sf::Font font;
    font.loadFromFile("consola.ttf");

    sf::Text title, txt;
    title.setFont(font);
    title.setCharacterSize(70);
    title.setFillColor(sf::Color::Red);
    title.setString("Add Board");
    title.setPosition({ 165, 90 });
    txt.setFont(font);
    txt.setCharacterSize(30);
    txt.setFillColor(sf::Color::White);
    txt.setString("Boardname:");
    txt.setPosition({ 100, 250 });
    sf::Text errormsg;
    errormsg.setFont(font);
    errormsg.setCharacterSize(20);
    errormsg.setFillColor(sf::Color::Black);
    errormsg.setString("Invalid Input");
    errormsg.setPosition({ 265, 380 });
    

    Textbox txtbox_boardname(30, sf::Color::Black, false);
    txtbox_boardname.setFont(font);
    txtbox_boardname.setPos({ 100, 300 });
    txtbox_boardname.setLimit(true, 15);


    Button enter("Enter", { 130, 65 }, 30, sf::Color::White, sf::Color::Black);
    enter.setFont(font);
    enter.setPos({ 150, 450 });
    Button cancel("Cancel", { 130, 65 }, 30, sf::Color::White, sf::Color::Black);
    cancel.setFont(font);
    cancel.setPos({ 400, 450 });

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::TextEntered:
                if (txtbox_boardname.isSel()) {
                    txtbox_boardname.typedOn(event);
                }
                break;
            case sf::Event::MouseMoved:
                if (enter.isMouseOver(window)) {
                    enter.setTxtColor(sf::Color::White);
                    enter.setBgColor(sf::Color(0, 204, 0));
                }
                else if (cancel.isMouseOver(window)) {
                    cancel.setTxtColor(sf::Color::White);
                    cancel.setBgColor(sf::Color::Red);
                }
                else {
                    enter.setTxtColor(sf::Color::Black);
                    enter.setBgColor(sf::Color::White);
                    cancel.setTxtColor(sf::Color::Black);
                    cancel.setBgColor(sf::Color::White);
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (txtbox_boardname.isMouseOver(window)) {
                    txtbox_boardname.setSelected(true);
                }
                else if (enter.isMouseOver(window)) {
                    txtbox_boardname.setSelected(false);
                    name = txtbox_boardname.getText();
                    //cout << name << endl;
                    bool valid = true;
                    for (int i = 0; i < boards.size(); i++) {
                        if (boards[i].board_name == name || name == "") {
                            valid = false;
                            errormsg.setFillColor(sf::Color::Red);
                            break;
                        }
                    }
                    if (valid) {
                        errormsg.setFillColor(sf::Color::Black);
                        return 1;
                    }
                }
                else if (cancel.isMouseOver(window)) {
                    //cout << "cancel" << endl;
                    txtbox_boardname.setSelected(false);
                    return -1;
                }
                else {
                    txtbox_boardname.setSelected(false);
                }
                break;
            }
        }

        window.clear();
        window.draw(title);
        window.draw(txt);
        window.draw(errormsg);
        txtbox_boardname.drawTo(window);
        enter.drawTo(window);
        cancel.drawTo(window);
        window.display();
    }
}

int Viewer::board_delete(vector<Board> boards)
{
    sf::RenderWindow window(sf::VideoMode(700, 800), "Delete Board", sf::Style::Default ^ sf::Style::Resize);
    sf::Font font;
    font.loadFromFile("consola.ttf");

    sf::Text title;
    title.setFont(font);
    title.setFillColor(sf::Color::Red);
    title.setCharacterSize(50);
    title.setString("Delete Board");
    title.setPosition({ 40, 30 });

    //boards
    int current = 0;
    int board_amount = boards.size();
    //bool btnOn[8] = { true, true, true, true, true, true, true, true };
    vector<Button>board_btn;
    for (int i = 0; i < 8; i++) {
        if (i < board_amount) {
            Button btn(boards[i].board_name, { 660, 50 }, 30, sf::Color::Black, sf::Color::White);
            board_btn.push_back(btn);
            board_btn[i].setFont(font);
            board_btn[i].setPos({ 20, (float)(130 + (70 * i)) });
        }
        else if (i >= board_amount) {
            Button btn("", { 660, 50 }, 30, sf::Color::Black, sf::Color::White);
            board_btn.push_back(btn);
            board_btn[i].setFont(font);
            board_btn[i].setPos({ 20, (float)(130 + (70 * i)) });
            board_btn[i].btnOff();
        }
    }
    //functional buttons
    Button back("Back", { 100, 40 }, 25, sf::Color::White, sf::Color::Black);
    back.setFont(font);
    back.setPos({ 50, 730 });
    Button prev("<<Prev", { 100, 40 }, 22, sf::Color::White, sf::Color::Black);
    prev.setFont(font);
    prev.setPos({ 420, 730 });
    Button next("Next>>", { 100, 40 }, 22, sf::Color::White, sf::Color::Black);
    next.setFont(font);
    next.setPos({ 550, 730 });

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseMoved:
                if (board_btn[0].isOn() && board_btn[0].isMouseOver(window)) {
                    board_btn[0].setBgColor(sf::Color::White);
                    board_btn[0].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[1].isOn() && board_btn[1].isMouseOver(window)) {
                    board_btn[1].setBgColor(sf::Color::White);
                    board_btn[1].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[2].isOn() && board_btn[2].isMouseOver(window)) {
                    board_btn[2].setBgColor(sf::Color::White);
                    board_btn[2].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[3].isOn() && board_btn[3].isMouseOver(window)) {
                    board_btn[3].setBgColor(sf::Color::White);
                    board_btn[3].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[4].isOn() && board_btn[4].isMouseOver(window)) {
                    board_btn[4].setBgColor(sf::Color::White);
                    board_btn[4].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[5].isOn() && board_btn[5].isMouseOver(window)) {
                    board_btn[5].setBgColor(sf::Color::White);
                    board_btn[5].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[6].isOn() && board_btn[6].isMouseOver(window)) {
                    board_btn[6].setBgColor(sf::Color::White);
                    board_btn[6].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[7].isOn() && board_btn[7].isMouseOver(window)) {
                    board_btn[7].setBgColor(sf::Color::White);
                    board_btn[7].setTxtColor(sf::Color::Black);
                }
                else if (back.isMouseOver(window)) {
                    back.setBgColor(sf::Color::Red);
                    back.setTxtColor(sf::Color::White);
                }
                else if (prev.isMouseOver(window)) {
                    prev.setBgColor(sf::Color::Yellow);
                }
                else if (next.isMouseOver(window)) {
                    next.setBgColor(sf::Color::Yellow);
                }
                else {
                    for (int i = 0; i < 8; i++) {
                        board_btn[i].setBgColor(sf::Color::Black);
                        board_btn[i].setTxtColor(sf::Color::White);
                    }
                    back.setBgColor(sf::Color::White);
                    back.setTxtColor(sf::Color::Black);
                    prev.setBgColor(sf::Color::White);
                    next.setBgColor(sf::Color::White);
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (board_btn[0].isOn() && board_btn[0].isMouseOver(window)) {
                    return current;
                }
                if (board_btn[1].isOn() && board_btn[1].isMouseOver(window)) {
                    return current + 1;
                }
                if (board_btn[2].isOn() && board_btn[2].isMouseOver(window)) {
                    return current + 2;
                }
                if (board_btn[3].isOn() && board_btn[3].isMouseOver(window)) {
                    return current + 3;
                }
                if (board_btn[4].isOn() && board_btn[4].isMouseOver(window)) {
                    return current + 4;
                }
                if (board_btn[5].isOn() && board_btn[5].isMouseOver(window)) {
                    return current + 5;
                }
                if (board_btn[6].isOn() && board_btn[6].isMouseOver(window)) {
                    return current + 6;
                }
                if (board_btn[7].isOn() && board_btn[7].isMouseOver(window)) {
                    return current + 7;
                }
                if (back.isMouseOver(window)) {
                    return -1;
                }
                if (prev.isMouseOver(window)) {
                    //cout << "Prev" << endl;
                    if (current > 0) {
                        current -= 8;
                        for (int i = 0; i < 8; i++) {
                            if (i + current < board_amount) {
                                board_btn[i].btnOn();
                                board_btn[i].setText(boards[i + current].board_name);
                            }
                            else if (i + current >= board_amount) {
                                board_btn[i].btnOff();
                                board_btn[i].setText("");
                            }
                        }
                    }
                }
                if (next.isMouseOver(window)) {
                    //cout << "Next " << endl;
                    if (current + 8 < board_amount) {
                        current += 8;
                        for (int i = 0; i < 8; i++) {
                            if (i + current < board_amount) {
                                board_btn[i].btnOn();
                                board_btn[i].setText(boards[i + current].board_name);
                            }
                            else if (i + current >= board_amount) {
                                board_btn[i].btnOff();
                                board_btn[i].setText("");
                            }
                        }
                    }
                }
                break;
            }
        }

        window.clear();
        for (int i = 0; i < 8; i++) {
            board_btn[i].drawTo(window);
        }
        back.drawTo(window);
        prev.drawTo(window);
        next.drawTo(window);
        window.draw(title);
        window.display();
    }
}

int Viewer::post_select(Board cur_board)
{
    sf::RenderWindow window(sf::VideoMode(700, 800), cur_board.board_name, sf::Style::Default ^ sf::Style::Resize);
    sf::Font font;
    font.loadFromFile("consola.ttf");

    sf::Text title(cur_board.board_name, font, 50);
    title.setFillColor(sf::Color::Red);
    title.setPosition({ 40, 30 });

    //boards
    int current = 0;
    int post_amount = cur_board.all_Post.size();
    //bool btnOn[8] = { true, true, true, true, true, true, true, true };
    vector<Button>post_btn;
    for (int i = 0; i < 8; i++) {
        if (i < post_amount) {
            Button btn(cur_board.all_Post[i].title, { 660, 50 }, 30, sf::Color::Black, sf::Color::White);
            post_btn.push_back(btn);
            post_btn[i].setFont(font);
            post_btn[i].setPos({ 20, (float)(130 + (70 * i)) });
        }
        else if (i >= post_amount) {
            Button btn("", { 660, 50 }, 30, sf::Color::Black, sf::Color::White);
            post_btn.push_back(btn);
            post_btn[i].setFont(font);
            post_btn[i].setPos({ 20, (float)(130 + (70 * i)) });
            post_btn[i].btnOff();
        }
    }
    //functional buttons
    Button back("Back", { 100, 40 }, 25, sf::Color::White, sf::Color::Black);
    back.setFont(font);
    back.setPos({ 50, 730 });
    Button logout("Logout", { 100, 40 }, 24, sf::Color::White, sf::Color::Black);
    logout.setFont(font);
    logout.setPos({ 180, 730 });
    Button prev("<<Prev", { 100, 40 }, 22, sf::Color::White, sf::Color::Black);
    prev.setFont(font);
    prev.setPos({ 420, 730 });
    Button next("Next>>", { 100, 40 }, 22, sf::Color::White, sf::Color::Black);
    next.setFont(font);
    next.setPos({ 550, 730 });
    Button add("Add Post", { 200, 40 }, 25, sf::Color(255, 128, 0), sf::Color::White);
    add.setFont(font);
    add.setPos({ 450, 40 });

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseMoved:
                if (post_btn[0].isOn() && post_btn[0].isMouseOver(window)) {
                    post_btn[0].setBgColor(sf::Color::White);
                    post_btn[0].setTxtColor(sf::Color::Black);
                }
                else if (post_btn[1].isOn() && post_btn[1].isMouseOver(window)) {
                    post_btn[1].setBgColor(sf::Color::White);
                    post_btn[1].setTxtColor(sf::Color::Black);
                }
                else if (post_btn[2].isOn() && post_btn[2].isMouseOver(window)) {
                    post_btn[2].setBgColor(sf::Color::White);
                    post_btn[2].setTxtColor(sf::Color::Black);
                }
                else if (post_btn[3].isOn() && post_btn[3].isMouseOver(window)) {
                    post_btn[3].setBgColor(sf::Color::White);
                    post_btn[3].setTxtColor(sf::Color::Black);
                }
                else if (post_btn[4].isOn() && post_btn[4].isMouseOver(window)) {
                    post_btn[4].setBgColor(sf::Color::White);
                    post_btn[4].setTxtColor(sf::Color::Black);
                }
                else if (post_btn[5].isOn() && post_btn[5].isMouseOver(window)) {
                    post_btn[5].setBgColor(sf::Color::White);
                    post_btn[5].setTxtColor(sf::Color::Black);
                }
                else if (post_btn[6].isOn() && post_btn[6].isMouseOver(window)) {
                    post_btn[6].setBgColor(sf::Color::White);
                    post_btn[6].setTxtColor(sf::Color::Black);
                }
                else if (post_btn[7].isOn() && post_btn[7].isMouseOver(window)) {
                    post_btn[7].setBgColor(sf::Color::White);
                    post_btn[7].setTxtColor(sf::Color::Black);
                }
                else if (back.isMouseOver(window)) {
                    back.setBgColor(sf::Color::Red);
                    back.setTxtColor(sf::Color::White);
                }
                else if (logout.isMouseOver(window)) {
                    logout.setBgColor(sf::Color::Blue);
                    logout.setTxtColor(sf::Color::White);
                }
                else if (prev.isMouseOver(window)) {
                    prev.setBgColor(sf::Color::Yellow);
                }
                else if (next.isMouseOver(window)) {
                    next.setBgColor(sf::Color::Yellow);
                }
                else if (add.isMouseOver(window)) {
                    add.setBgColor(sf::Color(204, 102, 0));
                }
                else {
                    for (int i = 0; i < 8; i++) {
                        post_btn[i].setBgColor(sf::Color::Black);
                        post_btn[i].setTxtColor(sf::Color::White);
                    }
                    back.setBgColor(sf::Color::White);
                    back.setTxtColor(sf::Color::Black);
                    logout.setBgColor(sf::Color::White);
                    logout.setTxtColor(sf::Color::Black);
                    prev.setBgColor(sf::Color::White);
                    next.setBgColor(sf::Color::White);
                    add.setBgColor(sf::Color(255, 128, 0));
                }
                break;
            case sf::Event::MouseButtonPressed:
#if DEBUG
                if (post_btn[0].isOn() && post_btn[0].isMouseOver(window)) {
                    cout << "Post " << cur_board.post_id[current] << endl;
                }
                if (post_btn[1].isOn() && post_btn[1].isMouseOver(window)) {
                    cout << "Post " << cur_board.post_id[current + 1] << endl;
                }
                if (post_btn[2].isOn() && post_btn[2].isMouseOver(window)) {
                    cout << "Post " << cur_board.post_id[current + 2] << endl;
                }
                if (post_btn[3].isOn() && post_btn[3].isMouseOver(window)) {
                    cout << "Post " << cur_board.post_id[current + 3] << endl;
                }
                if (post_btn[4].isOn() && post_btn[4].isMouseOver(window)) {
                    cout << "Post " << cur_board.post_id[current + 4] << endl;
                }
                if (post_btn[5].isOn() && post_btn[5].isMouseOver(window)) {
                    cout << "Post " << cur_board.post_id[current + 5] << endl;
                }
                if (post_btn[6].isOn() && post_btn[6].isMouseOver(window)) {
                    cout << "Post " << cur_board.post_id[current + 6] << endl;
                }
                if (post_btn[7].isOn() && post_btn[7].isMouseOver(window)) {
                    cout << "Post " << cur_board.post_id[current + 7] << endl;
                }
                if (back.isMouseOver(window)) {
                    cout << "back" << endl;
                }
                if (logout.isMouseOver(window)) {
                    cout << "Logout" << endl;
                }
                if (prev.isMouseOver(window)) {
                    cout << "Prev" << endl;
                    if (current > 0) current -= 8;
                    for (int i = 0; i < 8; i++) {
                        if (i + current < post_amount) {
                            post_btn[i].btnOn();
                            post_btn[i].setText(cur_board.all_Post[i + current].title[0]);
                        }
                        else if (i + current >= post_amount) {
                            post_btn[i].btnOff();
                            post_btn[i].setText("");
                        }
                    }
                }
                if (next.isMouseOver(window)) {
                    cout << "Next " << endl;
                    if (current + 8 < post_amount) current += 8;
                    for (int i = 0; i < 8; i++) {
                        if (i + current < post_amount) {
                            post_btn[i].btnOn();
                            post_btn[i].setText(cur_board.all_Post[i + current].title[0]);
                        }
                        else if (i + current >= post_amount) {
                            post_btn[i].btnOff();
                            post_btn[i].setText("");
                        }
                    }
                }
#else
                if (post_btn[0].isOn() && post_btn[0].isMouseOver(window)) {
                    return cur_board.post_id[current];
                }
                if (post_btn[1].isOn() && post_btn[1].isMouseOver(window)) {
                    return cur_board.post_id[current + 1];
                }
                if (post_btn[2].isOn() && post_btn[2].isMouseOver(window)) {
                    return cur_board.post_id[current + 2];
                }
                if (post_btn[3].isOn() && post_btn[3].isMouseOver(window)) {
                    return cur_board.post_id[current + 3];
                }
                if (post_btn[4].isOn() && post_btn[4].isMouseOver(window)) {
                    return cur_board.post_id[current + 4];
                }
                if (post_btn[5].isOn() && post_btn[5].isMouseOver(window)) {
                    return cur_board.post_id[current + 5];
                }
                if (post_btn[6].isOn() && post_btn[6].isMouseOver(window)) {
                    return cur_board.post_id[current + 6];
                }
                if (post_btn[7].isOn() && post_btn[7].isMouseOver(window)) {
                    return cur_board.post_id[current + 7];
                }
                if (back.isMouseOver(window)) {
                    return -1;
                }
                if (logout.isMouseOver(window)) {
                    return -2;
                }
                if (prev.isMouseOver(window)) {
                    //cout << "Prev" << endl;
                    if (current > 0) {
                        current -= 8;
                        for (int i = 0; i < 8; i++) {
                            if (i + current < post_amount) {
                                post_btn[i].btnOn();
                                post_btn[i].setText(cur_board.all_Post[i + current].title);
                            }
                            else if (i + current >= post_amount) {
                                post_btn[i].btnOff();
                                post_btn[i].setText("");
                            }
                        }
                    }
                }
                if (next.isMouseOver(window)) {
                    //cout << "Next " << endl;
                    if (current + 8 < post_amount) {
                        current += 8;
                        for (int i = 0; i < 8; i++) {
                            if (i + current < post_amount) {
                                post_btn[i].btnOn();
                                post_btn[i].setText(cur_board.all_Post[i + current].title);
                            }
                            else if (i + current >= post_amount) {
                                post_btn[i].btnOff();
                                post_btn[i].setText("");
                            }
                        }
                    }
                }
                if (add.isMouseOver(window)) {
                    return -3;
                }
#endif
                break;
            }
        }

        window.clear();
        for (int i = 0; i < 8; i++) {
            post_btn[i].drawTo(window);
        }
        back.drawTo(window);
        logout.drawTo(window);
        prev.drawTo(window);
        next.drawTo(window);
        add.drawTo(window);
        window.draw(title);
        window.display();
    }
}

int Viewer::view_post(vector<Post> posts, string author, int postID, int boardID, int userID, int permission_lv)
{
    sf::RenderWindow window(sf::VideoMode(700, 800), posts[postID].title, sf::Style::Default ^ sf::Style::Resize);
    sf::Font font;
    font.loadFromFile("consola.ttf");

    string a = "Author: " + author, t = "Title: " + posts[postID].title;
    sf::Text txt_author(a, font, 30);
    txt_author.setFillColor(sf::Color::Red);
    txt_author.setPosition({ 30, 45 });
    sf::Text title(t, font, 30);
    title.setFillColor(sf::Color::White);
    title.setPosition({ 30, 120 });

    //boards
    int current = 0;
    int line_amount = posts[postID].content.size();
    vector<sf::Text>lines;
    for (int i = 0; i < 12; i++) {
        if (i < line_amount) {
            sf::Text line(posts[postID].content[i], font, 30);
            lines.push_back(line);
            lines[i].setFillColor(sf::Color::White);
            lines[i].setPosition({ 70, (float)(200 + (40 * i)) });
        }
        else if (i >= line_amount) {
            sf::Text line("", font, 30);
            lines.push_back(line);
            lines[i].setFillColor(sf::Color::White);
            lines[i].setPosition({ 70, (float)(200 + (30 * i)) });
        }
    }
    //functional buttons
    Button back("Back", { 100, 40 }, 25, sf::Color::White, sf::Color::Black);
    back.setFont(font);
    back.setPos({ 50, 730 });
    Button logout("Logout", { 100, 40 }, 24, sf::Color::White, sf::Color::Black);
    logout.setFont(font);
    logout.setPos({ 175, 730 });
    Button comment("Comment", { 100, 40 }, 22, sf::Color(255, 128, 0), sf::Color::White);
    comment.setFont(font);
    comment.setPos({ 300, 730 });
    Button pgup("<<PgUp", { 100, 40 }, 22, sf::Color::White, sf::Color::Black);
    pgup.setFont(font);
    pgup.setPos({ 425, 730 });
    Button pgdn("PgDn>>", { 100, 40 }, 22, sf::Color::White, sf::Color::Black);
    pgdn.setFont(font);
    pgdn.setPos({ 550, 730 });
    Button edit("Edit", { 100, 40 }, 25, sf::Color::White, sf::Color::Black);
    edit.setFont(font);
    edit.setPos({ 420, 40 });
    Button del("Delete", { 100, 40 }, 25, sf::Color::White, sf::Color::Black);
    del.setFont(font);
    del.setPos({ 550, 40 });
    if (permission_lv != 2) {
        edit.btnOff();
        del.btnOff();
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseMoved:
                if (back.isMouseOver(window)) {
                    back.setBgColor(sf::Color::Red);
                    back.setTxtColor(sf::Color::White);
                }
                else if (logout.isMouseOver(window)) {
                    logout.setBgColor(sf::Color::Blue);
                    logout.setTxtColor(sf::Color::White);
                }
                else if (comment.isMouseOver(window)) {
                    comment.setBgColor(sf::Color(204, 102, 0));
                }
                else if (pgup.isMouseOver(window)) {
                    pgup.setBgColor(sf::Color::Yellow);
                }
                else if (pgdn.isMouseOver(window)) {
                    pgdn.setBgColor(sf::Color::Yellow);
                }
                else if (edit.isOn() && edit.isMouseOver(window)) {
                    edit.setBgColor(sf::Color::Green);
                }
                else if (del.isOn() && del.isMouseOver(window)) {
                    del.setBgColor(sf::Color::Red);
                    del.setTxtColor(sf::Color::White);
                }
                else {
                    back.setBgColor(sf::Color::White);
                    back.setTxtColor(sf::Color::Black);
                    logout.setBgColor(sf::Color::White);
                    logout.setTxtColor(sf::Color::Black);
                    comment.setBgColor(sf::Color(255, 128, 0));
                    pgup.setBgColor(sf::Color::White);
                    pgdn.setBgColor(sf::Color::White);
                    edit.setBgColor(sf::Color::White);
                    del.setBgColor(sf::Color::White);
                    del.setTxtColor(sf::Color::Black);
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (back.isMouseOver(window)) {
                    //cout << "back" << endl;
                    return -1;
                }
                if (logout.isMouseOver(window)) {
                    //cout << "logout" << endl;
                    return -2;
                }
                if (comment.isMouseOver(window)) {
                    //cout << "comment" << endl;
                    return -3;
                }
                if (pgup.isMouseOver(window)) {
                    cout << "Pgup" << endl;
                    if (current > 0) {
                        current -= 12;
                        for (int i = 0; i < 12; i++) {
                            if (i + current < line_amount) {
                                lines[i].setString(posts[postID].content[i + current]);
                            }
                            else if (i + current >= line_amount) {
                                lines[i].setString("");
                            }
                        }
                    }
                }
                if (pgdn.isMouseOver(window)) {
                    cout << "Pgdn " << endl;
                    if (current + 12 < line_amount) {
                        current += 12;
                        for (int i = 0; i < 12; i++) {
                            if (i + current < line_amount) {
                                lines[i].setString(posts[postID].content[i + current]);
                            }
                            else if (i + current >= line_amount) {
                                lines[i].setString("");
                            }
                        }
                    }
                }
                if (edit.isOn() && edit.isMouseOver(window)) {
                    //cout << "edit" << endl;
                    return -4;
                }
                if (del.isOn() && del.isMouseOver(window)) {
                    //cout << "del" << endl;
                    return -5;
                }
                break;
            }
        }

        window.clear();
        for (int i = 0; i < 12; i++) {
            window.draw(lines[i]);
        }        
        window.draw(txt_author);
        window.draw(title);
        back.drawTo(window);
        logout.drawTo(window);
        comment.drawTo(window);
        pgup.drawTo(window);
        pgdn.drawTo(window);
        if (permission_lv == 2) {
            edit.drawTo(window);
            del.drawTo(window);
        }
        window.display();
    }
}

int Viewer::view_comment(vector<Post> posts, int postID, int userID, int permission_lv)
{
    sf::RenderWindow window(sf::VideoMode(700, 800), posts[postID].title + "_comments", sf::Style::Default ^ sf::Style::Resize);
    sf::Font font;
    font.loadFromFile("consola.ttf");

    sf::Text txt_author("Comments of", font, 40);
    txt_author.setFillColor(sf::Color::Red);
    txt_author.setPosition({ 30, 30 });
    sf::Text title("> " + posts[postID].title, font, 30);
    title.setFillColor(sf::Color::White);
    title.setPosition({ 30, 90 });

    //boards
    int current = 0;
    int comment_amount = posts[postID].comments.size();

    //functional buttons
    Button back("Back", { 100, 40 }, 25, sf::Color::White, sf::Color::Black);
    back.setFont(font);
    back.setPos({ 50, 730 });
    Button comment("Write Comment", { 190, 40 }, 22, sf::Color(255, 128, 0), sf::Color::White);
    comment.setFont(font);
    comment.setPos({ 175, 730 });
    Button pgup("<<PgUp", { 100, 40 }, 22, sf::Color::White, sf::Color::Black);
    pgup.setFont(font);
    pgup.setPos({ 425, 730 });
    Button pgdn("PgDn>>", { 100, 40 }, 22, sf::Color::White, sf::Color::Black);
    pgdn.setFont(font);
    pgdn.setPos({ 550, 730 });

    vector<Button>del_btn;
    for (int i = 0; i < 8; i++) {
        Button btn("X", { 25, 25 }, 20, sf::Color::Red, sf::Color::White);
        del_btn.push_back(btn);
        del_btn[i].setFont(font);
        del_btn[i].setPos({ 630, (float)(205 + (60 * i)) });
    }
    if (permission_lv != 2) {
        for (int i = 0; i < 8; i++) {
            del_btn[i].btnOff();
        }
    }

    vector<sf::Text>comments;
    for (int i = 0; i < 8; i++) {
        if (i < comment_amount) {
            string t = posts[postID].comments[i].name + ":" + posts[postID].comments[i].com;
            sf::Text comment(t, font, 30);
            comments.push_back(comment);
            comments[i].setFillColor(sf::Color::White);
            comments[i].setPosition({ 50, (float)(200 + (60 * i)) });
        }
        else if (i >= comment_amount) {
            sf::Text comment("", font, 30);
            comments.push_back(comment);
            comments[i].setFillColor(sf::Color::White);
            comments[i].setPosition({ 50, (float)(200 + (60 * i)) });
            del_btn[i].btnOff();
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseMoved:
                if (del_btn[0].isOn() && del_btn[0].isMouseOver(window)) {
                    del_btn[0].setBgColor(sf::Color(100, 0, 0));
                }
                else if (del_btn[1].isOn() && del_btn[1].isMouseOver(window)) {
                    del_btn[1].setBgColor(sf::Color(100, 0, 0));
                }
                else if (del_btn[2].isOn() && del_btn[2].isMouseOver(window)) {
                    del_btn[2].setBgColor(sf::Color(100, 0, 0));
                }
                else if (del_btn[3].isOn() && del_btn[3].isMouseOver(window)) {
                    del_btn[3].setBgColor(sf::Color(100, 0, 0));
                }
                else if (del_btn[4].isOn() && del_btn[4].isMouseOver(window)) {
                    del_btn[4].setBgColor(sf::Color(100, 0, 0));
                }
                else if (del_btn[5].isOn() && del_btn[5].isMouseOver(window)) {
                    del_btn[5].setBgColor(sf::Color(100, 0, 0));
                }
                else if (del_btn[6].isOn() && del_btn[6].isMouseOver(window)) {
                    del_btn[6].setBgColor(sf::Color(100, 0, 0));
                }
                else if (del_btn[7].isOn() && del_btn[7].isMouseOver(window)) {
                    del_btn[7].setBgColor(sf::Color(100, 0, 0));
                }
                else if (back.isMouseOver(window)) {
                    back.setBgColor(sf::Color::Red);
                    back.setTxtColor(sf::Color::White);
                }
                else if (comment.isMouseOver(window)) {
                    comment.setBgColor(sf::Color(204, 102, 0));
                }
                else if (pgup.isMouseOver(window)) {
                    pgup.setBgColor(sf::Color::Yellow);
                }
                else if (pgdn.isMouseOver(window)) {
                    pgdn.setBgColor(sf::Color::Yellow);
                }
                else {
                    for (int i = 0; i < 8; i++) {
                        del_btn[i].setBgColor(sf::Color::Red);
                    }
                    back.setBgColor(sf::Color::White);
                    back.setTxtColor(sf::Color::Black);
                    comment.setBgColor(sf::Color(255, 128, 0));
                    pgup.setBgColor(sf::Color::White);
                    pgdn.setBgColor(sf::Color::White);
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (del_btn[0].isOn() && del_btn[0].isMouseOver(window)) {
                    //cout << "del comment no." << current + 0 << endl;
                    return current + 0;
                }
                if (del_btn[1].isOn() && del_btn[1].isMouseOver(window)) {
                    //cout << "del comment no." << current + 1 << endl;
                    return current + 1;
                }
                if (del_btn[2].isOn() && del_btn[2].isMouseOver(window)) {
                    //cout << "del comment no." << current + 2 << endl;
                    return current + 2;
                }
                if (del_btn[3].isOn() && del_btn[3].isMouseOver(window)) {
                    //cout << "del comment no." << current + 3 << endl;
                    return current + 3;
                }
                if (del_btn[4].isOn() && del_btn[4].isMouseOver(window)) {
                    //cout << "del comment no." << current + 4 << endl;
                    return current + 4;
                }
                if (del_btn[5].isOn() && del_btn[5].isMouseOver(window)) {
                    //cout << "del comment no." << current + 5 << endl;
                    return current + 5;
                }
                if (del_btn[6].isOn() && del_btn[6].isMouseOver(window)) {
                    //cout << "del comment no." << current + 6 << endl;
                    return current + 6;
                }
                if (del_btn[7].isOn() && del_btn[7].isMouseOver(window)) {
                    //cout << "del comment no." << current + 7 << endl;
                    return current + 7;
                }
                if (back.isMouseOver(window)) {
                    //cout << "back" << endl;
                    return -1;
                }
                if (comment.isMouseOver(window)) {
                    //cout << "write comment" << endl;
                    return -100;
                }
                if (pgup.isMouseOver(window)) {
                    cout << "Pgup" << endl;
                    if (current > 0) {
                        current -= 8;
                        for (int i = 0; i < 8; i++) {
                            if (i + current < comment_amount) {
                                comments[i].setString(posts[postID].comments[i + current].name + ":" + posts[postID].comments[i + current].com);
                                del_btn[i].btnOn();
                            }
                            else if (i + current >= comment_amount) {
                                comments[i].setString("");
                                del_btn[i].btnOff();
                            }
                        }
                    }
                }
                if (pgdn.isMouseOver(window)) {
                    cout << "Pgdn " << endl;
                    if (current + 8 < comment_amount) {
                        current += 8;
                        for (int i = 0; i < 8; i++) {
                            if (i + current < comment_amount) {
                                comments[i].setString(posts[postID].comments[i + current].name + ":" + posts[postID].comments[i + current].com);
                                del_btn[i].btnOn();
                            }
                            else if (i + current >= comment_amount) {
                                comments[i].setString("");
                                del_btn[i].btnOff();
                            }
                        }
                    }
                }
                break;
            }
        }

        window.clear();

        for (int i = 0; i < 8; i++) {
            window.draw(comments[i]);
        }
        window.draw(txt_author);
        window.draw(title);
        back.drawTo(window);
        comment.drawTo(window);
        pgup.drawTo(window);
        pgdn.drawTo(window);
        if (permission_lv == 2) {
            for (int i = 0; i < 8; i++) {
                if (del_btn[i].isOn())
                    del_btn[i].drawTo(window);
            }
        }
        window.display();
    }
}

int Viewer::window_txtbox(string title, string info, string& input, int limit, float posX, float posY)
{
    sf::RenderWindow window(sf::VideoMode(700, 600), "add board", sf::Style::Default ^ sf::Style::Resize);
    sf::Font font;
    font.loadFromFile("consola.ttf");

    sf::Text txt_title(title, font, 70);
    sf::Text txt_info(info, font, 30);
    sf::Text errormsg("Enter something...", font, 20);
    txt_title.setFillColor(sf::Color::Red);
    txt_title.setPosition({ posX, posY });
    txt_info.setFillColor(sf::Color::White);
    txt_info.setPosition({ 100, 245 });
    errormsg.setFillColor(sf::Color::Black);
    errormsg.setPosition({ 250, 350 });

    Textbox txtbox_input(30, sf::Color::Black, false);
    txtbox_input.setFont(font);
    txtbox_input.setPos({ 100, 295 });
    txtbox_input.setLimit(true, limit);


    Button enter("Enter", { 130, 65 }, 30, sf::Color::White, sf::Color::Black);
    enter.setFont(font);
    enter.setPos({ 150, 430 });
    Button cancel("Cancel", { 130, 65 }, 30, sf::Color::White, sf::Color::Black);
    cancel.setFont(font);
    cancel.setPos({ 400, 430 });

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::TextEntered:
                if (txtbox_input.isSel()) {
                    txtbox_input.typedOn(event);
                }
                break;
            case sf::Event::MouseMoved:
                if (enter.isMouseOver(window)) {
                    enter.setTxtColor(sf::Color::White);
                    enter.setBgColor(sf::Color(0, 204, 0));
                }
                else if (cancel.isMouseOver(window)) {
                    cancel.setTxtColor(sf::Color::White);
                    cancel.setBgColor(sf::Color::Red);
                }
                else {
                    enter.setTxtColor(sf::Color::Black);
                    enter.setBgColor(sf::Color::White);
                    cancel.setTxtColor(sf::Color::Black);
                    cancel.setBgColor(sf::Color::White);
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (txtbox_input.isMouseOver(window)) {
                    txtbox_input.setSelected(true);
                }
                else if (enter.isMouseOver(window)) {
                    txtbox_input.setSelected(false);
                    input = txtbox_input.getText();
                    if (input != "") {
                        errormsg.setFillColor(sf::Color::Black);
                        //cout << input << endl;
                        return 1;
                    }
                    else {
                        errormsg.setFillColor(sf::Color::Red);
                    }
                }
                else if (cancel.isMouseOver(window)) {
                    //cout << "cancel" << endl;
                    txtbox_input.setSelected(false);
                    return -1;
                }
                else {
                    txtbox_input.setSelected(false);
                }
                break;
            }
        }

        window.clear();
        window.draw(txt_title);
        window.draw(txt_info);
        window.draw(errormsg);
        txtbox_input.drawTo(window);
        enter.drawTo(window);
        cancel.drawTo(window);
        window.display();
    }
}

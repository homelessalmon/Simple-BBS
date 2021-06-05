#include "Viewer.h"
#define DEBUG 0

int Viewer::menu1()
{
    cout << " _ __ ___    ___  _ __   _   _" << endl;
    cout << "| '_ ` _ \\  / _ \\| '_ \\ | | | |" << endl;
    cout << "| | | | | ||  __/| | | || |_| |" << endl;
    cout << "|_| |_| |_| \\___||_| |_| \\__,_|\n" << endl;
    cout << "1. Log in" << endl;
    cout << "2. Sign up" << endl;
    cout << "3. Guest" << endl;
    cout << "0. Exit\n" << endl;
    cout << ">";
    int n;
    cin >> n;
    return n;
}

int Viewer::login(string& username, string& password, int check)
{
    cout << "  _                _" << endl;
    cout << " | |  ___    __ _ (_) _ __" << endl;
    cout << " | | / _ \\ /  _  || ||  _ \\" << endl;
    cout << " | || (_) || (_| || || | | |" << endl;
    cout << " |_| \\___/ \\__,  ||_||_| |_|" << endl;
    cout << "           |___ /\n" << endl;
    if (check == -1) cout << "--Username not exist--" << endl;
    if (check == -2) cout << "--Wrong password--" << endl;
    cout << "Back to menu: 0\n>";
    char n;
    cin >> n;
    if (n == '0') return 0;
    while ((n = getchar()) != '\n'); //clear the buffer

    system("cls");
    cout << "  _                _" << endl;
    cout << " | |  ___    __ _ (_) _ __" << endl;
    cout << " | | / _ \\ /  _  || ||  _ \\" << endl;
    cout << " | || (_) || (_| || || | | |" << endl;
    cout << " |_| \\___/ \\__,  ||_||_| |_|" << endl;
    cout << "           |___ /\n" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    char pass[32];
    char tmp;
    int i = 0;
    for (i = 0;;) {
        tmp = _getch();
        if ((tmp >= 'a' && tmp <= 'z') || (tmp >= 'A' && tmp <= 'Z') || (tmp >= '0' && tmp <= '9')) {
            pass[i] = tmp;
            ++i;
            cout << "*";
        }
        if (tmp == '\b' && i >= 1) { //if user typed backspace (i should be greater than 1)
            cout << "\b \b";//rub the character behind the cursor
            --i;
        }
        if (tmp == '\r') { //if enter is pressed
            pass[i] = '\0';//null means end of string
            break;
        }
    }
    password = pass;
    return 1;
}

int Viewer::signup(string& username, string& password, int check)
{
    cout << "       _                                " << endl;
    cout << "      (_)                               " << endl;
    cout << "  ___  _   __ _  _ __      _   _  _ __  " << endl;
    cout << " / __|| | / _` || '_ \\    | | | || '_ \\ " << endl;
    cout << " \\__ \\| || (_| || | | |   | |_| || |_) |" << endl;
    cout << " |___/|_| \\__, ||_| |_|    \\__,_|| .__/ " << endl;
    cout << "           __/ |                 | |    " << endl;
    cout << "          |___/                  |_|    \n" << endl;
    if (check == -1) cout << "--Username existed, try another one--" << endl;
    cout << "Back to menu: 0\n>";
    char n;
    cin >> n;
    if (n == '0') return 0;
    while ((n = getchar()) != '\n'); //clear the buffer

    system("cls");
    cout << "       _                                " << endl;
    cout << "      (_)                               " << endl;
    cout << "  ___  _   __ _  _ __      _   _  _ __  " << endl;
    cout << " / __|| | / _` || '_ \\    | | | || '_ \\ " << endl;
    cout << " \\__ \\| || (_| || | | |   | |_| || |_) |" << endl;
    cout << " |___/|_| \\__, ||_| |_|    \\__,_|| .__/ " << endl;
    cout << "           __/ |                 | |    " << endl;
    cout << "          |___/                  |_|    \n" << endl; 
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    char pass[32];
    char tmp;
    int i = 0;
    for (i = 0;;) {
        tmp = _getch();
        if ((tmp >= 'a' && tmp <= 'z') || (tmp >= 'A' && tmp <= 'Z') || (tmp >= '0' && tmp <= '9')) {
            pass[i] = tmp;
            ++i;
            cout << "*";
        }
        if (tmp == '\b' && i >= 1) { //if user typed backspace (i should be greater than 1)
            cout << "\b \b";//rub the character behind the cursor
            --i;
        }
        if (tmp == '\r') { //if enter is pressed
            pass[i] = '\0';//null means end of string
            break;
        }
    }
    password = pass;
    return 1;
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
                if (board_btn[0].buttonOn && board_btn[0].isMouseOver(window)) {
                    board_btn[0].setBgColor(sf::Color::White);
                    board_btn[0].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[1].buttonOn && board_btn[1].isMouseOver(window)) {
                    board_btn[1].setBgColor(sf::Color::White);
                    board_btn[1].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[2].buttonOn && board_btn[2].isMouseOver(window)) {
                    board_btn[2].setBgColor(sf::Color::White);
                    board_btn[2].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[3].buttonOn && board_btn[3].isMouseOver(window)) {
                    board_btn[3].setBgColor(sf::Color::White);
                    board_btn[3].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[4].buttonOn && board_btn[4].isMouseOver(window)) {
                    board_btn[4].setBgColor(sf::Color::White);
                    board_btn[4].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[5].buttonOn && board_btn[5].isMouseOver(window)) {
                    board_btn[5].setBgColor(sf::Color::White);
                    board_btn[5].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[6].buttonOn && board_btn[6].isMouseOver(window)) {
                    board_btn[6].setBgColor(sf::Color::White);
                    board_btn[6].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[7].buttonOn && board_btn[7].isMouseOver(window)) {
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
                else if (add_board.buttonOn && add_board.isMouseOver(window)) {
                    add_board.setBgColor(sf::Color::Green);
                }
                else if (del_board.buttonOn && del_board.isMouseOver(window)) {
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
                if (board_btn[0].buttonOn && board_btn[0].isMouseOver(window)) {
                    cout << "Board " << current << endl;
                }
                if (board_btn[1].buttonOn && board_btn[1].isMouseOver(window)) {
                    cout << "Board " << current + 1 << endl;
                }
                if (board_btn[2].buttonOn && board_btn[2].isMouseOver(window)) {
                    cout << "Board " << current + 2 << endl;
                }
                if (board_btn[3].buttonOn && board_btn[3].isMouseOver(window)) {
                    cout << "Board " << current + 3 << endl;
                }
                if (board_btn[4].buttonOn && board_btn[4].isMouseOver(window)) {
                    cout << "Board " << current + 4 << endl;
                }
                if (board_btn[5].buttonOn && board_btn[5].isMouseOver(window)) {
                    cout << "Board " << current + 5 << endl;
                }
                if (board_btn[6].buttonOn && board_btn[6].isMouseOver(window)) {
                    cout << "Board " << current + 6 << endl;
                }
                if (board_btn[7].buttonOn && board_btn[7].isMouseOver(window)) {
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
                            board_btn[i].buttonOn = true;
                            board_btn[i].setText(boards[i + current].board_name);
                        }
                        else if (i + current >= board_amount) {
                            board_btn[i].buttonOn = false;
                            board_btn[i].setText("");
                        }
                    }
                }
                if (next.isMouseOver(window)) {
                    cout << "Next " << endl;
                    if (current + 8 < board_amount) current += 8;
                    for (int i = 0; i < 8; i++) {
                        if (i + current < board_amount) {
                            board_btn[i].buttonOn = true;
                            board_btn[i].setText(boards[i + current].board_name);
                        }
                        else if (i + current >= board_amount) {
                            board_btn[i].buttonOn = false;
                            board_btn[i].setText("");
                        }
                    }
                }
                if (add_board.buttonOn && add_board.isMouseOver(window)) {
                    cout << "add board" << endl;
                }
                if (del_board.buttonOn && del_board.isMouseOver(window)) {
                    cout << "delete board" << endl;
                }
#else
                if (board_btn[0].buttonOn && board_btn[0].isMouseOver(window)) {
                    return current;
                }
                if (board_btn[1].buttonOn && board_btn[1].isMouseOver(window)) {
                    return current + 1;
                }
                if (board_btn[2].buttonOn && board_btn[2].isMouseOver(window)) {
                    return current + 2;
                }
                if (board_btn[3].buttonOn && board_btn[3].isMouseOver(window)) {
                    return current + 3;
                }
                if (board_btn[4].buttonOn && board_btn[4].isMouseOver(window)) {
                    return current + 4;
                }
                if (board_btn[5].buttonOn && board_btn[5].isMouseOver(window)) {
                    return current + 5;
                }
                if (board_btn[6].buttonOn && board_btn[6].isMouseOver(window)) {
                    return current + 6;
                }
                if (board_btn[7].buttonOn && board_btn[7].isMouseOver(window)) {
                    return current + 7;
                }
                if (back.isMouseOver(window)) {
                    return -1;
                }
                if (logout.isMouseOver(window)) {
                    return -2;
                }
                if (prev.isMouseOver(window)) {
                    cout << "Prev" << endl;
                    if (current > 0) current -= 8;
                    for (int i = 0; i < 8; i++) {
                        if (i + current < board_amount) {
                            board_btn[i].buttonOn = true;
                            board_btn[i].setText(boards[i + current].board_name);
                        }
                        else if (i + current >= board_amount) {
                            board_btn[i].buttonOn = false;
                            board_btn[i].setText("");
                        }
                    }
                }
                if (next.isMouseOver(window)) {
                    cout << "Next " << endl;
                    if (current + 8 < board_amount) current += 8;
                    for (int i = 0; i < 8; i++) {
                        if (i + current < board_amount) {
                            board_btn[i].buttonOn = true;
                            board_btn[i].setText(boards[i + current].board_name);
                        }
                        else if (i + current >= board_amount) {
                            board_btn[i].buttonOn = false;
                            board_btn[i].setText("");
                        }
                    }
                }
                if (add_board.buttonOn && add_board.isMouseOver(window)) {
                    return -3;
                }
                if (del_board.buttonOn && del_board.isMouseOver(window)) {
                    return -4;
                }
#endif
                break;
            }
        }

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
                if (board_btn[0].buttonOn && board_btn[0].isMouseOver(window)) {
                    board_btn[0].setBgColor(sf::Color::White);
                    board_btn[0].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[1].buttonOn && board_btn[1].isMouseOver(window)) {
                    board_btn[1].setBgColor(sf::Color::White);
                    board_btn[1].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[2].buttonOn && board_btn[2].isMouseOver(window)) {
                    board_btn[2].setBgColor(sf::Color::White);
                    board_btn[2].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[3].buttonOn && board_btn[3].isMouseOver(window)) {
                    board_btn[3].setBgColor(sf::Color::White);
                    board_btn[3].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[4].buttonOn && board_btn[4].isMouseOver(window)) {
                    board_btn[4].setBgColor(sf::Color::White);
                    board_btn[4].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[5].buttonOn && board_btn[5].isMouseOver(window)) {
                    board_btn[5].setBgColor(sf::Color::White);
                    board_btn[5].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[6].buttonOn && board_btn[6].isMouseOver(window)) {
                    board_btn[6].setBgColor(sf::Color::White);
                    board_btn[6].setTxtColor(sf::Color::Black);
                }
                else if (board_btn[7].buttonOn && board_btn[7].isMouseOver(window)) {
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
                if (board_btn[0].buttonOn && board_btn[0].isMouseOver(window)) {
                    return current;
                }
                if (board_btn[1].buttonOn && board_btn[1].isMouseOver(window)) {
                    return current + 1;
                }
                if (board_btn[2].buttonOn && board_btn[2].isMouseOver(window)) {
                    return current + 2;
                }
                if (board_btn[3].buttonOn && board_btn[3].isMouseOver(window)) {
                    return current + 3;
                }
                if (board_btn[4].buttonOn && board_btn[4].isMouseOver(window)) {
                    return current + 4;
                }
                if (board_btn[5].buttonOn && board_btn[5].isMouseOver(window)) {
                    return current + 5;
                }
                if (board_btn[6].buttonOn && board_btn[6].isMouseOver(window)) {
                    return current + 6;
                }
                if (board_btn[7].buttonOn && board_btn[7].isMouseOver(window)) {
                    return current + 7;
                }
                if (back.isMouseOver(window)) {
                    return -1;
                }
                if (prev.isMouseOver(window)) {
                    cout << "Prev" << endl;
                    if (current > 0) current -= 8;
                    for (int i = 0; i < 8; i++) {
                        if (i + current < board_amount) {
                            board_btn[i].buttonOn = true;
                            board_btn[i].setText(boards[i + current].board_name);
                        }
                        else if (i + current >= board_amount) {
                            board_btn[i].buttonOn = false;
                            board_btn[i].setText("");
                        }
                    }
                }
                if (next.isMouseOver(window)) {
                    cout << "Next " << endl;
                    if (current + 8 < board_amount) current += 8;
                    for (int i = 0; i < 8; i++) {
                        if (i + current < board_amount) {
                            board_btn[i].buttonOn = true;
                            board_btn[i].setText(boards[i + current].board_name);
                        }
                        else if (i + current >= board_amount) {
                            board_btn[i].buttonOn = false;
                            board_btn[i].setText("");
                        }
                    }
                }
                break;
            }
        }

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

    sf::Text title;
    title.setFont(font);
    title.setFillColor(sf::Color::Red);
    title.setCharacterSize(50);
    title.setString(cur_board.board_name);
    title.setPosition({ 40, 30 });

    //boards
    int current = 0;
    int post_amount = cur_board.all_Post.size();
    //bool btnOn[8] = { true, true, true, true, true, true, true, true };
    vector<Button>post_btn;
    for (int i = 0; i < 8; i++) {
        if (i < post_amount) {
            Button btn(cur_board.all_Post[i].title[0], { 660, 50 }, 30, sf::Color::Black, sf::Color::White);
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

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseMoved:
                if (post_btn[0].buttonOn && post_btn[0].isMouseOver(window)) {
                    post_btn[0].setBgColor(sf::Color::White);
                    post_btn[0].setTxtColor(sf::Color::Black);
                }
                else if (post_btn[1].buttonOn && post_btn[1].isMouseOver(window)) {
                    post_btn[1].setBgColor(sf::Color::White);
                    post_btn[1].setTxtColor(sf::Color::Black);
                }
                else if (post_btn[2].buttonOn && post_btn[2].isMouseOver(window)) {
                    post_btn[2].setBgColor(sf::Color::White);
                    post_btn[2].setTxtColor(sf::Color::Black);
                }
                else if (post_btn[3].buttonOn && post_btn[3].isMouseOver(window)) {
                    post_btn[3].setBgColor(sf::Color::White);
                    post_btn[3].setTxtColor(sf::Color::Black);
                }
                else if (post_btn[4].buttonOn && post_btn[4].isMouseOver(window)) {
                    post_btn[4].setBgColor(sf::Color::White);
                    post_btn[4].setTxtColor(sf::Color::Black);
                }
                else if (post_btn[5].buttonOn && post_btn[5].isMouseOver(window)) {
                    post_btn[5].setBgColor(sf::Color::White);
                    post_btn[5].setTxtColor(sf::Color::Black);
                }
                else if (post_btn[6].buttonOn && post_btn[6].isMouseOver(window)) {
                    post_btn[6].setBgColor(sf::Color::White);
                    post_btn[6].setTxtColor(sf::Color::Black);
                }
                else if (post_btn[7].buttonOn && post_btn[7].isMouseOver(window)) {
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
                }
                break;
            case sf::Event::MouseButtonPressed:
#if DEBUG
                if (post_btn[0].buttonOn && post_btn[0].isMouseOver(window)) {
                    cout << "Post " << cur_board.post_id[current] << endl;
                }
                if (post_btn[1].buttonOn && post_btn[1].isMouseOver(window)) {
                    cout << "Post " << cur_board.post_id[current + 1] << endl;
                }
                if (post_btn[2].buttonOn && post_btn[2].isMouseOver(window)) {
                    cout << "Post " << cur_board.post_id[current + 2] << endl;
                }
                if (post_btn[3].buttonOn && post_btn[3].isMouseOver(window)) {
                    cout << "Post " << cur_board.post_id[current + 3] << endl;
                }
                if (post_btn[4].buttonOn && post_btn[4].isMouseOver(window)) {
                    cout << "Post " << cur_board.post_id[current + 4] << endl;
                }
                if (post_btn[5].buttonOn && post_btn[5].isMouseOver(window)) {
                    cout << "Post " << cur_board.post_id[current + 5] << endl;
                }
                if (post_btn[6].buttonOn && post_btn[6].isMouseOver(window)) {
                    cout << "Post " << cur_board.post_id[current + 6] << endl;
                }
                if (post_btn[7].buttonOn && post_btn[7].isMouseOver(window)) {
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
                            post_btn[i].buttonOn = true;
                            post_btn[i].setText(cur_board.all_Post[i + current].title[0]);
                        }
                        else if (i + current >= post_amount) {
                            post_btn[i].buttonOn = false;
                            post_btn[i].setText("");
                        }
                    }
                }
                if (next.isMouseOver(window)) {
                    cout << "Next " << endl;
                    if (current + 8 < post_amount) current += 8;
                    for (int i = 0; i < 8; i++) {
                        if (i + current < post_amount) {
                            post_btn[i].buttonOn = true;
                            post_btn[i].setText(cur_board.all_Post[i + current].title[0]);
                        }
                        else if (i + current >= post_amount) {
                            post_btn[i].buttonOn = false;
                            post_btn[i].setText("");
                        }
                    }
                }
#else
                if (post_btn[0].buttonOn && post_btn[0].isMouseOver(window)) {
                    return cur_board.post_id[current];
                }
                if (post_btn[1].buttonOn && post_btn[1].isMouseOver(window)) {
                    return cur_board.post_id[current + 1];
                }
                if (post_btn[2].buttonOn && post_btn[2].isMouseOver(window)) {
                    return cur_board.post_id[current + 2];
                }
                if (post_btn[3].buttonOn && post_btn[3].isMouseOver(window)) {
                    return cur_board.post_id[current + 3];
                }
                if (post_btn[4].buttonOn && post_btn[4].isMouseOver(window)) {
                    return cur_board.post_id[current + 4];
                }
                if (post_btn[5].buttonOn && post_btn[5].isMouseOver(window)) {
                    return cur_board.post_id[current + 5];
                }
                if (post_btn[6].buttonOn && post_btn[6].isMouseOver(window)) {
                    return cur_board.post_id[current + 6];
                }
                if (post_btn[7].buttonOn && post_btn[7].isMouseOver(window)) {
                    return cur_board.post_id[current + 7];
                }
                if (back.isMouseOver(window)) {
                    return -1;
                }
                if (logout.isMouseOver(window)) {
                    return -2;
                }
                if (prev.isMouseOver(window)) {
                    cout << "Prev" << endl;
                    if (current > 0) current -= 8;
                    for (int i = 0; i < 8; i++) {
                        if (i + current < post_amount) {
                            post_btn[i].buttonOn = true;
                            post_btn[i].setText(cur_board.all_Post[i + current].title[0]);
                        }
                        else if (i + current >= post_amount) {
                            post_btn[i].buttonOn = false;
                            post_btn[i].setText("");
                        }
                    }
                }
                if (next.isMouseOver(window)) {
                    cout << "Next " << endl;
                    if (current + 8 < post_amount) current += 8;
                    for (int i = 0; i < 8; i++) {
                        if (i + current < post_amount) {
                            post_btn[i].buttonOn = true;
                            post_btn[i].setText(cur_board.all_Post[i + current].title[0]);
                        }
                        else if (i + current >= post_amount) {
                            post_btn[i].buttonOn = false;
                            post_btn[i].setText("");
                        }
                    }
                }
#endif
                break;
            }
        }

        for (int i = 0; i < 8; i++) {
            post_btn[i].drawTo(window);
        }
        back.drawTo(window);
        logout.drawTo(window);
        prev.drawTo(window);
        next.drawTo(window);
        window.draw(title);
        window.display();
    }
}

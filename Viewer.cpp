#include "Viewer.h"

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

int Viewer::login(string& username, string& password)
{
    cout << "  _                _" << endl;
    cout << " | |  ___    __ _ (_) _ __" << endl;
    cout << " | | / _ \\ /  _  || ||  _ \\" << endl;
    cout << " | || (_) || (_| || || | | |" << endl;
    cout << " |_| \\___/ \\__,  ||_||_| |_|" << endl;
    cout << "           |___ /\n" << endl;
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

int Viewer::signup(string& username, string& password)
{
    cout << "       _                                " << endl;
    cout << "      (_)                               " << endl;
    cout << "  ___  _   __ _  _ __      _   _  _ __  " << endl;
    cout << " / __|| | / _` || '_ \\    | | | || '_ \\ " << endl;
    cout << " \\__ \\| || (_| || | | |   | |_| || |_) |" << endl;
    cout << " |___/|_| \\__, ||_| |_|    \\__,_|| .__/ " << endl;
    cout << "           __/ |                 | |    " << endl;
    cout << "          |___/                  |_|    \n" << endl;
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
    sf::Font font;
    font.loadFromFile("consola.ttf");
    sf::Text title;
    title.setFont(font);
    title.setFillColor(sf::Color::Red);
    title.setCharacterSize(100);
    title.setString("BBS");
    title.setPosition({ 255, 50 });

    sf::RenderWindow window(sf::VideoMode(700, 800), "Welcome!", sf::Style::Default ^ sf::Style::Resize);

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

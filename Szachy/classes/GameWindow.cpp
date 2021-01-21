#include "GameWindow.hpp"

    GameWindow::GameWindow(){
        end = new bool(false);
        win = new sf::Music();
        makingMove = new bool(false);
        players = new Player*[2];
        players[0] = nullptr;
        players[1] = nullptr;
        started = new bool(false);
        paused = new bool(false);
        turn = new int(0);
        tHelp = new sf::Text*[6];
        for(int i = 0; i < 6; i++){
                tHelp[i] = nullptr;
            }
        board = new Button**[8];
        for(int i = 0; i < 8; i++){
            board[i] = new Button*[8];
            for(int j = 0; j < 8; j++) board[i][j] = nullptr;
        }
        boardButtons = new Tile**[8];
        for(int i = 0; i < 8; i++){
            boardButtons[i] = new Tile*[8];
            for(int j = 0; j < 8; j++) boardButtons[i][j] = nullptr;
        }
        textures = new sf::Texture *[13];
        for(int i = 0; i < 13; i++) textures[i] = new sf::Texture;
        //for(int i = 0; i < 12; i++) textures[i] = nullptr;
        textes = new std::vector<sf::Text* >;
        buttons = new std::vector<Button*>;

        tileSet = new std::string();
        fontName = new std::string();
        musicSet = new std::string();
        language = new std::string;
        width = new int;
        height = new int;
        font = new sf::Font();
        music = new sf::Music();
        eff = new sf::Music();
        menu = new std::vector <Button* >;
        top = new std::vector <Button* >;
        menuT = new std::vector <sf::Text* >;
        topT = new std::vector <sf::Text* >;
        topMenu = new bool(false);
        setMenu = new bool(false);
        updateData();
        music->setLoop(true);
        music->play();
    }
    void GameWindow::updateData(){
        loadData();
        *height = *width;
        eff->openFromFile("../resources/sound/" + *musicSet + "/select.wav");
        setMusic("../resources/sound/" + *musicSet + "/bcg.wav");
        setFont("../resources/fonts/" + *fontName);
        //setTilesSet("../resources/img/" + *tileSet);
        //std::cout << *tileSet << std::endl;
        setLanguage(*language);
        win->openFromFile("../resources/sound/" + *musicSet + "/win.wav");
        loadTextures();
    }
    void GameWindow::calculateOffsetAndSize(int& x_, int& y_, int& s_){
        s_ = *width / 10;
        x_ = s_ + s_/4;
        y_ = s_ - s_/4;
    }
    void GameWindow::makeBoard(){
        sf::Text *t;
        const sf::Color *a;
        int s_x, s_y, size;
        calculateOffsetAndSize(s_x, s_y, size);
        s_x = size*13/8;
        s_y = 8.8*size;
        for(char i = 'a'; i <= 'h'; i++){
            t = new sf::Text();
            t->setString((std::string(1,i)));
            t->setFillColor(sf::Color::Black);
            t->setPosition(sf::Vector2f(s_x,s_y));
            t->setFont(*font);
            t->setCharacterSize(size*0.7);
            textes->push_back(t);
            s_x += size;
        }
        s_x = size/2;
        s_y = size*0.8;
        for(char i = '8'; i >= '1'; i--){
            t = new sf::Text();
            t->setString(std::string(1,i));
            t->setFillColor(sf::Color::Black);
            t->setPosition(sf::Vector2f(s_x,s_y));
            t->setFont(*font);
            t->setCharacterSize(size*0.7);
            textes->push_back(t);
            s_y += size;
        }
        calculateOffsetAndSize(s_x, s_y, size);
        tHelp[4] = new sf::Text();
        tHelp[4]->setString("");
        tHelp[4]->setFillColor(sf::Color::Black);
        tHelp[4]->setPosition(sf::Vector2f(s_x+size/10, s_y-size*0.6));
        tHelp[4]->setFont(*font);
        tHelp[4]->setCharacterSize(size*0.4);
        calculateOffsetAndSize(s_x, s_y, size);
        sf::Color black = sf::Color(206,200,200);
        //change to offset
        boardBg = new Button(s_x-2,s_y-2, "bg", sf::Color(73,67,67),size*8+4,size*8+4,  font, 1); 
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if((i+j)%2 == 0) a = &sf::Color::White;
                else a = &black;
                board[i][j] = new Button(s_x,s_y, "bg", *a,size,size,  font, 1); ; //Tile(););
                s_x += size;
            }
            s_y += size;
            s_x = size + size/4;
        }
    }
    void GameWindow::nextTurn(){
        ++(*turn);
    }
    void GameWindow::makeTiles(){
        //making the board
        const sf::Color *a;
        int s_x, s_y, size;
        calculateOffsetAndSize(s_x, s_y, size);
        a = &sf::Color::Black;
        s_y += 2*size;
        for(int i = 2; i < 6; i++){//blanks
            for(int j = 0; j < 8; j++){
                boardButtons[i][j] = new Tile(s_x,s_y, "blank", sf::Color::Transparent,size,size,  font, 0, i, j); ; //Tile(););
                s_x += size;
            }
            s_y += size;
            s_x = size + size/4;
        }
        calculateOffsetAndSize(s_x, s_y, size);
        s_y += size;
        //pawns
        for(int j = 0; j < 8; j++){
            boardButtons[1][j] = new Tile(s_x,s_y, "pawn", *a,size,size,  font, 1, 1, j); ; //Tile(););
            s_x += size;
        }
        calculateOffsetAndSize(s_x, s_y, size);
        s_y+=6*size;
        for(int j = 0; j < 8; j++){
            boardButtons[6][j] = new Tile(s_x,s_y, "pawn", *a,size,size,  font, 7, 6, j); ; //Tile(););
            s_x += size;
        }
        calculateOffsetAndSize(s_x, s_y, size);
        //rooks
        boardButtons[0][0] = new Tile(s_x,s_y, "rook", *a, size, size, font, 2, 0, 0);
        boardButtons[0][7] = new Tile(s_x+7*size,s_y, "rook", *a, size, size, font, 2,0,7);
        boardButtons[7][0] = new Tile(s_x,s_y+7*size, "rook", *a, size, size, font, 8,7,0);
        boardButtons[7][7] = new Tile(s_x+7*size,s_y+7*size, "rook", *a, size, size, font, 8,7,7);
        //knights
        s_x+= size;
        boardButtons[0][1] = new Tile(s_x,s_y, "knight", *a, size, size, font, 3,0,1);
        boardButtons[0][6] = new Tile(s_x+5*size,s_y, "knight", *a, size, size, font, 3,0,6);
        boardButtons[7][1] = new Tile(s_x,s_y+7*size, "knight", *a, size, size, font, 9,7,1);
        boardButtons[7][6] = new Tile(s_x+5*size,s_y+7*size, "knight", *a, size, size, font, 9,7,6);
        //bishops
        s_x+= size;
        boardButtons[0][2] = new Tile(s_x,s_y, "bishop", *a, size, size, font,4,0,2);
        boardButtons[0][5] = new Tile(s_x+3*size,s_y, "bishop", *a, size, size, font, 4,0,5);
        boardButtons[7][2] = new Tile(s_x,s_y+7*size, "bishop", *a, size, size, font, 10,7,2);
        boardButtons[7][5] = new Tile(s_x+3*size,s_y+7*size, "bishop", *a, size, size, font, 10,7,5);
        //queens
        s_x+= size;
        boardButtons[0][3] = new Tile(s_x,s_y, "queen", *a, size, size, font,5,0,3);
        boardButtons[7][3] = new Tile(s_x,s_y+7*size, "queen", *a, size, size, font, 11,7,3);
        //kings
        s_x+= size;
        boardButtons[0][4] = new Tile(s_x,s_y, "king", *a, size, size, font,6,0,4);
        boardButtons[7][4] = new Tile(s_x,s_y+7*size, "king", *a, size, size, font, 12,7,4);
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(boardButtons[i][j]->getId() == 0) continue;
                boardButtons[i][j]->setTexture(textures[boardButtons[i][j]->getId()-1]);
            }
        }
    }
    void GameWindow::drawBoard(){
        if (*setMenu || *topMenu) return;
        for(auto it = textes->begin(); it < textes->end(); it++) draw(**it);
        boardBg->set();
        draw(*boardBg);
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                board[i][j]->set();
                draw(*board[i][j]);
            }
        }
    }
    void GameWindow::updateTiles(Tile* t){
        int r = t->getX(), c = t->getY(), i = t->getId();
        i = i > 6 ? 1: 2;
        t->setOutlineThickness(3);
        t->setOutlineColor(sf::Color::Red);
        lockTiles();
        t->unlock();
        switch(t->getId() % 6){
            case 0: //king
            {
                Tile *t;
                int x = r-1, y = c-1;
                if (x >= 0 && x < 8 && y >= 0 && y < 8){
                    t  = boardButtons[x][y];
                    if( t-> getId() != 0){
                            if(i == 1){
                                if(t->getId() <= 6){
                                    t->setOutlineColor(sf::Color::Red);
                                    t->setOutlineThickness(4);
                                    t->unlock();
                                }
                            }else{
                                if(t->getId() > 6){
                                    t->setOutlineColor(sf::Color::Red);
                                    t->setOutlineThickness(4);
                                    t->unlock();
                                }
                            }
                    }else{
                        t->setOutlineColor(sf::Color::Cyan);
                        t->setOutlineThickness(2);
                        t->unlock();
                    }
                }
                x = r - 1, y = c;
                if (x >= 0 && x < 8 && y >= 0 && y < 8){
                    t  = boardButtons[x][y];
                    if( t-> getId() != 0){
                            if(i == 1){
                                if(t->getId() <= 6){
                                    t->setOutlineColor(sf::Color::Red);
                                    t->setOutlineThickness(4);
                                    t->unlock();
                                }
                            }else{
                                if(t->getId() > 6){
                                    t->setOutlineColor(sf::Color::Red);
                                    t->setOutlineThickness(4);
                                    t->unlock();
                                }
                            }
                    }else{
                        t->setOutlineColor(sf::Color::Cyan);
                        t->setOutlineThickness(2);
                        t->unlock();
                    }
                }
                x = r-1, y=c+1;
                if (x >= 0 && x < 8 && y >= 0 && y < 8){
                    t = boardButtons[x][y];
                    if( t-> getId() != 0){
                            if(i == 1){
                                if(t->getId() <= 6){
                                    t->setOutlineColor(sf::Color::Red);
                                    t->setOutlineThickness(4);
                                    t->unlock();
                                }
                            }else{
                                if(t->getId() > 6){
                                    t->setOutlineColor(sf::Color::Red);
                                    t->setOutlineThickness(4);
                                    t->unlock();
                                }
                            }
                    }else{
                        t->setOutlineColor(sf::Color::Cyan);
                        t->setOutlineThickness(2);
                        t->unlock();
                    }
                }
                x = r, y = c -1;
                if (x >= 0 && x < 8 && y >= 0 && y < 8){
                t  = boardButtons[x][y];
                    if( t-> getId() != 0){
                            if(i == 1){
                                if(t->getId() <= 6){
                                    t->setOutlineColor(sf::Color::Red);
                                    t->setOutlineThickness(4);
                                    t->unlock();
                                }
                            }else{
                                if(t->getId() > 6){
                                    t->setOutlineColor(sf::Color::Red);
                                    t->setOutlineThickness(4);
                                    t->unlock();
                                }
                            }
                    }else{
                        t->setOutlineColor(sf::Color::Cyan);
                        t->setOutlineThickness(2);
                        t->unlock();
                    }
                }
                x =r, y = c+1;
                if (x >= 0 && x < 8 && y >= 0 && y < 8){
                    t  = boardButtons[x][y];
                    if( t-> getId() != 0){
                            if(i == 1){
                                if(t->getId() <= 6){
                                    t->setOutlineColor(sf::Color::Red);
                                    t->setOutlineThickness(4);
                                    t->unlock();
                                }
                            }else{
                                if(t->getId() > 6){
                                    t->setOutlineColor(sf::Color::Red);
                                    t->setOutlineThickness(4);
                                    t->unlock();
                                }
                            }
                    }else{
                        t->setOutlineColor(sf::Color::Cyan);
                        t->setOutlineThickness(2);
                        t->unlock();
                    }
                }
                x = r+1, y = c-1;
                if (x >= 0 && x < 8 && y >= 0 && y < 8){
                    t  = boardButtons[x][y];
                    if( t-> getId() != 0){
                            if(i == 1){
                                if(t->getId() <= 6){
                                    t->setOutlineColor(sf::Color::Red);
                                    t->setOutlineThickness(4);
                                    t->unlock();
                                }
                            }else{
                                if(t->getId() > 6){
                                    t->setOutlineColor(sf::Color::Red);
                                    t->setOutlineThickness(4);
                                    t->unlock();
                                }
                            }
                    }else{
                        t->setOutlineColor(sf::Color::Cyan);
                        t->setOutlineThickness(2);
                        t->unlock();
                    }
                }
                x= r+1, y = c;
                if (x >= 0 && x < 8 && y >= 0 && y < 8){
                    t  = boardButtons[x][y];
                    if( t-> getId() != 0){
                            if(i == 1){
                                if(t->getId() <= 6){
                                    t->setOutlineColor(sf::Color::Red);
                                    t->setOutlineThickness(4);
                                    t->unlock();
                                }
                            }else{
                                if(t->getId() > 6){
                                    t->setOutlineColor(sf::Color::Red);
                                    t->setOutlineThickness(4);
                                    t->unlock();
                                }
                            }
                    }else{
                        t->setOutlineColor(sf::Color::Cyan);
                        t->setOutlineThickness(2);
                        t->unlock();
                    }
                }
                x = r +1, y = c+1;
                if (x >= 0 && x < 8 && y >= 0 && y < 8){
                    t  = boardButtons[x][y];
                    if( t-> getId() != 0){
                            if(i == 1){
                                if(t->getId() <= 6){
                                    t->setOutlineColor(sf::Color::Red);
                                    t->setOutlineThickness(4);
                                    t->unlock();
                                }
                            }else{
                                if(t->getId() > 6){
                                    t->setOutlineColor(sf::Color::Red);
                                    t->setOutlineThickness(4);
                                    t->unlock();
                                }
                            }
                    }else{
                        t->setOutlineColor(sf::Color::Cyan);
                        t->setOutlineThickness(2);
                        t->unlock();
                    }
                }
                break;
            }
            case 1:
            {
                if( i == 1 ){
                    if(t->isFirst() && r != 0){
                        if(boardButtons[r-1][c]->getId() < 6 && boardButtons[r-1][c]->getId() > 0){
                            boardButtons[r-1][c]->setOutlineColor(sf::Color::Red);
                            boardButtons[r-1][c]->setOutlineThickness(4);
                            boardButtons[r-1][c]->unlock();
                            break;
                        }
                        for(int j = 1; j < 3; j++){
                            if(boardButtons[r-j][c]->getId() > 6) break;
                            if(boardButtons[r-j][c]->getId() != 0){
                                boardButtons[r-j][c]->setOutlineColor(sf::Color::Red);
                                boardButtons[r-j][c]->setOutlineThickness(4);
                                boardButtons[r-j][c]->unlock();
                                break;
                            }
                            boardButtons[r-j][c]->setOutlineColor(sf::Color::Cyan);
                            boardButtons[r-j][c]->setOutlineThickness(2);
                            boardButtons[r-j][c]->unlock();
                        }
                    }else if (r != 0){
                        if(boardButtons[r-1][c]->getId() < 6 && boardButtons[r-1][c]->getId() > 0){
                            boardButtons[r-1][c]->setOutlineColor(sf::Color::Red);
                            boardButtons[r-1][c]->setOutlineThickness(4);
                            boardButtons[r-1][c]->unlock();
                            break;
                        }
                        if(boardButtons[r-1][c]->getId() > 6) break;
                        if(boardButtons[r-1][c]->getId() != 0){
                            boardButtons[r-1][c]->setOutlineColor(sf::Color::Red);
                            boardButtons[r-1][c]->setOutlineThickness(4);
                            boardButtons[r-1][c]->unlock();
                            break;
                        }
                        boardButtons[r-1][c]->setOutlineColor(sf::Color::Cyan);
                        boardButtons[r-1][c]->setOutlineThickness(2);
                        boardButtons[r-1][c]->unlock();
                    }
                }else{
                    if(t->isFirst() && r != 7){
                        if(boardButtons[r+1][c]->getId() > 6 ){
                            boardButtons[r+1][c]->setOutlineColor(sf::Color::Red);
                            boardButtons[r+1][c]->setOutlineThickness(4);
                            boardButtons[r+1][c]->unlock();
                            break;
                        }
                        for(int j = 1; j < 3; j++){
                            if(boardButtons[r+j][c]->getId() <= 6 && boardButtons[r+1][c]->getId() > 0) break;
                            if(boardButtons[r+j][c]->getId() != 0){
                                boardButtons[r+j][c]->setOutlineColor(sf::Color::Red);
                                boardButtons[r+j][c]->setOutlineThickness(4);
                                boardButtons[r+j][c]->unlock();
                                break;
                            }
                            boardButtons[r+j][c]->setOutlineColor(sf::Color::Cyan);
                            boardButtons[r+j][c]->setOutlineThickness(2);
                            boardButtons[r+j][c]->unlock();
                        }
                    }else if (r != 7){
                        if(boardButtons[r+1][c]->getId() > 6){
                            boardButtons[r+1][c]->setOutlineColor(sf::Color::Red);
                            boardButtons[r+1][c]->setOutlineThickness(4);
                            boardButtons[r+1][c]->unlock();
                            break;
                        }
                        if(boardButtons[r+1][c]->getId() <= 6 && boardButtons[r+1][c]->getId() > 0) break;
                        if(boardButtons[r+1][c]->getId() != 0){
                            boardButtons[r+1][c]->setOutlineColor(sf::Color::Red);
                            boardButtons[r+1][c]->setOutlineThickness(4);
                            boardButtons[r+1][c]->unlock();
                            break;
                        }
                        boardButtons[r+1][c]->setOutlineColor(sf::Color::Cyan);
                        boardButtons[r+1][c]->setOutlineThickness(2);
                        boardButtons[r+1][c]->unlock();
                    }
                }
                
                break;
            }
            case 2: // rook
            {
                Tile *t;
                for(int j = r+1; j < 8; j++){
                    t = boardButtons[j][c];
                    if( t-> getId() != 0){
                        if(i == 1){
                            if(t->getId() <= 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else{
                                break;
                            }
                        }else{
                            if(t->getId() > 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else{
                                break;
                            }
                        }
                        break;
                    }
                    t->setOutlineColor(sf::Color::Cyan);
                    t->setOutlineThickness(2);
                    t->unlock();
                }
                for(int j = r-1; j >= 0; j--){
                    t = boardButtons[j][c];
                    if( t-> getId() != 0){
                        if(i == 1){
                            if(t->getId() <= 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else{
                                break;
                            }
                        }else{
                            if(t->getId() > 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else{
                                break;
                            }
                        }
                        break;
                    }
                    t->setOutlineColor(sf::Color::Cyan);
                    t->setOutlineThickness(2);
                    t->unlock();
                }
                for(int j = c+1; j < 8; j++){
                    t = boardButtons[r][j];
                    if( t-> getId() != 0){
                        if(i == 1){
                            if(t->getId() <= 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else{
                                break;
                            }
                        }else{
                            if(t->getId() > 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else{
                                break;
                            }
                        }
                        break;
                    }
                    t->setOutlineColor(sf::Color::Cyan);
                    t->setOutlineThickness(2);
                    t->unlock();
                }               
                for(int j = c -1; j >= 0 ; j--){
                    t = boardButtons[r][j];
                    if( t-> getId() != 0){
                        if(i == 1){
                            if(t->getId() <= 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else{
                                break;
                            }
                        }else{
                            if(t->getId() > 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else{
                                break;
                            }
                        }
                        break;
                    }
                    t->setOutlineColor(sf::Color::Cyan);
                    t->setOutlineThickness(2);
                    t->unlock();
                }
                break;
            }
            case 3: //knight
            {
                Tile *t;
                if (r - 2 >= 0){
                    if(c - 1 >= 0){
                        t = boardButtons[r-2][c-1];
                        if (t->getId() == 0){
                            t->setOutlineColor(sf::Color::Cyan);
                            t->setOutlineThickness(2);
                            t->unlock();
                        }else{
                            if(i == 1 && t->getId() <= 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else if (i == 2 && t->getId() > 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }
                        }
                    }
                    if(c + 1 < 8){
                        t = boardButtons[r-2][c+1];
                        if (t->getId() == 0){
                            t->setOutlineColor(sf::Color::Cyan);
                            t->setOutlineThickness(2);
                            t->unlock();
                        }else{
                            if(i == 1 && t->getId() <= 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else if (i == 2 && t->getId() > 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }
                        }
                    }
                }
                
                if (r + 2 < 8){
                    if(c - 1 >= 0){
                        t = boardButtons[r+2][c-1];
                        if (t->getId() == 0){
                            t->setOutlineColor(sf::Color::Cyan);
                            t->setOutlineThickness(2);
                            t->unlock();
                        }else{
                            if(i == 1 && t->getId() <= 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else if (i == 2 && t->getId() > 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }
                        }
                    }
                    if(c + 1 < 8){
                        t = boardButtons[r+2][c+1];
                        if (t->getId() == 0){
                            t->setOutlineColor(sf::Color::Cyan);
                            t->setOutlineThickness(2);
                            t->unlock();
                        }else{
                            if(i == 1 && t->getId() <= 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else if (i == 2 && t->getId() > 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }
                        }
                    }
                }
                if (c - 2 >= 0){
                    if(r - 1 >= 0){
                        t = boardButtons[r-1][c-2];
                        if (t->getId() == 0){
                            t->setOutlineColor(sf::Color::Cyan);
                            t->setOutlineThickness(2);
                            t->unlock();
                        }else{
                            if(i == 1 && t->getId() <= 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else if (i == 2 && t->getId() > 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }
                        }
                    }
                    if(r + 1 < 8){
                        t = boardButtons[r+1][c-2];
                        if (t->getId() == 0){
                            t->setOutlineColor(sf::Color::Cyan);
                            t->setOutlineThickness(2);
                            t->unlock();
                        }else{
                            if(i == 1 && t->getId() <= 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else if (i == 2 && t->getId() > 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }
                        }
                    }
                }
                
                if (c + 2 < 8){
                    if(r - 1 >= 0){
                        t = boardButtons[r-1][c+2];
                        if (t->getId() == 0){
                            t->setOutlineColor(sf::Color::Cyan);
                            t->setOutlineThickness(2);
                            t->unlock();
                        }else{
                            if(i == 1 && t->getId() <= 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else if (i == 2 && t->getId() > 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }
                        }
                    }
                    if(r + 1 < 8){ 
                        t = boardButtons[r+1][c+2];
                        if (t->getId() == 0){
                            t->setOutlineColor(sf::Color::Cyan);
                            t->setOutlineThickness(2);
                            t->unlock();
                        }else{
                            if(i == 1 && t->getId() <= 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else if (i == 2 && t->getId() > 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }
                        }
                    }
                }
                break;
            }
            case 4: // bishop
            {
                Tile *t;
                int x = r - 1, y = c - 1;
                while( x >= 0 && y >= 0){
                    t = boardButtons[x][y];
                    if (t->getId() == 0){
                        t->setOutlineColor(sf::Color::Cyan);
                        t->setOutlineThickness(2);
                        t->unlock();
                    }else{
                        if(i == 1 && t->getId() <= 6){
                            t->setOutlineColor(sf::Color::Red);
                            t->setOutlineThickness(4);
                            t->unlock();
                            break;
                        }else if (i == 2 && t->getId() > 6){
                            t->setOutlineColor(sf::Color::Red);
                            t->setOutlineThickness(4);
                            t->unlock();
                            break;
                        }else break;
                    }
                    x--;
                    y--;
                }
                x = r + 1, y = c + 1;
                while( x < 8 && y < 8){
                    t = boardButtons[x][y];
                    if (t->getId() == 0){
                        t->setOutlineColor(sf::Color::Cyan);
                        t->setOutlineThickness(2);
                        t->unlock();
                    }else{
                        if(i == 1 && t->getId() <= 6){
                            t->setOutlineColor(sf::Color::Red);
                            t->setOutlineThickness(4);
                            t->unlock();
                            break;
                        }else if (i == 2 && t->getId() > 6){
                            t->setOutlineColor(sf::Color::Red);
                            t->setOutlineThickness(4);
                            t->unlock();
                            break;
                        }else break;
                    }
                    x++;
                    y++;
                }
                x = r + 1, y = c - 1;
                while( x < 8 && y >= 0){
                    t = boardButtons[x][y];
                    if (t->getId() == 0){
                        t->setOutlineColor(sf::Color::Cyan);
                        t->setOutlineThickness(2);
                        t->unlock();
                    }else{
                        if(i == 1 && t->getId() <= 6){
                            t->setOutlineColor(sf::Color::Red);
                            t->setOutlineThickness(4);
                            t->unlock();
                            break;
                        }else if (i == 2 && t->getId() > 6){
                            t->setOutlineColor(sf::Color::Red);
                            t->setOutlineThickness(4);
                            t->unlock();
                            break;
                        }else break;
                    }
                    x++;
                    y--;
                }
                x = r - 1, y = c + 1;
                while( x >= 0 && y < 8){
                    t = boardButtons[x][y];
                    if (t->getId() == 0){
                        t->setOutlineColor(sf::Color::Cyan);
                        t->setOutlineThickness(2);
                        t->unlock();
                    }else{
                        if(i == 1 && t->getId() <= 6){
                            t->setOutlineColor(sf::Color::Red);
                            t->setOutlineThickness(4);
                            t->unlock();
                            break;
                        }else if (i == 2 && t->getId() > 6){
                            t->setOutlineColor(sf::Color::Red);
                            t->setOutlineThickness(4);
                            t->unlock();
                            break;
                        }else break;
                    }
                    x--;
                    y++;
                }
                break;
            }
            case 5: //queen
            {
                Tile *t;
                for(int j = r+1; j < 8; j++){
                    t = boardButtons[j][c];
                    if( t-> getId() != 0){
                        if(i == 1){
                            if(t->getId() <= 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else{
                                break;
                            }
                        }else{
                            if(t->getId() > 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else{
                                break;
                            }
                        }
                        break;
                    }
                    t->setOutlineColor(sf::Color::Cyan);
                    t->setOutlineThickness(2);
                    t->unlock();
                }
                for(int j = r-1; j >= 0; j--){
                    t = boardButtons[j][c];
                    if( t-> getId() != 0){
                        if(i == 1){
                            if(t->getId() <= 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else{
                                break;
                            }
                        }else{
                            if(t->getId() > 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else{
                                break;
                            }
                        }
                        break;
                    }
                    t->setOutlineColor(sf::Color::Cyan);
                    t->setOutlineThickness(2);
                    t->unlock();
                }
                for(int j = c+1; j < 8; j++){
                    t = boardButtons[r][j];
                    if( t-> getId() != 0){
                        if(i == 1){
                            if(t->getId() <= 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else{
                                break;
                            }
                        }else{
                            if(t->getId() > 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else{
                                break;
                            }
                        }
                        break;
                    }
                    t->setOutlineColor(sf::Color::Cyan);
                    t->setOutlineThickness(2);
                    t->unlock();
                }               
                for(int j = c -1; j >= 0 ; j--){
                t = boardButtons[r][j];
                    if( t-> getId() != 0){
                        if(i == 1){
                            if(t->getId() <= 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else{
                                break;
                            }
                        }else{
                            if(t->getId() > 6){
                                t->setOutlineColor(sf::Color::Red);
                                t->setOutlineThickness(4);
                                t->unlock();
                            }else{
                                break;
                            }
                        }
                        break;
                    }
                    t->setOutlineColor(sf::Color::Cyan);
                    t->setOutlineThickness(2);
                    t->unlock();
            }
                int x = r - 1, y = c - 1;
                while( x >= 0 && y >= 0){
                    t = boardButtons[x][y];
                    if (t->getId() == 0){
                        t->setOutlineColor(sf::Color::Cyan);
                        t->setOutlineThickness(2);
                        t->unlock();
                    }else{
                        if(i == 1 && t->getId() <= 6){
                            t->setOutlineColor(sf::Color::Red);
                            t->setOutlineThickness(4);
                            t->unlock();
                            break;
                        }else if (i == 2 && t->getId() > 6){
                            t->setOutlineColor(sf::Color::Red);
                            t->setOutlineThickness(4);
                            t->unlock();
                            break;
                        }else break;
                    }
                    x--;
                    y--;
                }
                x = r + 1, y = c + 1;
                while( x < 8 && y < 8){
                    t = boardButtons[x][y];
                    if (t->getId() == 0){
                        t->setOutlineColor(sf::Color::Cyan);
                        t->setOutlineThickness(2);
                        t->unlock();
                    }else{
                        if(i == 1 && t->getId() <= 6){
                            t->setOutlineColor(sf::Color::Red);
                            t->setOutlineThickness(4);
                            t->unlock();
                            break;
                        }else if (i == 2 && t->getId() > 6){
                            t->setOutlineColor(sf::Color::Red);
                            t->setOutlineThickness(4);
                            t->unlock();
                            break;
                        }else break;
                    }
                    x++;
                    y++;
                }
                x = r + 1, y = c - 1;
                while( x < 8 && y >= 0){
                    t = boardButtons[x][y];
                    if (t->getId() == 0){
                        t->setOutlineColor(sf::Color::Cyan);
                        t->setOutlineThickness(2);
                        t->unlock();
                    }else{
                        if(i == 1 && t->getId() <= 6){
                            t->setOutlineColor(sf::Color::Red);
                            t->setOutlineThickness(4);
                            t->unlock();
                            break;
                        }else if (i == 2 && t->getId() > 6){
                            t->setOutlineColor(sf::Color::Red);
                            t->setOutlineThickness(4);
                            t->unlock();
                            break;
                        }else break;
                    }
                    x++;
                    y--;
                }
                x = r - 1, y = c + 1;
                while( x >= 0 && y < 8){
                    t = boardButtons[x][y];
                    if (t->getId() == 0){
                        t->setOutlineColor(sf::Color::Cyan);
                        t->setOutlineThickness(2);
                        t->unlock();
                    }else{
                        if(i == 1 && t->getId() <= 6){
                            t->setOutlineColor(sf::Color::Red);
                            t->setOutlineThickness(4);
                            t->unlock();
                            break;
                        }else if (i == 2 && t->getId() > 6){
                            t->setOutlineColor(sf::Color::Red);
                            t->setOutlineThickness(4);
                            t->unlock();
                            break;
                        }else break;
                    }
                    x--;
                    y++;
                }
                break;
            
            }
            
        }
    }

    void GameWindow::drawTiles(sf::Vector2f v_){
        //if(*makingMove) return;
        if (*setMenu || *topMenu) return;
        Tile *t;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                t = boardButtons[i][j];
                //if(t->getId() == 0) continue;
                sf::Color a = t->getOutlineColor();
                if(checkMouse(v_, t) && !t->isLocked()){
                    t->setOutlineColor(sf::Color::Red);
                    t->setOutlineThickness(2);
                }   
                t->set();
                draw(*t);
                
                t->setOutlineColor(a);
                if(!*makingMove) t->setOutlineThickness(0);
                
            }
        }
    }
    void GameWindow::start(){
        *started = true;
    } 
    void GameWindow::pause(){
        *paused = true;
        music->stop();
    }
    void GameWindow::unPause(){
        *paused = false;
        //music->play();
    }
    bool GameWindow::isRunning(){
        return *started;
    }
    bool GameWindow::isPaused(){
        return *paused;
    }

    void GameWindow::reset(){
        *language = "polski";
        *tileSet = "set_1";
        *musicSet = "set_1";
        *fontName = "Roboto/Roboto-Regular.ttf";
        saveData();
        updateData();
        std::fstream data;
        data.open("../resources/best.txt", std::ios::out);
        data.close();
    }
    void GameWindow::loadTextures(){
        //textures[0] = new sf::Texture;
        textures[0]->loadFromFile("../resources/img/"+*tileSet+"/black_pawn.png");
        //textures[6] = new sf::Texture;
        textures[6]->loadFromFile("../resources/img/"+*tileSet+"/white_pawn.png");

        //textures[1] = new sf::Texture;
        textures[1]->loadFromFile("../resources/img/"+*tileSet+"/black_rook.png");
        //textures[7] = new sf::Texture;
        textures[7]->loadFromFile("../resources/img/"+*tileSet+"/white_rook.png");

        //textures[2] = new sf::Texture;
        textures[2]->loadFromFile("../resources/img/"+*tileSet+"/black_knight.png");
        //textures[8] = new sf::Texture;
        textures[8]->loadFromFile("../resources/img/"+*tileSet+"/white_knight.png");

        //textures[3] = new sf::Texture;
        textures[3]->loadFromFile("../resources/img/"+*tileSet+"/black_bishop.png");
        //textures[9] = new sf::Texture;
        textures[9]->loadFromFile("../resources/img/"+*tileSet+"/white_bishop.png");

        //textures[4] = new sf::Texture;
        textures[4]->loadFromFile("../resources/img/"+*tileSet+"/black_queen.png");
        //textures[10] = new sf::Texture;
        textures[10]->loadFromFile("../resources/img/"+*tileSet+"/white_queen.png");

        //textures[5] = new sf::Texture;
        textures[5]->loadFromFile("../resources/img/"+*tileSet+"/black_king.png");
        //textures[11] = new sf::Texture;
        textures[11]->loadFromFile("../resources/img/"+*tileSet+"/white_king.png");
        //textures[12] = new sf::Texture;
        textures[12]->loadFromFile("../resources/img/"+*tileSet+"/trans.png");
        for(int i = 0; i < 13; i++) textures[i]->setSmooth(true);
    }
    void GameWindow::show(){
        makeBoard();
        loadTextures();
        makeButtons();
        makeTiles();
        lockTiles();
        this->create(sf::VideoMode(*width,*height), "Chess",sf::Style::Close);
    }
    void GameWindow::makeButtons(){
        //start button
        int size_x = *width * 2/3;
        int size_y = *height  / 4;
        int s_x = *width / 6;
        int s_y = *height * 5 / 8;
        Button *x = new Button(s_x, s_y, "start", sf::Color::White, size_x, size_y, font, -1);
        x->setOutlineColor(sf::Color(73,67,67));
        x->setOutlineThickness(2);
        buttons->push_back(x);
        tHelp[0] = new sf::Text();
        tHelp[0]->setString("OK");
        tHelp[0]->setFillColor(sf::Color::Black);
        tHelp[0]->setPosition(sf::Vector2f(s_x+size_x*0.3,s_y+size_y*0.05));
        tHelp[0]->setFont(*font);
        tHelp[0]->setCharacterSize(size_y*0.7);
        
        //first player name
        size_x = *width * 7/8;
        size_y = *height * 1/5;
        s_x = size_x/16;
        s_y = *height * 1 / 8;
        x = new Button(s_x, s_y, "name first", sf::Color::White, size_x, size_y, font, -2);
        x->setOutlineColor(sf::Color::Red);
        x->setOutlineThickness(2);
        buttons->push_back(x);
        tHelp[1] = new sf::Text();
        tHelp[1]->setString("_");
        tHelp[1]->setFillColor(sf::Color::Black);
        tHelp[1]->setPosition(sf::Vector2f(s_x+size_x*0.05,s_y+size_y*0.2));
        tHelp[1]->setFont(*font);
        tHelp[1]->setCharacterSize(size_y*0.4);
        //second player name
        size_x = *width * 7/8;
        size_y = *height * 1/5;
        s_x = size_x/16;
        s_y = *height * 3 / 8;
        x = new Button(s_x, s_y, "name first", sf::Color::White, size_x, size_y, font, -2);
        x->setOutlineColor(sf::Color(73,67,67));
        x->setOutlineThickness(2);
        buttons->push_back(x);
        tHelp[2] = new sf::Text();
        tHelp[2]->setString("");
        tHelp[2]->setFillColor(sf::Color::Black);
        tHelp[2]->setPosition(sf::Vector2f(s_x+size_x*0.05,s_y+size_y*0.2));
        tHelp[2]->setFont(*font);
        tHelp[2]->setCharacterSize(size_y*0.4);

        // pause start
        size_x = *width / 5;
        size_y = *height / 25;
        s_x = *width /2;
        s_y = *height / 60;
        x = new Button(s_x, s_y, "ps", sf::Color::White, size_x, size_y, font, -2);
        x->setOutlineColor(sf::Color(73,67,67));
        x->setOutlineThickness(2);
        buttons->push_back(x);
        tHelp[3] = new sf::Text();
        tHelp[3]->setString("pause");
        tHelp[3]->setFillColor(sf::Color::Black);
        tHelp[3]->setPosition(sf::Vector2f(s_x+size_x/3.5,s_y-size_y*0.2));
        tHelp[3]->setFont(*font);
        tHelp[3]->setCharacterSize(size_y);
        //settings
        x = new Button(s_x + 1.05*size_x, s_y, "setts", sf::Color::White, size_x, size_y, font, -2);
        x->setOutlineColor(sf::Color(73,67,67));
        x->setOutlineThickness(2);
        buttons->push_back(x);
        tHelp[5] = new sf::Text();
        if (*language == "english") tHelp[5]->setString("setts");
            else tHelp[5]->setString("wyglad"); 
        tHelp[5]->setFillColor(sf::Color::Black);
        tHelp[5]->setPosition(sf::Vector2f(s_x+size_x/3.7 + 1.05*size_x,s_y-size_y*0.2));
        tHelp[5]->setFont(*font);
        tHelp[5]->setCharacterSize(size_y);
    }
    bool GameWindow::checkMouse(sf::Vector2f v, Button *b){
        sf::Vector2f s = b->getPos();
        sf::Vector2f size = b->getSize();
        if(v.x >= s.x && v.y >= s.y && v.x <= s.x+size.x && v.y <= s.y + size.y) return true;
        else return false;
    }
    void GameWindow::drawButtons(sf::Vector2f v_){
        if (*setMenu){
            auto itT = menuT->begin();
            auto it = menu->begin();
            Button* a;
            sf::Color u;
            
            for(; it < menu->end() && itT < menuT->end(); it++, itT++){
                a = *it;
                u = a->getOutlineColor();
                //std::string code = (*itT)->getString();
                int id = a->getId();
                std::string s = (*itT)->getString();
                if( a->getId() > 9){
                    switch(a->getId()/10){
                        case 0:{
                            break;
                        }
                        case 1:{
                            std::string j;
                            //if(*language == "polski");
                            if(*language == s ){
                                a->setOutlineColor(sf::Color::Red);
                                a->setOutlineThickness(4);
                            }
                            break;
                        }
                        case 2:{
                            if(*tileSet ==  "set_" +  s ){
                                a->setOutlineColor(sf::Color::Red);
                                a->setOutlineThickness(4);
                            }
                            break;
                        }
                        case 3:{
                            if(*musicSet == "set_" + s ){
                                a->setOutlineColor(sf::Color::Red);
                                a->setOutlineThickness(4);
                            }
                            break;
                        }
                        case 4:{//**********
                            switch(id%10){
                                    case 0:
                                    {
                                        if(*fontName == "Audiowide/Audiowide-Regular.ttf"){
                                            a->setOutlineColor(sf::Color::Red);
                                            a->setOutlineThickness(4);
                                        }
                                        break;
                                    }
                                    case 1:
                                    {
                                        if(*fontName ==  "Open_Sans_Condensed/OpenSansCondensed-Light.ttf"){
                                            a->setOutlineColor(sf::Color::Red);
                                            a->setOutlineThickness(4);
                                        }
                                        break;
                                    }
                                    case 2:
                                    {
                                        if(*fontName ==  "Redressed/Redressed-Regular.ttf"){
                                            a->setOutlineColor(sf::Color::Red);
                                            a->setOutlineThickness(4);
                                        }
                                        break;
                                    }
                                    case 3:
                                    {
                                        if(*fontName ==  "Roboto/Roboto-Regular.ttf"){{
                                            a->setOutlineColor(sf::Color::Red);
                                            a->setOutlineThickness(4);
                                        }}
                                        break;
                                    }
                                }
                            break;
                        }
                    }
                    if(checkMouse(v_, a)) a->setOutlineColor(sf::Color::Red);
                    a->set();
                    draw(*a);
                    a->setOutlineColor(u);
                    a->setOutlineThickness(2);
                }
                draw(**itT);
                
            }
            return;
        }else if(*topMenu){
            for(auto it = top->begin(); it < top->end(); it++){
                sf::Color u = (*it)->getOutlineColor();
                if(checkMouse(v_, *it)) (*it)->setOutlineColor(sf::Color::Red);
                (*it)->set();
                draw(**it);
                (*it)->setOutlineColor(u);
                (*it)->setOutlineThickness(2);
            }
            for(auto it = topT->begin(); it < topT->end(); it++){
                
                draw(**it);
            }
            return;
        }else if(*end){
            std::string wyg = *turn % 2 ? tHelp[1]->getString() : tHelp[1]->getString();
            if (*language == "english") tHelp[4]->setString(wyg + " won");
            else tHelp[4]->setString("Wygral " + wyg); 
            Button *a;
            a = buttons->at(3);
            sf::Color t = a->getOutlineColor();
            if(checkMouse(v_, a)) a->setOutlineColor(sf::Color::Red);
            a->set();
            draw(*a);
            a->setOutlineColor(t);
            tHelp[3]->setString("TOP");
            draw(*tHelp[3]);
            a = buttons->at(4);
            t = a->getOutlineColor();
            if(checkMouse(v_, a)) a->setOutlineColor(sf::Color::Red);
            a->set();
            draw(*a);
            a->setOutlineColor(t);
            draw(*tHelp[5]);
        }else if (!*started && !*paused){
            Button *a;
            a = buttons->at(0);
            sf::Color t = a->getOutlineColor();
            if(checkMouse(v_, a)) a->setOutlineColor(sf::Color::Red);
            a->set();
            draw(*a);
            a->setOutlineColor(t);
            draw(*tHelp[0]);
            a = buttons->at(1);
            a->set();
            draw(*a);
            draw(*tHelp[1]);
            a = buttons->at(2);
            a->set();
            draw(*a);
            draw(*tHelp[2]);
            
        }else
        if (*paused){
            if (*language == "english") tHelp[4]->setString("Paused");
            else tHelp[4]->setString("Pauza");
            Button *a;
            a = buttons->at(3);
            sf::Color t = a->getOutlineColor();
            if(checkMouse(v_, a)) a->setOutlineColor(sf::Color::Red);
            a->set();
            draw(*a);
            a->setOutlineColor(t);
            draw(*tHelp[3]);
            
        }else
        if (*started && !*paused){
            std::string t;
            if (*language == "english")  t = "'s turn";
            else t = " robi ruch";
            if(*turn % 2 == 0) tHelp[4]->setString(tHelp[1]->getString()+t);
            else tHelp[4]->setString(tHelp[2]->getString()+t);
            if (*language == "english") tHelp[3]->setString("pause");
            else tHelp[3]->setString("pauza");
            Button *a;
            a = buttons->at(3);
            sf::Color c = a->getOutlineColor();
            if(checkMouse(v_, a)) a->setOutlineColor(sf::Color::Red);
            a->set();
            draw(*a);
            a->setOutlineColor(c);
            draw(*tHelp[3]);
        }
        draw(*tHelp[4]);
    }
    void GameWindow::addToName(std::string s){
        if(tHelp[0]->getString() == "OK"){
            std::string t =tHelp[1]->getString();
            if(t == "_") t ="";
            else if (t == "") t ="_";
            //std::string x(1, 8);
            if(s == "\b"){
                if (t.size() > 1) t = t.substr(0, t.size()-1);
            }else t+=s;
            tHelp[1]->setString(t);
        }else{
            std::string t =tHelp[2]->getString();
            if(t == "_") t ="";
            else if (t == "") t ="_";
            //else t =" ";
            //std::string x(1, 8);
            if(s == "\b"){
                if (t.size() > 1) t = t.substr(0, t.size()-1);
            }else t+=s;
            tHelp[2]->setString(t);
        }
    }
    int GameWindow::checkPress(sf::Vector2f v){
        if( *setMenu){
            auto itT = menuT->begin();
            auto it = menu->begin();
            Button* a;
            for(; it < menu->end() && itT < menuT->end(); it++, itT++){
                a = *it;
                if(checkMouse(v, a)){
                    eff->stop();
                    eff->play();
                    int id = a->getId();
                    if(id == 200){
                        reset();
                        if(*language == "polski"){
                            (topT->at(0))->setString("Wyjdz");
                            (menuT->at(0))->setString("jezyk");
                            (menuT->at(3))->setString("piony");
                            (menuT->at(8))->setString("dzwieki");
                            (menuT->at(11))->setString("tekst");
                            (menuT->at(16))->setString("zapisz");
                            (menuT->at(17))->setString("reset");
                        }else{
                            (topT->at(0))->setString("Quit");
                            (menuT->at(0))->setString("lang");
                            (menuT->at(3))->setString("pieces");
                            (menuT->at(8))->setString("sound");
                            (menuT->at(11))->setString("font");
                            (menuT->at(16))->setString("accept");
                        }
                        eff->stop();
                        eff->play();
                    }
                    if(id == 100){
                        saveData();
                        updateData();
                        eff->stop();
                        eff->play();
                        if(*language == "polski"){
                            (topT->at(0))->setString("Wyjdz");
                            (menuT->at(0))->setString("jezyk");
                            (menuT->at(3))->setString("piony");
                            (menuT->at(8))->setString("dzwieki");
                            (menuT->at(11))->setString("tekst");
                            (menuT->at(16))->setString("zapisz");
                            (menuT->at(17))->setString("reset");
                        }else{
                            (topT->at(0))->setString("Quit");
                            (menuT->at(0))->setString("lang");
                            (menuT->at(3))->setString("pieces");
                            (menuT->at(8))->setString("sound");
                            (menuT->at(11))->setString("font");
                            (menuT->at(16))->setString("accept");
                        }
                        *setMenu = false;
                    }else{
                        if( a->getId() > 9){
                            switch(a->getId()/10){
                                case 0:{
                                    break;
                                }
                                case 1:{
                                    *language = (*itT)->getString();
                                    if(*language == "polski"){
                            (topT->at(0))->setString("Wyjdz");
                            (menuT->at(0))->setString("jezyk");
                            (menuT->at(3))->setString("piony");
                            (menuT->at(8))->setString("dzwieki");
                            (menuT->at(11))->setString("tekst");
                            (menuT->at(16))->setString("zapisz");
                            (menuT->at(17))->setString("reset");
                        }else{
                            (topT->at(0))->setString("Quit");
                            (menuT->at(0))->setString("lang");
                            (menuT->at(3))->setString("pieces");
                            (menuT->at(8))->setString("sound");
                            (menuT->at(11))->setString("font");
                            (menuT->at(16))->setString("accept");
                        }
                                    break;
                                }
                                case 2:{
                                    *tileSet = "set_" + (*itT)->getString();
                                    break;
                                }
                                case 3:{
                                    *musicSet = "set_"+(*itT)->getString();
                                    break;
                                }
                                case 4:{//*********
                                    switch(id%10+1){
                                        case 1:
                                        {
                                            *fontName = "Audiowide/Audiowide-Regular.ttf";
                                            break;
                                        }
                                        case 2:
                                        {
                                            *fontName = "Open_Sans_Condensed/OpenSansCondensed-Light.ttf";
                                            break;
                                        }
                                        case 3:
                                        {
                                            *fontName = "Redressed/Redressed-Regular.ttf";
                                            break;
                                        }
                                        case 4:
                                        {
                                            *fontName = "Roboto/Roboto-Regular.ttf";
                                            break;
                                        }
                                    }
                                    break;
                                }
                            }
                            saveData();
                        updateData();
                        eff->stop();
                        eff->play();
                        }
                    }
                }
            }
        }
        else if(*topMenu){
            Button* a;
            
            for(auto it = top->begin(); it < top->end(); it++){
                a = *it;
                if(checkMouse(v, a)){
                    eff->stop();
                    eff->play();
                    *topMenu = false;
                    return 3;
                }
            }
        }
        else if(*end){
            //lockTiles();
            Button *a;
            a = buttons->at(3);
            //top
            if(checkMouse(v, a)){
                eff->stop();
                eff->play();
                *topMenu = true;
                return 1;
            }
            //set
            a = buttons->at(4);
            if(checkMouse(v, a)){
                eff->stop();
                eff->play();
                *setMenu = true;
                return 2;
            }

        }else if(*makingMove && !*paused){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    Tile *a;
                    a = boardButtons[i][j];
                    //int i;
                    //if(*turn %2 == 0) i = 6;
                    int p = *turn %2;
                    if(checkMouse(v, a) && !a->isLocked()){
                        *makingMove = false;
                        eff->stop();
                        eff->play();
                        if(selectedTile == a){
                            selectedTile = nullptr;
                            lockTiles();
                        }else if(p == 0){
                            if(a->getId() <= 6 && a->getId()!=0){
                                a->setTexture(textures[12]);
                                a->setFillColor(sf::Color::Transparent);
                                if (a->getId() == 6){
                                    *end = true;
                                    win->play();
                                    music->stop();
                                    updatePoints(tHelp[1]->getString());
                                    makeLeader();
                                }
                                a->setId(0);
                            }
                            players[0]->makeMove(selectedTile, a);
                            move(selectedTile, a);
                            
                            selectedTile = nullptr;
                            nextTurn();
                            lockTiles();
                        }else{
                            if(a->getId() > 6){
                                a->setTexture(textures[12]);
                                a->setFillColor(sf::Color::Transparent);
                                if (a->getId() == 12){
                                    *end = true;
                                    win->play();
                                    music->stop();
                                    updatePoints(tHelp[2]->getString());
                                    makeLeader();
                                }
                                a->setId(0);
                            }
                            players[1]->makeMove(selectedTile, a);
                            move(selectedTile, a);
                            selectedTile = nullptr;
                            nextTurn();
                            lockTiles();
                        }
                        lockTiles();
                        
                        return 0;
                    }
                }
            }
        }else if (!*started && !*paused){
            Button *a;
            a = buttons->at(0);
            if(checkMouse(v, a)){
                if((tHelp[1]->getString() == "" || tHelp[1]->getString() == "_") && tHelp[2]->getString() != "_"){
                    return 0;
                }else if(tHelp[0]->getString()=="OK" && tHelp[1]->getString() != "_"){
                    tHelp[0]->setString("START");
                    tHelp[0]->setFillColor(sf::Color::Black);
                    tHelp[0]->setPosition(sf::Vector2f((*width) / 6+ (*width) * 2/3*0.2,(*height) * 5 / 8+(*width) * 7/8*0.05));
                    tHelp[0]->setFont(*font);
                    tHelp[0]->setCharacterSize(*height * 1/5 * 7/8*0.7);
                    buttons->at(1)->setOutlineColor(sf::Color(73,67,67));
                    buttons->at(2)->setOutlineColor(sf::Color::Red);
                    tHelp[2]->setString("_");
                    eff->play();
                }else if(tHelp[2]->getString() != "_"){
                    eff->stop();
                    eff->play();
                    start();
                    //setPlayers
                    players[0] = new Player(tHelp[1]->getString());
                    players[1] = new Player(tHelp[2]->getString());
                }
            }
        }else if( *started && !*paused){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    Tile *a;
                    a = boardButtons[i][j];
                    //int i;
                    //if(*turn %2 == 0) i = 6;
                    if(checkMouse(v, a) && !a->isLocked()){
                        *makingMove = true;
                        eff->stop();
                        eff->play();
                        updateTiles(a);
                        selectedTile = a;
                        drawTiles(v);
                    }
                }
            }
            Button* a = buttons->at(3);
            if (checkMouse(v, a)){
                eff->stop();
                eff->play();
                *paused = true;
                music->stop();
                if (*language == "english") tHelp[3]->setString("play");
                else tHelp[3]->setString("graj");
                lockTiles();
            }
        }else if( *started && *paused){
            Button* a = buttons->at(3);
            if (checkMouse(v, a)){
                eff->stop();
                eff->play();
                *paused = false;
                music->play();
                lockTiles();
                tHelp[3]->setString("pause");
            }
        }
        return 0;
    }
    void GameWindow::move(Tile* t1, Tile* t2){
        int x1 = t1->getX(), x2 = t2->getX();
        int y1 = t1->getY(), y2 = t2->getY();
        Tile* temp;
        temp = boardButtons[x1][y1];
        boardButtons[x1][y1] = boardButtons[x2][y2];
        boardButtons[x2][y2] = temp;
    }
    void GameWindow::makeLeader(){
        std::fstream data;
        data.open("../resources/best.txt", std::ios::in);
        std::string name[5];
        int points[5];
        int i = 0;
       
        while(data >> name[i]){
            if(name[i] == "0"){
                name[i] = "";
                break;
            }
            data >> points[i];
            i++;
        }
        data.close();
        for(int j = i; j < 5; j++){
                    name[j] = "";
                    points[j] = 0;
                }
        for(int i = 0; i < 5; i++){
            for(int j = i+1; j < 5; j++){
                if( points[i] < points[j]){
                    std::swap(points[i], points[j]);
                    std::swap(name[i], name[j]);
                }

            }
        }
        int w = *width/ 3;
        int h = *height/5;
        Button *b = new Button(*width - w*1.1, *height - h*1.1, "Quit", sf::Color::White, w, h, font, 1);
        b->setOutlineColor(sf::Color(73,67,67));
        b->setOutlineThickness(2);
        sf::Text *t = new sf::Text();
        if(*language == "english") t->setString("Quit");
        else t->setString("Wyjdz");
        t->setFillColor(sf::Color::Black);
        t->setPosition(sf::Vector2f(*width - w*1+w/4.5,*height - h*1.1+h/4));
        t->setFont(*font);
        t->setCharacterSize(w*0.2);
        top->push_back(b);
        topT->push_back(t);

        t = new sf::Text();
        t->setString("TOP 5");
        t->setFillColor(sf::Color::Black);
        t->setPosition(sf::Vector2f(*width/12,*height/12));
        t->setFont(*font);
        t->setCharacterSize(w*0.4);
        topT->push_back(t);

        for(int i = 0; i < 5; i++){
            if(name[i] == "") break;
            t = new sf::Text();
            t->setString(std::to_string(i+1) + ". " +name[i] + " " + std::to_string(points[i]));
            t->setFillColor(sf::Color::Black);
            t->setPosition(sf::Vector2f(*width/12,*height/12 + (i+2) * *height/11));
            t->setFont(*font);
            t->setCharacterSize(w*0.3);
            topT->push_back(t);
        }


    }
    void GameWindow::updatePoints(std::string n_){
        std::fstream data;
        data.open("../resources/best.txt", std::ios::in);
        std::string name[5];
        int points[5];
        int i = 0;
        //std::string t;
        
        while(data >> name[i]){
            if(name[i] == "0"){
                name[i] = "";
                break;
            }
            data >> points[i];
            i++;
        }
        data.close();
        for(int j = i; j < 5; j++){
            name[j] = "";
            points[j] = 0;
        }
        if( i == 0){
            name[0] = n_;
            points[0] = 1;

        }else{
            bool b = false;
            int j = 0;
            while(name[j] != "" && j < 5){
                if(name[j] == n_){
                    points[j]++;
                    b = true;
                    break;
                }
                j++;
            }
            if(!b){
                name[j] = n_;
                points[j] = 1;
            }
        }
        for(int i = 0; i < 5; i++){
            for(int j = i+1; j < 5; j++){
                if( points[i] < points[j]){
                    std::swap(points[i], points[j]);
                    std::swap(name[i], name[j]);
                }

            }
        }

        data.open("../resources/best.txt", std::ios::out);
        for(int i = 0; i < 5; i++){
            data << name[i] << " " << points[i] << std::endl;
        }
        data.close();

    }
    void GameWindow::lockTiles(){
        Tile *t;
        
        if(isPaused() || *end){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    t = boardButtons[i][j];
                    if(t->getId() < 0) continue;
                    t->lock();
                }
            }
            return;
        }
        if(*makingMove){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    t = boardButtons[i][j];
                    t->lock();
                }
            }
            return;
        }
        if(*turn %2 == 0){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    t = boardButtons[i][j];
                    if(t->getId() < 0) continue;
                    else if(t->getId() <= 6) t->lock();
                    else t->unlock();
                }
            }
        }else{
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    t = boardButtons[i][j];
                    if(t->getId() < 0) continue;
                    else if(t->getId() <= 6 && t->getId() > 0) t->unlock();
                    else t->lock();
                }
            }
        }
    }
    void GameWindow::makeMenu(){
        int w = *width / 6;
        int h = w;
        int x = w/6;
        int y = h/6;
        //lang
        Button* b;
        sf::Text *t;
        b = new Button(x, y, "l", sf::Color::White, w,h, font, 1);
        b->setOutlineColor(sf::Color(73,67,67));
        b->setOutlineThickness(2);
        t = new sf::Text();
        if(*language == "english") t->setString("lang");
        else t->setString("jezyk");
        t->setFillColor(sf::Color::Black);
        t->setPosition(sf::Vector2f(x,y+h/4));
        t->setFont(*font);
        t->setCharacterSize(w*0.3);
        menuT->push_back(t);

        menu->push_back(b);

        //^text
        b = new Button(x+w+w/10, y, "polish", sf::Color::White, 2*w,h, font, 10);
        b->setOutlineColor(sf::Color(73,67,67));
        b->setOutlineThickness(2);
        t = new sf::Text();
        if(*language == "english") t->setString("polski");
        else t->setString("polski");
        t->setFillColor(sf::Color::Black);
        t->setPosition(sf::Vector2f(x+w+3*w/4,y+h/4));
        t->setFont(*font);
        t->setCharacterSize(w*0.3);
        menuT->push_back(t);
        menu->push_back(b);

        //^text
        b = new Button(x+3*w+2*w/10, y, "english", sf::Color::White, 2*w,h, font, 11);
        b->setOutlineColor(sf::Color(73,67,67));
        b->setOutlineThickness(2);
        t = new sf::Text();
        if(*language == "english") t->setString("english");
        else t->setString("english");
        t->setFillColor(sf::Color::Black);
        t->setPosition(sf::Vector2f(x+3*w+w/2+w/10,y+h/4));
        t->setFont(*font);
        t->setCharacterSize(w*0.3);
        menuT->push_back(t);
        menu->push_back(b);
        
        //^text

        //tiles
        b = new Button(x, y+h+h/12, "t", sf::Color::White, w,h, font, 2);
        b->setOutlineColor(sf::Color(73,67,67));
        b->setOutlineThickness(2);
        t = new sf::Text();
        if(*language == "english") t->setString("pieces");
        else t->setString("piony");
        t->setFillColor(sf::Color::Black);
        t->setPosition(sf::Vector2f(x,y+h+h/4));
        t->setFont(*font);
        t->setCharacterSize(w*0.3);
        menuT->push_back(t);

        menu->push_back(b);

        //^text
        b = new Button(x+w+w/10, y+h+h/12, "1", sf::Color::White, w,h, font, 20);
        b->setOutlineColor(sf::Color(73,67,67));
        b->setOutlineThickness(2);
        t = new sf::Text();
        t->setString("1");
        t->setFillColor(sf::Color::Black);
        t->setPosition(sf::Vector2f(x+w+w/2,y+h+h/4));
        t->setFont(*font);
        t->setCharacterSize(w*0.4);
        menuT->push_back(t);
        menu->push_back(b);

        //^text
        b = new Button(x+2*w+2*w/10, y+h+h/12, "2", sf::Color::White, w,h, font, 21);
        b->setOutlineColor(sf::Color(73,67,67));
        b->setOutlineThickness(2);
        t = new sf::Text();
        t->setString("2");
        t->setFillColor(sf::Color::Black);
        t->setPosition(sf::Vector2f(x+2*w+w/2+w/10,y+h+h/4));
        t->setFont(*font);
        t->setCharacterSize(w*0.4);
        menuT->push_back(t);
        menu->push_back(b);

        //^text
        b = new Button(x+3*w+3*w/10, y+h+h/12, "3", sf::Color::White, w,h, font, 22);
        b->setOutlineColor(sf::Color(73,67,67));
        b->setOutlineThickness(2);
        t = new sf::Text();
        t->setString("3");
        t->setFillColor(sf::Color::Black);
        t->setPosition(sf::Vector2f(x+3*w+w/2+2*w/10,y+h+h/4));
        t->setFont(*font);
        t->setCharacterSize(w*0.4);
        menuT->push_back(t);
        menu->push_back(b);

        //^text
        b = new Button(x+4*w+4*w/10, y+h+h/12, "4", sf::Color::White, w,h, font, 23);
        b->setOutlineColor(sf::Color(73,67,67));
        b->setOutlineThickness(2);
        t = new sf::Text();
        t->setString("4");
        t->setFillColor(sf::Color::Black);
        t->setPosition(sf::Vector2f(x+4*w+w/2+3*w/10,y+h+h/4));
        t->setFont(*font);
        t->setCharacterSize(w*0.4);
        menuT->push_back(t);
        menu->push_back(b);

        //^text
        //music
        b = new Button(x, y+2*h+2*h/12, "m", sf::Color::White, w,h, font, 3);
        b->setOutlineColor(sf::Color(73,67,67));
        b->setOutlineThickness(2);
        t = new sf::Text();
        if(*language == "english") t->setString("sounds");
        else t->setString("dzwieki");
        t->setFillColor(sf::Color::Black);
        t->setPosition(sf::Vector2f(x,y+2*h+2*h/12+h/4));
        t->setFont(*font);
        t->setCharacterSize(w*0.3);
        menuT->push_back(t);
        menu->push_back(b);

        b = new Button(x+w+w/10, y+2*h+2*h/12, "1", sf::Color::White, w,h, font, 30);
        b->setOutlineColor(sf::Color(73,67,67));
        b->setOutlineThickness(2);
        t = new sf::Text();
        t->setString("1");
        t->setFillColor(sf::Color::Black);
        t->setPosition(sf::Vector2f(x+w+w/2,y+2*h+h/12+h/4));
        t->setFont(*font);
        t->setCharacterSize(w*0.4);
        menuT->push_back(t);
        menu->push_back(b);

        //^text
        b = new Button(x+2*w+2*w/10, y+2*h+2*h/12, "2", sf::Color::White, w,h, font, 31);
        b->setOutlineColor(sf::Color(73,67,67));
        b->setOutlineThickness(2);
        t = new sf::Text();
        t->setString("2");
        t->setFillColor(sf::Color::Black);
        t->setPosition(sf::Vector2f(x+2*w+w/2+w/10,y+2*h+h/12+h/4));
        t->setFont(*font);
        t->setCharacterSize(w*0.4);
        menuT->push_back(t);
        menu->push_back(b);

        //fonts
        b = new Button(x, y+3*h+3*h/12, "f", sf::Color::White, w,h, font, 4);
        b->setOutlineColor(sf::Color(73,67,67));
        b->setOutlineThickness(2);
        t = new sf::Text();
        if(*language == "english") t->setString("font");
        else t->setString("tekst");
        t->setFillColor(sf::Color::Black);
        t->setPosition(sf::Vector2f(x,y+3*h+3*h/12 +h/4));
        t->setFont(*font);
        t->setCharacterSize(w*0.3);
        menuT->push_back(t);

        menu->push_back(b);

        //^text
        b = new Button(x+w+w/10, y+3*h+3*h/12, "1", sf::Color::White, w,h, font, 40);
        b->setOutlineColor(sf::Color(73,67,67));
        b->setOutlineThickness(2);
        t = new sf::Text();
        t->setString("1");
        t->setFillColor(sf::Color::Black);
        t->setPosition(sf::Vector2f(x+w+w/2,y+3*h+3*h/12 +h/4));
        t->setFont(*font);
        t->setCharacterSize(w*0.4);
        menuT->push_back(t);
        menu->push_back(b);

        //^text
        b = new Button(x+2*w+2*w/10, y+3*h+3*h/12, "2", sf::Color::White, w,h, font, 41);
        b->setOutlineColor(sf::Color(73,67,67));
        b->setOutlineThickness(2);
        t = new sf::Text();
        t->setString("2");
        t->setFillColor(sf::Color::Black);
        t->setPosition(sf::Vector2f(x+2*w+w/2+w/10,y+3*h+3*h/12 +h/4));
        t->setFont(*font);
        t->setCharacterSize(w*0.4);
        menuT->push_back(t);
        menu->push_back(b);

        //^text
        b = new Button(x+3*w+3*w/10, y+3*h+3*h/12, "3", sf::Color::White, w,h, font, 42);
        b->setOutlineColor(sf::Color(73,67,67));
        b->setOutlineThickness(2);
        t = new sf::Text();
        t->setString("3");
        t->setFillColor(sf::Color::Black);
        t->setPosition(sf::Vector2f(x+3*w+w/2+2*w/10,y+3*h+3*h/12 +h/4));
        t->setFont(*font);
        t->setCharacterSize(w*0.4);
        menuT->push_back(t);
        menu->push_back(b);

        //^text
        b = new Button(x+4*w+4*w/10, y+3*h+3*h/12, "4", sf::Color::White, w,h, font, 43);
        b->setOutlineColor(sf::Color(73,67,67));
        b->setOutlineThickness(2);
        t = new sf::Text();
        t->setString("4");
        t->setFillColor(sf::Color::Black);
        t->setPosition(sf::Vector2f(x+4*w+w/2+3*w/10,y+3*h+3*h/12 +h/4));
        t->setFont(*font);
        t->setCharacterSize(w*0.4);
        menuT->push_back(t);
        menu->push_back(b);

        //accept
        //^text
        b = new Button(x+w/2, y+4*h+4*h/12, "ac", sf::Color::White, w*2,h, font, 100);
        b->setOutlineColor(sf::Color(73,67,67));
        b->setOutlineThickness(2);
        t = new sf::Text();
        if(*language == "english") t->setString("accept");
        else t->setString("zapisz");
        t->setFillColor(sf::Color::Black);
        t->setPosition(sf::Vector2f(x+w/2+w/3,y+4*h+4*h/12 +h/4));
        t->setFont(*font);
        t->setCharacterSize(w*0.4);
        menuT->push_back(t);
        menu->push_back(b);

        b = new Button(x+2*w+w/2+w/10, y+4*h+4*h/12, "ac", sf::Color::White, w*2,h, font, 200);
        b->setOutlineColor(sf::Color(73,67,67));
        b->setOutlineThickness(2);
        t = new sf::Text();
        t->setString("Reset");
        t->setFillColor(sf::Color::Black);
        t->setPosition(sf::Vector2f(x+2*w+w/2+w/3+w/10,y+4*h+4*h/12 +h/4));
        t->setFont(*font);
        t->setCharacterSize(w*0.4);
        menuT->push_back(t);
        menu->push_back(b);

    }
    GameWindow::~GameWindow(){
        if(menu != nullptr){
            for(auto it = menu->begin(); it < menu->end(); it++) delete *it;
            menu->clear();
            delete menu;
            }   
        if(top != nullptr){
            for(auto it = top->begin(); it < top->end(); it++) delete *it;
            top->clear();
            delete top;
        }
        if(menuT != nullptr){
            for(auto it = menuT->begin(); it < menuT->end(); it++) delete *it;
            menuT->clear();
            delete menuT;
            }   
        if(top != nullptr){
            for(auto it = topT->begin(); it < topT->end(); it++) delete *it;
            topT->clear();
            delete topT;
        }
        if(setMenu != nullptr) delete setMenu;
        if(topMenu != nullptr) delete topMenu;
        if( win != nullptr) delete win;
        if (end != nullptr) delete end;
        if( players != nullptr){
            if (players[0] != nullptr) delete players[0];
            if (players[1] != nullptr) delete players[1];
            delete[] players;
        }
        if(turn != nullptr) delete turn;
        if(tHelp != nullptr){
            for(int i = 0; i < 6; i++){
                if(tHelp[i] != nullptr) delete tHelp[i];
            }
            delete[] tHelp;
        }
        if(started != nullptr) delete started;
        if(paused != nullptr) delete paused;
        if(board != nullptr){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    if(board[i][j] != nullptr) delete board[i][j];
                }
            }
            delete[] board;
        }
        if (boardBg != nullptr) delete boardBg;
        if(boardButtons != nullptr){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    if(boardButtons[i][j] != nullptr) delete boardButtons[i][j];
                }
            }
            delete[] boardButtons;
        }
        if(textures != nullptr){
            for(int i = 0; i < 13; i++){
                if(textures[i] != nullptr) delete textures[i];
            }
            delete[] textures;
        }
        if(makingMove != nullptr) delete makingMove;
    }
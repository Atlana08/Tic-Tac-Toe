//

//  Game.h

//  hw1

//

//  Created by Cara Drake on 10/15/19.

//  Copyright © 2019 Cara Drake. All rights reserved.

//



#ifndef Game_h

#define Game_h

#include "Person.h"

#include <iostream>

#include <string>

#include <vector>



class Game{

public:

    Game(int&, Person&,Person&);

    void print_board();

    int get_rounds();

    void update_board(std::string&, std::string&);

    void reset_board();

    bool check_win_condition(std::string&);

    std::string assign_character_position1();

    std::string assign_character_position2();

    void print_wins();

    bool check_if_winner();

private:

    bool win_tracker =false;

    Person* player1;

    Person* player2;

    int rounds=1;

    std::string symbols [3][3] = {" "," "," "," "," "," "," "," "," "};

};



#endif /* Game_h */

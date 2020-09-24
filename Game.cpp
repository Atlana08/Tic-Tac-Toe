//

//  Game.cpp

//  hw1

//

//  Created by Cara Drake on 10/17/19.

//  Copyright © 2019 Cara Drake. All rights reserved.

//



#include "Game.h"



Game::Game(int& x, Person& p1, Person& p2){

    player1 = &p1;

    player2 = &p2;

    rounds=x;

}

int Game::get_rounds(){

    return rounds;

}

void Game::print_board(){

    std::string vertical = "      |     |     \n";

    std::string horizonal = " _____|_____|_____\n";



    std:: cout<< "\n   1     2    3   \n";

    std:: cout<<vertical;

    std:: cout<<"1  "<<symbols[0][0]<<"  |  "<<symbols[0][1]<<"  |  "<<symbols[0][2]<<"  \n";

    std:: cout<<horizonal;

    std:: cout<<vertical;

    std:: cout<<"2  "<<symbols[1][0]<<"  |  "<<symbols[1][1]<<"  |  "<<symbols[1][2]<<"  \n";

    std:: cout<<horizonal;

    std:: cout<<vertical;

    std:: cout<<"3  "<<symbols[2][0]<<"  |  "<<symbols[2][1]<<"  |  "<<symbols[2][2]<<"  \n";

    std:: cout<<vertical;

}



void Game::update_board(std::string& placement, std::string& symbol){ //you need to pass by reference here!!!

    if (placement == "1 1"){

        symbols[0][0]={symbol};

    }

    if (placement == "1 2"){

        symbols[0][1]={symbol};

    }

    if (placement == "1 3"){

        symbols[0][2]={symbol};

    }

    if (placement == "2 1"){

        symbols[1][0]={symbol};

    }

    if (placement == "2 2"){

        symbols[1][1]={symbol};

    }

    if (placement == "2 3"){

        symbols[1][2]={symbol};

    }

    if (placement == "3 1"){

        symbols[2][0]={symbol};

    }

    if (placement == "3 2"){

        symbols[2][1]={symbol};

        

    }

    if (placement == "3 3"){

        symbols[2][2]={symbol};

    }

}

void Game::reset_board(){

    for(int i=0;i<3;i++){

        for(int j =0; j<3;j++){

            symbols[i][j]= " ";

        }

    }

    win_tracker = false;

}

std::string Game::assign_character_position1(){

    std::string input = "0";

    bool empty_space = false;

    std::cout<< (*player1).get_person_name()<<" ("<<(*player1).get_person_symbol()<<") Mark location: ";

    while(empty_space == false){

        std::getline(std::cin,input);

        if (input == "1 1"){

            if (symbols[0][0] == " "){

                empty_space=true;

            }

        }

        else if (input == "1 2"){

            if (symbols[0][1] == " "){

                empty_space=true;

            }

        }

        else if (input == "1 3"){

            if (symbols[0][2] == " "){

                empty_space=true;

            }

        }

        else if (input == "2 1"){

            if (symbols[1][0] == " "){

                empty_space=true;

            }

        }

        else if (input == "2 2"){

            if (symbols[1][1] == " "){

                empty_space=true;

            }

        }

        else if (input == "2 3"){

            if (symbols[1][2] == " "){

                empty_space=true;

            }

        }

        else if (input == "3 1"){

            if (symbols[2][0] == " "){

                empty_space=true;

            }

        }

        else  if (input == "3 2"){

            if (symbols[2][1] == " "){

                empty_space=true;

            }

        }

        else if (input == "3 3"){

            if (symbols[2][2] == " "){

                empty_space=true;

            }

        }

        

    }

    return input;

}

std::string Game::assign_character_position2(){

    std::string input;

    bool empty_space = false;

    std::cout<< (*player2).get_person_name()<<"("<<(*player2).get_person_symbol()<<") Mark location: ";

    while(empty_space == false){

        std::getline(std::cin,input);

        if (input == "1 1"){

            if (symbols[0][0] == " "){

                empty_space=true;

            }

        }

        else if (input == "1 2"){

            if (symbols[0][1] == " "){

                empty_space=true;

            }

        }

        else if (input == "1 3"){

            if (symbols[0][2] == " "){

                empty_space=true;

            }

        }

        else if (input == "2 1"){

            if (symbols[1][0] == " "){

                empty_space=true;

            }

        }

        else if (input == "2 2"){

            if (symbols[1][1] == " "){

                empty_space=true;

            }

        }

        else if (input == "2 3"){

            if (symbols[1][2] == " "){

                empty_space=true;

            }

        }

        else if (input == "3 1"){

            if (symbols[2][0] == " "){

                empty_space=true;

            }

        }

        else  if (input == "3 2"){

            if (symbols[2][1] == " "){

                empty_space=true;

            }

        }

        else if (input == "3 3"){

            if (symbols[2][2] == " "){

                empty_space=true;

            }

        }

    }

    return input;

}



bool Game::check_win_condition(std::string& s){

    //ROWS WIN IF

    if(symbols[0][0]== s && symbols[0][1]==s &&symbols[0][2]==s){

        win_tracker = true;

        return true;

    }

    if(symbols[1][0]== s && symbols[1][1]==s &&symbols[1][2]==s){

        win_tracker = true;

        return true;

    }

    if(symbols[2][0]== s && symbols[2][1]==s &&symbols[2][2]==s){

        win_tracker = true;

        return true;

    }

    //COLUMNS WIN IF

    if(symbols[0][0]== s && symbols[1][0]==s &&symbols[2][0]==s){

        win_tracker = true;

        return true;

    }

    if(symbols[0][1]== s && symbols[1][1]==s &&symbols[2][1]==s){

        win_tracker = true;

        return true;

    }

    if(symbols[0][2]== s && symbols[1][2]==s &&symbols[2][2]==s){

        win_tracker = true;

        return true;

    }

    //DIAGNALS WIN IF

    if(symbols[0][0]== s && symbols[1][1]==s &&symbols[2][2]==s){

        win_tracker = true;

        return true;

    }

    if(symbols[0][2]== s && symbols[1][1]==s &&symbols[2][0]==s){

        win_tracker = true;

        return true;

    }

    return false;

}

void Game::print_wins(){

    std::cout<< (*player1).get_person_name()<<" :"<<player1->get_person_score()<<std::endl;

    std::cout<< (*player2).get_person_name()<<" :"<<player2->get_person_score()<<std::endl;

}

bool Game::check_if_winner(){

    if (win_tracker == true){

        return true;

    }

    return false;

}

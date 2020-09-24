//

//  main.cpp

//  hw1

//

//  Created by Cara Drake on 10/15/19.

//  Copyright © 2019 Cara Drake. All rights reserved.

//



#include <iostream>

#include "Person.h"

#include "Game.h"



int main() {

    //strings the Users will use to imput their names

    std::string name1;

    std::string name2;

    //variable for how many rounds they want to play

    int rounds = -1;

    //pointer to switch between both players

    Person* prt;

    //User input values

    std:: cout<< "Player 1 Name = ";

    std:: getline(std::cin,name1);

    std:: cout<< "\nPlayer 2 Name = ";

    std:: getline(std::cin,name2);

    std::cout<< "\nNumber of Games = ";

    std::cin>>rounds;

    if (std::cin.fail()){

        std::cout<< "That is not an interger, please restart program and try again\n";

        

    }

    if (rounds < 0){

        std:: cout<< "That is not a viable number of rounds, the game will not be played\n";

    }

    

    

    //Assigning the classes based on the inputted variables

    std::string O = "O";

    std::string X = "X";

    Person p1(name1, O);

    Person p2(name2, X);

    

    //Assigning the game with the specfic number of rounds requested

    Game mygame(rounds,p1,p2);

    //Games played should start at 0 because it will increase the games_played each time a game is finished until it reaches the inputed value of rounds

    int games_played = 0;

    while(games_played < mygame.get_rounds()){

        //player one will always go first and the pointer will be assigned outside of the forloop

        prt = &p1;

        mygame.print_board();

        //this part will start the forloop :))

        for (int i =0; i<9;i++){

            

            /* run code that will go for player one*/

            if(prt== &p1){

                std::string placement = mygame.assign_character_position1();

                mygame.update_board(placement,O);

                mygame.print_board();

                if(mygame.check_win_condition(O) == true){

                    std::cout<< (*prt).get_person_name()<<" has won this round!\n";

                    (*prt).increase_score();

                    

                }

                prt =&p2;

            }

            else{

                std::string placement = mygame.assign_character_position2();

                mygame.update_board(placement,X);

                mygame.print_board();

                if(mygame.check_win_condition(X) == true){

                    std::cout<< (*prt).get_person_name()<<" has won this round!\n";

                    (*prt).increase_score();

                    

                    

                }

                prt = &p1;

            }

            if(mygame.check_if_winner() == true)

                break;

            

            if (i== 8){

                std::cout<<"It is a tie, no one wins!\n";

                

            }

            

        }

        std::cout<< p1.get_person_name()<<": "<<p1.get_person_score()<<std::endl;

        std::cout<< p2.get_person_name()<<": "<<p2.get_person_score()<<std::endl;

        ++games_played;

        //Removes all the player's symbols from the respective boards

        mygame.reset_board();

    }

    p1.compare_person_scores(p1, p2);

    return 0;

}


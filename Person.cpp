//

//  Person.cpp

//  hw1

//

//  Created by Cara Drake on 10/15/19.

//  Copyright © 2019 Cara Drake. All rights reserved.

//



#include "Person.h"

Person:: Person(std::string& name, std::string& X_or_O){ 

    playername=name;

    if (name == ""){

        playername = "Default Name";

    }

    symbol = X_or_O;

    score = 0;

}

void Person:: print_name(){

    std:: cout<<playername<<"and you will be playing with "<< symbol<< "'s this round." <<std::endl;

}

std::string Person::get_person_symbol(){

    return symbol;

}

std::string Person::get_person_name(){

    return playername;

}

void Person::increase_score(){

    score = score+1;

    

}

int Person::get_person_score(){

    

    return score;

}

void Person::compare_person_scores(Person& a,Person& b){

    if(a.get_person_score()> b.get_person_score()){

        std::cout<<"Congradulations "<< a.get_person_name()<<". You Win\n";

    }

    else if(a.get_person_score()< b.get_person_score()){

        std::cout<<"Congradulations "<< b.get_person_name()<<". You Win\n";

    }

    else{

        std::cout<<"It is a tie!\n";

    }

}


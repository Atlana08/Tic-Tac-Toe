//

//  Header.h

//  hw1

//

//  Created by Cara Drake on 10/15/19.

//  Copyright © 2019 Cara Drake. All rights reserved.

//



#ifndef Person_h

#define Person_h

#include <iostream>

#include <string>

#include <vector>





class Person{

public:

    Person(std::string&,std::string&);

    void print_name();

    std:: string get_person_name();

    std::string get_person_symbol();

    int get_person_score();

    void increase_score();

    void compare_person_scores(Person&, Person&);

private:

    int score;

    std::string playername = "Bill";

    std::string symbol;

};


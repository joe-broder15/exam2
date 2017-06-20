//I affirm that all code given below was written solely by me, Joe Broder, and that any help I received adhered to the rules stated for this exam.
//  Runner.h
//  exam2
//
//  Created by JoeB on 6/20/17.
//  Copyright © 2017 Bromine Software. All rights reserved.
//

#ifndef Runner_h
#define Runner_h
#include <string>
using namespace std;

class Runner
{
public:
    string get_firstname();
    string get_lastname();
    int get_pace();
    void set_firstname(string name);
    void set_lastname(string name);
    void set_pace(int newPlace);
    
private:
    string firstname;
    string lastname;
    int pace;
};

#endif /* Runner_h */

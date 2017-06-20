//I affirm that all code given below was written solely by me, Joe Broder, and that any help I received adhered to the rules stated for this exam.
//  Runner.cpp
//  exam2
//
//  Created by JoeB on 6/20/17.
//  Copyright © 2017 Bromine Software. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "Runner.h"
using namespace std;

string Runner::get_firstname()
{
    return firstname;
}

string Runner::get_lastname()
{
    return lastname;
}

int Runner::get_pace()
{
    return pace;
}

void Runner::set_firstname(string name)
{
    firstname = name;
}

void Runner::set_lastname(string name)
{
    lastname = name;
}

void Runner::set_pace(int newPace)
{
    pace = newPace;
}


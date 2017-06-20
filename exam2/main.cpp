//I affirm that all code given below was written solely by me, Joe Broder, and that any help I received adhered to the rules stated for this exam.
//  main.cpp
//  exam2
//
//  Created by JoeB on 6/20/17.
//  Copyright © 2017 Bromine Software. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Runner.h"
using namespace std;

int main() {
    
    //Read through the file initially and create a vector of runner objects
    ifstream fin;
    fin.open("registrants.txt");
    
    //Handle error
    if(fin.fail())
    {
        cout << "Failed" << endl;
        return 0;
    }
    
    //Create vectors to store runners
    vector<Runner> runVect;
    
    //search through file and create runners
    string line;
    while(getline(fin, line))
    {
        //Create runner for each line
        //Temporary runner object and array to hold parsed line pieces
        Runner tempRun;
        vector<string> lineVect;
        
        //Create int variables to serve as markers
        int firstLetter= 0;
        int lastLetter= 0;
        
        //Parse the line into its parts
        for(int i=0; i<line.length() + 1; i++)
        {
            
            if(line[i] != ' ' && line[i-1] == ' ')
            {
                firstLetter = i;
            }
            
            if(line[i] != ' ' &&  line[i+1] == ' ')
            {
                lastLetter = i + 1;
                lineVect.push_back(line.substr(firstLetter, lastLetter));
            }
            //Handles last word in
            if(i == line.length()) {
                lastLetter = i;
                lineVect.push_back(line.substr(firstLetter, lastLetter));
            }
        }
        
        //Remove non alpha characters from second item (last name)
        lineVect[1].erase(remove_if(lineVect[1].begin(), lineVect[1].end(), [](char c) { return !isalpha(c); } ), lineVect[1].end());
        
        //Modify runner object
        tempRun.set_firstname(lineVect[0]);
        tempRun.set_lastname(lineVect[1]);
        tempRun.set_pace(stoi(lineVect[2]));
        
        runVect.push_back(tempRun);
    }
    
    //sort vector with bubble sort
    for (int i = 0; i <= runVect.size(); i++) {
       
        for (int j = 0; i <= runVect.size() - i; i++) {
            
            if (runVect[j].get_pace()>runVect[j+1].get_pace()){
                Runner temp = runVect[j+1];
                runVect[j+1] = runVect[j];
                runVect[j] = temp;
            }
        }
    }
    
    //close file
    fin.close();
    
    //The following vectors will contain content for each file respectively
    vector<Runner> redVect;
    vector<Runner> lilacVect;
    vector<Runner> blueVect;
    vector<Runner> orangeVect;
    vector<Runner> greenVect;
    vector<Runner> yellowVect;
    vector<Runner> whiteVect;
    
    //sort vector to respective color vectors
    for(int i = 0; i <= runVect.size(); i++)
    {
        if(runVect[i].get_pace() >= 721 && runVect[i].get_pace() <= 1200){
            redVect.push_back(runVect[i]);
            
        }else if(runVect[i].get_pace() >= 601 && runVect[i].get_pace() <= 720){
            lilacVect.push_back(runVect[i]);
            
        }else if(runVect[i].get_pace() >= 541 && runVect[i].get_pace() <= 600){
            blueVect.push_back(runVect[i]);
            
        }else if(runVect[i].get_pace() >= 481 && runVect[i].get_pace() <= 540){
            orangeVect.push_back(runVect[i]);
            
        }else if(runVect[i].get_pace() >= 421 && runVect[i].get_pace() <= 480){
            greenVect.push_back(runVect[i]);
            
        }else if(runVect[i].get_pace() >= 361 && runVect[i].get_pace() <= 420){
            yellowVect.push_back(runVect[i]);
            
        }else if(runVect[i].get_pace() >= 0 && runVect[i].get_pace() <= 360){
            whiteVect.push_back(runVect[i]);
            
        }
    }
    
    //Write data to files
    
    //Create stream
    ofstream fout;
    
    //RED
    fout.open("red.txt");
    
    if(fout.fail())
    {
        cout << "Can't open file \n";
        return 0;
    }
        
    for(int i = 0; i <= redVect.size(); i++)
    {
        fout << redVect[i].get_firstname() << " " << redVect[i].get_lastname() << endl;
    }
        
    fout.close();
    
    //LILAC
    fout.open("lilac.txt");
    
    if(fout.fail())
    {
        cout << "Can't open file \n";
        return 0;
    }
    
    for(int i = 0; i <= lilacVect.size(); i++)
    {
        fout << lilacVect[i].get_firstname() << " " << lilacVect[i].get_lastname() << endl;
    }
    
    fout.close();
    
    //BLUE
    fout.open("blue.txt");
    
    if(fout.fail())
    {
        cout << "Can't open file \n";
        return 0;
    }
    
    for(int i = 0; i <= blueVect.size(); i++)
    {
        fout << blueVect[i].get_firstname() << " " << blueVect[i].get_lastname() << endl;
    }
    
    fout.close();
    
    //ORANGE
    fout.open("orange.txt");
    
    if(fout.fail())
    {
        cout << "Can't open file \n";
        return 0;
    }
    
    for(int i = 0; i <= orangeVect.size(); i++)
    {
        fout << orangeVect[i].get_firstname() << " " << orangeVect[i].get_lastname() << endl;
    }
    
    fout.close();
    
    //GREEN
    fout.open("green.txt");
    
    if(fout.fail())
    {
        cout << "Can't open file \n";
        return 0;
    }
    
    for(int i = 0; i <= greenVect.size(); i++)
    {
        fout << greenVect[i].get_firstname() << " " << greenVect[i].get_lastname() << endl;
    }
    
    fout.close();
    
    //YELLOW
    fout.open("yellow.txt");
    
    if(fout.fail())
    {
        cout << "Can't open file \n";
        return 0;
    }
    
    for(int i = 0; i <= yellowVect.size(); i++)
    {
        fout << yellowVect[i].get_firstname() << " " << yellowVect[i].get_lastname() << endl;
    }
    
    fout.close();
    
    //WHITE
    fout.open("white.txt");
    
    if(fout.fail())
    {
        cout << "Can't open file \n";
        return 0;
    }
    
    for(int i = 0; i <= whiteVect.size(); i++)
    {
        fout << whiteVect[i].get_firstname() << " " << whiteVect[i].get_lastname() << endl;
    }
    
    fout.close();
    
    //----------------TEST FUNCTIONS----------------
    
    //TEST RED
    fin.open("red.txt");
    
    //Handle error
    if(fin.fail())
    {
        cout << "Failed" << endl;
        return 0;
    }
    
    //Create vectors to store runners
    vector<Runner> redVectTest;
    
    //search through file and create runners
    while(getline(fin, line))
    {
        //Create runner for each line
        //Temporary runner object and array to hold parsed line pieces
        Runner tempRun;
        vector<string> lineVect;
        
        //Create int variables to serve as markers
        int firstLetter= 0;
        int lastLetter= 0;
        
        //Parse the line into its parts
        for(int i=0; i<line.length() + 1; i++)
        {
            
            if(line[i] != ' ' && line[i-1] == ' ')
            {
                firstLetter = i;
            }
            
            if(line[i] != ' ' &&  line[i+1] == ' ')
            {
                lastLetter = i + 1;
                lineVect.push_back(line.substr(firstLetter, lastLetter));
            }
            //Handles last word in
            if(i == line.length()) {
                lastLetter = i;
                lineVect.push_back(line.substr(firstLetter, lastLetter));
            }
        }
        
        //Remove non alpha characters from second item (last name)
        lineVect[1].erase(remove_if(lineVect[1].begin(), lineVect[1].end(), [](char c) { return !isalpha(c); } ), lineVect[1].end());
        
        //Modify runner object
        tempRun.set_firstname(lineVect[0]);
        tempRun.set_lastname(lineVect[1]);
        
        redVectTest.push_back(tempRun);
    }
    
    //Compare items to file content
    for(int i = 0; i < redVect.size(); i++)
    {
        if(redVect[i].get_lastname() != redVectTest[i].get_lastname() && redVectTest[i].get_firstname() != redVect[i].get_firstname())
        {
            cout << "ERROR RED" << endl;
            return 0;
        }
    }
    cout << "passed red" << endl;
    fin.close();
    
    
    //-------------TEST lilac-------------
    fin.open("lilac.txt");
    
    //Handle error
    if(fin.fail())
    {
        cout << "Failed" << endl;
        return 0;
    }
    
    //Create vectors to store runners
    vector<Runner> lilacVectTest;
    
    //search through file and create runners
    while(getline(fin, line))
    {
        //Create runner for each line
        //Temporary runner object and array to hold parsed line pieces
        Runner tempRun;
        vector<string> lineVect;
        
        //Create int variables to serve as markers
        int firstLetter= 0;
        int lastLetter= 0;
        
        //Parse the line into its parts
        for(int i=0; i<line.length() + 1; i++)
        {
            
            if(line[i] != ' ' && line[i-1] == ' ')
            {
                firstLetter = i;
            }
            
            if(line[i] != ' ' &&  line[i+1] == ' ')
            {
                lastLetter = i + 1;
                lineVect.push_back(line.substr(firstLetter, lastLetter));
            }
            //Handles last word in
            if(i == line.length()) {
                lastLetter = i;
                lineVect.push_back(line.substr(firstLetter, lastLetter));
            }
        }
        
        //Remove non alpha characters from second item (last name)
        lineVect[1].erase(remove_if(lineVect[1].begin(), lineVect[1].end(), [](char c) { return !isalpha(c); } ), lineVect[1].end());
        
        //Modify runner object
        tempRun.set_firstname(lineVect[0]);
        tempRun.set_lastname(lineVect[1]);
        
        lilacVectTest.push_back(tempRun);
    }
    
    //Compare items to file content
    for(int i = 0; i < lilacVect.size(); i++)
    {
        if(lilacVect[i].get_lastname() != lilacVectTest[i].get_lastname() && lilacVectTest[i].get_firstname() != lilacVect[i].get_firstname())
        {
            cout << "ERROR lilac" << endl;
            return 0;
        }
    }
    cout << "passed lilac" << endl;
    
    fin.close();
    
    //-------------TEST blue-------------
    fin.open("blue.txt");
    
    //Handle error
    if(fin.fail())
    {
        cout << "Failed" << endl;
        return 0;
    }
    
    //Create vectors to store runners
    vector<Runner> blueVectTest;
    
    //search through file and create runners
    while(getline(fin, line))
    {
        //Create runner for each line
        //Temporary runner object and array to hold parsed line pieces
        Runner tempRun;
        vector<string> lineVect;
        
        //Create int variables to serve as markers
        int firstLetter= 0;
        int lastLetter= 0;
        
        //Parse the line into its parts
        for(int i=0; i<line.length() + 1; i++)
        {
            
            if(line[i] != ' ' && line[i-1] == ' ')
            {
                firstLetter = i;
            }
            
            if(line[i] != ' ' &&  line[i+1] == ' ')
            {
                lastLetter = i + 1;
                lineVect.push_back(line.substr(firstLetter, lastLetter));
            }
            //Handles last word in
            if(i == line.length()) {
                lastLetter = i;
                lineVect.push_back(line.substr(firstLetter, lastLetter));
            }
        }
        
        //Remove non alpha characters from second item (last name)
        lineVect[1].erase(remove_if(lineVect[1].begin(), lineVect[1].end(), [](char c) { return !isalpha(c); } ), lineVect[1].end());
        
        //Modify runner object
        tempRun.set_firstname(lineVect[0]);
        tempRun.set_lastname(lineVect[1]);
        
        blueVectTest.push_back(tempRun);
    }
    
    //Compare items to file content
    for(int i = 0; i < blueVect.size(); i++)
    {
        if(blueVect[i].get_lastname() != blueVectTest[i].get_lastname() && blueVectTest[i].get_firstname() != blueVect[i].get_firstname())
        {
            cout << "ERROR blue" << endl;
            return 0;
        }
    }
    cout << "passed blue" << endl;
    
    fin.close();
    
    //-------------TEST orange-------------
    fin.open("orange.txt");
    
    //Handle error
    if(fin.fail())
    {
        cout << "Failed" << endl;
        return 0;
    }
    
    //Create vectors to store runners
    vector<Runner> orangeVectTest;
    
    //search through file and create runners
    while(getline(fin, line))
    {
        //Create runner for each line
        //Temporary runner object and array to hold parsed line pieces
        Runner tempRun;
        vector<string> lineVect;
        
        //Create int variables to serve as markers
        int firstLetter= 0;
        int lastLetter= 0;
        
        //Parse the line into its parts
        for(int i=0; i<line.length() + 1; i++)
        {
            
            if(line[i] != ' ' && line[i-1] == ' ')
            {
                firstLetter = i;
            }
            
            if(line[i] != ' ' &&  line[i+1] == ' ')
            {
                lastLetter = i + 1;
                lineVect.push_back(line.substr(firstLetter, lastLetter));
            }
            //Handles last word in
            if(i == line.length()) {
                lastLetter = i;
                lineVect.push_back(line.substr(firstLetter, lastLetter));
            }
        }
        
        //Remove non alpha characters from second item (last name)
        lineVect[1].erase(remove_if(lineVect[1].begin(), lineVect[1].end(), [](char c) { return !isalpha(c); } ), lineVect[1].end());
        
        //Modify runner object
        tempRun.set_firstname(lineVect[0]);
        tempRun.set_lastname(lineVect[1]);
        
        orangeVectTest.push_back(tempRun);
    }
    
    //Compare items to file content
    for(int i = 0; i < orangeVect.size(); i++)
    {
        if(orangeVect[i].get_lastname() != orangeVectTest[i].get_lastname() && orangeVectTest[i].get_firstname() != orangeVect[i].get_firstname())
        {
            cout << "ERROR orange" << endl;
            return 0;
        }
    }
    cout << "passed orange" << endl;
    
    fin.close();
    
    //-------------TEST green-------------
    fin.open("green.txt");
    
    //Handle error
    if(fin.fail())
    {
        cout << "Failed" << endl;
        return 0;
    }
    
    //Create vectors to store runners
    vector<Runner> greenVectTest;
    
    //search through file and create runners
    while(getline(fin, line))
    {
        //Create runner for each line
        //Temporary runner object and array to hold parsed line pieces
        Runner tempRun;
        vector<string> lineVect;
        
        //Create int variables to serve as markers
        int firstLetter= 0;
        int lastLetter= 0;
        
        //Parse the line into its parts
        for(int i=0; i<line.length() + 1; i++)
        {
            
            if(line[i] != ' ' && line[i-1] == ' ')
            {
                firstLetter = i;
            }
            
            if(line[i] != ' ' &&  line[i+1] == ' ')
            {
                lastLetter = i + 1;
                lineVect.push_back(line.substr(firstLetter, lastLetter));
            }
            //Handles last word in
            if(i == line.length()) {
                lastLetter = i;
                lineVect.push_back(line.substr(firstLetter, lastLetter));
            }
        }
        
        //Remove non alpha characters from second item (last name)
        lineVect[1].erase(remove_if(lineVect[1].begin(), lineVect[1].end(), [](char c) { return !isalpha(c); } ), lineVect[1].end());
        
        //Modify runner object
        tempRun.set_firstname(lineVect[0]);
        tempRun.set_lastname(lineVect[1]);
        
        greenVectTest.push_back(tempRun);
    }
    
    //Compare items to file content
    for(int i = 0; i < greenVect.size(); i++)
    {
        if(greenVect[i].get_lastname() != greenVectTest[i].get_lastname() && greenVectTest[i].get_firstname() != greenVect[i].get_firstname())
        {
            cout << "ERROR green" << endl;
            return 0;
        }
    }
    cout << "passed green" << endl;
    
    fin.close();
    
    //-------------TEST yellow-------------
    fin.open("yellow.txt");
    
    //Handle error
    if(fin.fail())
    {
        cout << "Failed" << endl;
        return 0;
    }
    
    //Create vectors to store runners
    vector<Runner> yellowVectTest;
    
    //search through file and create runners
    while(getline(fin, line))
    {
        //Create runner for each line
        //Temporary runner object and array to hold parsed line pieces
        Runner tempRun;
        vector<string> lineVect;
        
        //Create int variables to serve as markers
        int firstLetter= 0;
        int lastLetter= 0;
        
        //Parse the line into its parts
        for(int i=0; i<line.length() + 1; i++)
        {
            
            if(line[i] != ' ' && line[i-1] == ' ')
            {
                firstLetter = i;
            }
            
            if(line[i] != ' ' &&  line[i+1] == ' ')
            {
                lastLetter = i + 1;
                lineVect.push_back(line.substr(firstLetter, lastLetter));
            }
            //Handles last word in
            if(i == line.length()) {
                lastLetter = i;
                lineVect.push_back(line.substr(firstLetter, lastLetter));
            }
        }
        
        //Remove non alpha characters from second item (last name)
        lineVect[1].erase(remove_if(lineVect[1].begin(), lineVect[1].end(), [](char c) { return !isalpha(c); } ), lineVect[1].end());
        
        //Modify runner object
        tempRun.set_firstname(lineVect[0]);
        tempRun.set_lastname(lineVect[1]);
        
        yellowVectTest.push_back(tempRun);
    }
    
    //Compare items to file content
    for(int i = 0; i < yellowVect.size(); i++)
    {
        if(yellowVect[i].get_lastname() != yellowVectTest[i].get_lastname() && yellowVectTest[i].get_firstname() != yellowVect[i].get_firstname())
        {
            cout << "ERROR yellow" << endl;
            return 0;
        }
    }
    cout << "passed yellow" << endl;
    
    fin.close();
    
    //-------------TEST white-------------
    fin.open("white.txt");
    
    //Handle error
    if(fin.fail())
    {
        cout << "Failed" << endl;
        return 0;
    }
    
    //Create vectors to store runners
    vector<Runner> whiteVectTest;
    
    //search through file and create runners
    while(getline(fin, line))
    {
        //Create runner for each line
        //Temporary runner object and array to hold parsed line pieces
        Runner tempRun;
        vector<string> lineVect;
        
        //Create int variables to serve as markers
        int firstLetter= 0;
        int lastLetter= 0;
        
        //Parse the line into its parts
        for(int i=0; i<line.length() + 1; i++)
        {
            
            if(line[i] != ' ' && line[i-1] == ' ')
            {
                firstLetter = i;
            }
            
            if(line[i] != ' ' &&  line[i+1] == ' ')
            {
                lastLetter = i + 1;
                lineVect.push_back(line.substr(firstLetter, lastLetter));
            }
            //Handles last word in
            if(i == line.length()) {
                lastLetter = i;
                lineVect.push_back(line.substr(firstLetter, lastLetter));
            }
        }
        
        //Remove non alpha characters from second item (last name)
        lineVect[1].erase(remove_if(lineVect[1].begin(), lineVect[1].end(), [](char c) { return !isalpha(c); } ), lineVect[1].end());
        
        //Modify runner object
        tempRun.set_firstname(lineVect[0]);
        tempRun.set_lastname(lineVect[1]);
        
        whiteVectTest.push_back(tempRun);
    }
    
    //Compare items to file content
    for(int i = 0; i < whiteVect.size(); i++)
    {
        if(whiteVect[i].get_lastname() != whiteVectTest[i].get_lastname() && whiteVectTest[i].get_firstname() != whiteVect[i].get_firstname())
        {
            cout << "ERROR white" << endl;
            return 0;
        }
    }
    cout << "passed white" << endl;
    
    fin.close();

}

    

#pragma once
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Player
{
private:
    string firstName;
    string secondName;
    int points;
public:
    Player();
    Player(string, string, int);
    ~Player();

    void setFirstName(string);   //nu le am folosit mai putin getPoints
    void setSecondName(string);
    void setPoints(int);
    string getFirstName();
    string getSecondName();
    int getPoints();
};


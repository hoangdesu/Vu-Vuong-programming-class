In this exercise, you are required to implement a friend function of the GameCharacter class to overload the << operator. The goal of this function is to print the details of a game character: the class has two member variables that must be printed to the output stream: the name, and a list of scores over a number of runs. The details are given below.

The files included in this exercise are:

main.cpp - provided for you to use as you develop your code
GameCharacter.h - header file (read-only) for the GameCharacter class
GameCharacter.cpp - you will write your assessed C++ code in this file
Function Details

For the following function, which is declared in GameCharacter.h, write the implementation in GameCharacter.cpp:

friend std::ostream& operator<<(std::ostream& os, const GameCharacter& character);
The input parameters are:

stream: a generic output stream, where you need to print the character's name, and scores (i.e. all of the scores in the scores vector - as specifed in task.h)
character: a reference to a GameCharacter object, where you will get the details to print out.
The format for the output stream is shown in the example below. The function should return the same output stream as given to it to ensure output chaining can be performed.

Example

For the following object and member function calls:

GameCharacter knight("Knight");
knight.addScore(500);
knight.addScore(600);
knight.addScore(700);
where the vector of scores for knight is now {500, 600, 700}. Calling the following:

std::cout << knight;
Should produce the following output:

Character Name: Knight
        Scores: 500, 600, 700
A representation of the string showing special characters such as \t is as follows:

"Character Name: Knight\n\tScores: 500, 600, 700\n"
Example 2

For the following object and member function calls:

GameCharacter knight("Knight");
i.e. where the vector of scores for knight is {} (no scores added). Calling the following:

std::cout << knight;
Should produce the following output:

Character Name: Knight
        Scores: 
A representation of the string showing special characters such as \t is as follows:

"Character Name: Knight\n\tScores: \n"
Note:

All separating spaces in the formatted string are single e.g. single space between Character and Name in the string above
Be mindful of tabs, spaces, and newline characters! They are important.

#include <iostream>
#include "GameCharacter.h"

int main()
{
   /***********************************************************************
   * This code is provided as a starting point for development and testing
       * Please modify the code below as you develop your program.
   **********************************************************************/

   GameCharacter knight("Knight");

   knight.addScore(500);
   knight.addScore(600);
   knight.addScore(700);

   std::cout << knight << std::endl; 
    
   return EXIT_SUCCESS;
}




#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include <iostream>
#include <string>
#include <vector>

class GameCharacter {
public:
    GameCharacter(const std::string& name);
    void addScore(int score);
    friend std::ostream& operator<<(std::ostream& os, const GameCharacter& character);
private:
    std::string name;
    std::vector<int> scores;
};

#endif // GAMECHARACTER_H


#include "GameCharacter.h"
#include <iostream>
#include <string>
 
using namespace std;
 
GameCharacter::GameCharacter(const std::string& name)
    : name(name) {}

void GameCharacter::addScore(int score) {
    scores.push_back(score);
}
 
ostream& operator<<(ostream& os, const GameCharacter& character) {
   os << "Character Name: " << character.name << '\n' << '\t';
   
   vector<int> num;
   
   int a = character.scores.size();
   os << "Scores: ";
   
   for ( int i = 0 ; i < a; i++) {
      if ( i == a - 1) {
         os << character.scores[i];
      } else {
      os << character.scores[i] << ", ";
   }
   }
   os<< '\n';
   
   
    return os;
}
   
   
   
   
   
   

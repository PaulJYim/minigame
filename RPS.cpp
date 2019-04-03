#include "RPS.h"
#include <iostream>
#include <fstream>
using namespace std;

/**
* Default Constructer
*/

RPS::RPS(){
}
/**
 * Getters and Setters for the players
 */
void RPS::setPlayerOne(string newPlayerOne){
    players[0] = newPlayerOne;
}
void RPS::setPlayerTwo(string newPlayerTwo){
    players[1] = newPlayerTwo;
}

string RPS::getPlayerOne(){
    return players[0];
}
string RPS::getPlayerTwo(){
    return players[1];
}
/**
* set/getplayerchoice let's the player choose between rock paper and scissors
*/

void RPS::setPlayerOneChoice(){
    bool choiceLoop = false;
    while(choiceLoop == false){
        cout << players[0] << ", choose Rock (R), Paper (P), or Scissors (S)." << endl;
        cin >> playerOneChoice;
        if(playerOneChoice == "R" || playerOneChoice == "r" || playerOneChoice == "rock"){
            playerOneChoice = "Rock";
            choiceLoop = true;
        }
        else if(playerOneChoice == "P" || playerOneChoice == "p" || playerOneChoice == "paper"){
            playerOneChoice = "Paper";
            choiceLoop = true;
        }
        else if(playerOneChoice == "S" || playerOneChoice == "s" || playerOneChoice == "scissors"){
            playerOneChoice = "Scissors";
            choiceLoop = true;
        }
        else{
            cout << "Please enter one of the three choices\n";
        }
    }
}
string RPS::getPlayerOneChoice(){
    return playerOneChoice;
}

void RPS::setPlayerTwoChoice(){
    bool choiceLoop = false;
    while(choiceLoop == false){
        cout << players[1] << ", choose Rock (R), Paper (P), or Scissors (S)." << endl;
        cin >> playerTwoChoice;
        if(playerTwoChoice == "R" || playerTwoChoice == "r" || playerTwoChoice == "rock"){
            playerTwoChoice = "Rock";
            choiceLoop = true;
        }
        else if(playerTwoChoice == "P" || playerTwoChoice == "p" || playerTwoChoice == "paper"){
            playerTwoChoice = "Paper";
            choiceLoop = true;
        }
        else if(playerTwoChoice == "S" || playerTwoChoice == "s" || playerTwoChoice == "scissors"){
            playerTwoChoice = "Scissors";
            choiceLoop = true;
        }
        else{
            cout << "Please enter one of the three choices\n";
        }
    }
}
string RPS::getPlayerTwoChoice(){
    return playerTwoChoice;
}

/**
* determineWinner compares the two player choices, if they are the same it'll be a tie, otherwise the winning player will get points
*/

void RPS::determineWinner(){
    if (playerOneChoice == playerTwoChoice){
        cout << "It's a tie! No points are awarded." << endl;
        tie = true;
    }
    else{
        if (playerOneChoice == "Rock" && playerTwoChoice == "Scissors" || playerOneChoice == "Scissors" && playerTwoChoice == "Paper" || playerOneChoice == "Paper" && playerTwoChoice == "Rock"){
            cout << players[0] << " wins! ";
            winner = players[0];
        }
        else if (playerTwoChoice == "Rock" && playerOneChoice == "Scissors" || playerTwoChoice == "Scissors" && playerOneChoice == "Paper" || playerTwoChoice == "Paper" && playerOneChoice == "Rock"){
            cout << players[1] << " wins! ";
            winner = players[1];
        }
    }
}

string RPS::getWinner(){
    return winner;
}
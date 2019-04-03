
#include "GTN.h"
#include <iostream>
#include <fstream>
using namespace std;

/**
* Constructer initializes it all the tries to 0, and creates a random number
*/

GTN::GTN(){
    random = rand() % 101; 
    p1Tries = 0;
    p2Tries = 0;
    p3Tries = 0;
    p4Tries = 0;
}

/**
 * getters and setters for the player names
 */
void GTN::setPlayerOne(string newPlayerOne){
    players[0] = newPlayerOne;
}
void GTN::setPlayerTwo(string newPlayerTwo){
    players[1] = newPlayerTwo;
}
void GTN::setPlayerThree(string newPlayerThree){
    players[2] = newPlayerThree;
}
void GTN::setPlayerFour(string newPlayerFour){
    players[3] = newPlayerFour;
}

string GTN::getPlayerOne(){
    return players[0];
}
string GTN::getPlayerTwo(){
    return players[1];
}
string GTN::getPlayerThree(){
    return players[2];
}
string GTN::getPlayerFour(){
    return players[3];
}
/**
* These will be the actual game portion, where each player gets a turn to guess for the number.
*/

int GTN::p1Turn(){
    bool correct = false;
    cout << players[0] << ", what do you think the number is?" << endl;
    while(correct == false){
        cin >> p1Guess;
        if(p1Guess < 0 and p1Guess > 100){
            cout << "The number you chose is not in the range!" << endl;
        }
        else if(p1Tries > 7){
            cout << "Wow it took you more than 7 tries. You are getting mercy ruled." << endl;
            correct = true;
        }
        else if(p1Guess > random){
            cout << "You are too high. Try again!"<< endl;
            p1Tries++;
        }
        else if(p1Guess < random){
            cout << "You are too low. Try again!" << endl;
            p1Tries++;
        }
        else if(p1Guess == random){
            cout << "You guessed the right number! It took you " << p1Tries << " tries." << endl;;
            correct = true;
        }
    }
}
int GTN::getP1Tries(){
    return p1Tries;
}

int GTN::p2Turn(){
    bool correct = false;
    cout << players[1] << ", what do you think the number is?" << endl;
    while(correct == false){
        cin >> p2Guess;
        if(p2Guess < 0 and p2Guess > 100){
            cout << "The number you chose is not in the range!" << endl;
        }
        else if(p2Tries > 7){
            cout << "Wow it took you more than 7 tries. You are getting mercy ruled." << endl;
            correct = true;
        }
        else if(p2Guess > random){
            cout << "You are too high. Try again!"<< endl;
            p2Tries++;
        }
        else if(p2Guess < random){
            cout << "You are too low. Try again!" << endl;
            p2Tries++;
        }
        else if(p2Guess == random){
            cout << "You guessed the right number! It took you " << p2Tries << " tries." << endl;
            correct = true;
        }
    }
}
int GTN::getP2Tries(){
    return p2Tries;
}

int GTN::p3Turn(){
    bool correct = false;
    cout << players[2] << ", what do you think the number is?" << endl;
    while(correct == false){
        cin >> p3Guess;
        if(p3Guess < 0 and p3Guess > 100){
            cout << "The number you chose is not in the range!" << endl;
        }
        else if(p3Tries > 7){
            cout << "Wow it took you more than 7 tries. You are getting mercy ruled." << endl;
            correct = true;
        }
        else if(p3Guess > random){
            cout << "You are too high. Try again!"<< endl;
            p3Tries++;
        }
        else if(p3Guess < random){
            cout << "You are too low. Try again!" << endl;
            p3Tries++;
        }
        else if(p3Guess == random){
            cout << "You guessed the right number! It took you " << p3Tries << " tries." << endl;
            correct = true;
        }

    }
}
int GTN::getP3Tries(){
    return p3Tries;
}

int GTN::p4Turn(){
    bool correct = false;
    cout << players[3] << ", what do you think the number is?" << endl;
    while(correct == false){
        cin >> p4Guess;
        if(p4Guess < 0 and p4Guess > 100){
            cout << "The number you chose is not in the range!" << endl;
        }
        else if(p4Tries > 7){
            cout << "Wow it took you more than 7 tries. You are getting mercy ruled." << endl;
            correct = true;
        }
        else if(p4Guess > random){
            cout << "You are too high. Try again!"<< endl;
            p4Tries++;
        }
        else if(p4Guess < random){
            cout << "You are too low. Try again!" << endl;
            p4Tries++;
        }
        else if(p4Guess == random){
            cout << "You guessed the right number! It took you " << p4Tries << " tries." << endl;
            correct = true;
        }

    }
}
int GTN::getP4Tries(){
    return p4Tries;
}
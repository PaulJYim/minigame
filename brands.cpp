#include "brands.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

/**
* Constructors for carBrands class. One chooses the players that will be in the game.
*/

carBrands::carBrands(){
}
/**
*the setPlayerChoice and getPlayerChoice functions allow each player to choose a brand
*/
void carBrands::setPlayers(string p1, string p2, string p3, string p4){
    players[0] = p1;
    players[1] = p2;
    players[2] = p3;
    players[3] = p4;
}
string carBrands::getPlayers(int i){
    return players[i];
}
void carBrands::setPlayerOneChoice(){
    cout << players[0] << ", name a brand." << endl;
    cin >> playerOneChoice;
    std::transform(playerOneChoice.begin(), playerOneChoice.end(), playerOneChoice.begin(), ::tolower);
}
string carBrands::getPlayerOneChoice(){
    return playerOneChoice;
}

void carBrands::setPlayerTwoChoice(){
    cout << players[1] << ", name a brand." << endl;
    cin >> playerTwoChoice;
    std::transform(playerTwoChoice.begin(), playerTwoChoice.end(), playerTwoChoice.begin(), ::tolower);    
}
string carBrands::getPlayerTwoChoice(){
    return playerTwoChoice;
}

void carBrands::setPlayerThreeChoice(){
    cout << players[2] << ", name a brand." << endl;
    cin >> playerThreeChoice;
    std::transform(playerThreeChoice.begin(), playerThreeChoice.end(), playerThreeChoice.begin(), ::tolower);
}
string carBrands::getPlayerThreeChoice(){
    return playerThreeChoice;
}

void carBrands::setPlayerFourChoice(){
    cout << players[3] << ", name a brand." << endl;
    cin >> playerFourChoice;
    std::transform(playerFourChoice.begin(), playerFourChoice.end(), playerFourChoice.begin(), ::tolower);
}
string carBrands::getPlayerFourChoice(){
    return playerFourChoice;
}

/**
* openBrands opens the file with the list of brand names and puts them into array brands to be used in the game.
*/

void carBrands::openBrands(string filename){
    int index = 0;
    string line;
    ifstream file;
    file.open(filename);
    if (file.is_open()){
        while (getline(file, line)){
            brands[index] = line;
            index++;
        }
        cout << "Loading...\nSuccess!" << endl;
        file.close();
    }
    else{
        cout << "Loading...\nUnable to open File";
    }
}


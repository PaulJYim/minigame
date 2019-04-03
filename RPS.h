#ifndef RPS_H
#define RPS_H

using namespace std;
#include <iostream>

class RPS{
    private:
        string players[2];
        string playerOneChoice;
        string playerTwoChoice;
        string winner;
    public:
        RPS();
        bool tie = false;
        void setPlayerOne(string);
        void setPlayerTwo(string);
        string getPlayerOne();
        string getPlayerTwo();
        void setPlayerOneChoice();
        string getPlayerOneChoice();
        void setPlayerTwoChoice();
        string getPlayerTwoChoice();
        void determineWinner();
        string getWinner();
};
#endif

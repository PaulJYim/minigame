
#ifndef GTN_H
#define GTN_H

using namespace std;
#include <iostream>

class GTN{
    private:
        int random;
        string players[4];
        int p1Tries;
        int p2Tries;
        int p3Tries;
        int p4Tries;
        int p1Guess;
        int p2Guess;
        int p3Guess;
        int p4Guess;
        string winner;
        string winner2;
        string winner3;
    public:
        GTN();
        void setPlayerOne(string);
        void setPlayerTwo(string);
        void setPlayerThree(string);
        void setPlayerFour(string);
        string getPlayerOne();
        string getPlayerTwo();
        string getPlayerThree();
        string getPlayerFour();
        int p1Turn();
        int getP1Tries();
        int p2Turn();
        int getP2Tries();
        int p3Turn();
        int getP3Tries();
        int p4Turn();
        int getP4Tries();
};
#endif

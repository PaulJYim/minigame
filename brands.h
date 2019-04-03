#ifndef BRANDS_H
#define BRANDS_H

using namespace std;
#include <iostream>

class carBrands{
    private:
        string players[4];

    public:
        carBrands();
        void setPlayers(string, string, string, string);
        string getPlayers(int);
        string playerOneChoice;
        string playerTwoChoice;
        string playerThreeChoice;
        string playerFourChoice;
        string brands[50];
        void setPlayerOneChoice();
        string getPlayerOneChoice();
        void setPlayerTwoChoice();
        string getPlayerTwoChoice();
        void setPlayerThreeChoice();
        string getPlayerThreeChoice();
        void setPlayerFourChoice();
        string getPlayerFourChoice();

        void openBrands(string);
};
#endif

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;
#include <iostream>

class player{
    private:
        string name;                 
        string note;            
        string noteHistory[5];  
        string playerInfo;    
    public:
        int points;                
        player();
        player(string);
        void setName(string);     
        string getName();      
        string writeNote();   
        string getNoteHistory();
        void clearHistory();
};
#endif

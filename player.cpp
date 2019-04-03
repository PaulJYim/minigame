#include "player.h"
#include <iostream>
#include <fstream>
using namespace std;

/**
* default constructer and constructer to create a new player
*/

player::player(){

}
player::player(string newName){
    name = newName;
    points = 0;
    note = "";
    for (int index = 0; index < 5; index++){
        noteHistory[index] = "";
    }
}

/**
* setters/getters for name
*/

void player::setName(string newName){
    name = newName;
}
string player::getName(){
    return name;
}

/**
* writenote let's the user write a note to themselves, the note gets inputted into noteHistory array afterwards
* to be called upon later by the getNoteHistory function
*/

string player::writeNote(){
    string tempNote;
    cout<< "These notes are very special so it cannot contain any spaces. :D"<< endl;
    cout << "Note: ";
    cin >> tempNote;
    note = tempNote;
    if (noteHistory[0] != "" && noteHistory[1] != "" && noteHistory[2] != "" && noteHistory[3] != "" && noteHistory[4] != ""){
        for (int count = 0; count < 5; count++){
            noteHistory[count] = "";
        }
    }
    for (int index = 0; index < 5; index++){
        if (noteHistory[index] == ""){
            noteHistory[index] = note;
            index = 5;
        }
    }
    cout << note << endl;
    return note;
}

/**
* getnoteHistory allows a player to see their note history
*/

string player::getNoteHistory(){
    for(int i = 0; i < 5; i++){
        if(noteHistory[i] == ""){
            break;
        }
        else{
            cout << noteHistory[i] << endl;
    }   }
}

/**
* clearHistory allows a player to clear their note history.
*/

void player::clearHistory(){
    for (int count = 0; count < 5; count++){
        noteHistory[count] = "";
    }
}

#include "RPS.h"
#include "RPS.cpp"
#include "GTN.h"
#include "GTN.cpp"
#include "brands.h"
#include "brands.cpp"
#include "player.h"
#include "player.cpp"

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

/**
 * Sources:
 * 1.
 * I worked with Timothy to brainstorm ideas and how to implement ideas
 * 
 * 2.
 * http://www.cplusplus.com/reference/cstdlib/rand/
 * used to learn how to get a random number
 * 
 */
 
 


int main(){
/**
* The code below creates the players, allowing them to choose their name. It then returns the names they have chosen.
*/  
    string choice;
    int helpCondense = 1;
    bool loop = true;
    string playerOne;
    string playerTwo;
    string playerThree;
    string playerFour;
    cout <<"Player one, please enter your name: ";
    cin >> playerOne;
    std::transform(playerOne.begin(), playerOne.end(), playerOne.begin(), ::toupper);

    while(loop = true){
        cout << "Player two, please enter your name: ";
        cin >> playerTwo;
        std::transform(playerTwo.begin(), playerTwo.end(), playerTwo.begin(), ::toupper);
        if(playerTwo == playerOne){
            cout << "You're name cannot be the same as someone else's!\n";
        }
        else{
            break;
        }
    }
        
        while(loop = true){
        cout << "Player three, please enter your name: ";
        cin >> playerThree;
        std::transform(playerThree.begin(), playerThree.end(), playerThree.begin(), ::toupper);
        if(playerThree == playerOne || playerThree == playerTwo){
            cout << "You're name cannot be the same as someone else's!\n";
        }
        else{
            break;
        }
    }
        while(loop = true){
        cout << "Player four, please enter your name: ";
        cin >> playerFour;
        std::transform(playerFour.begin(), playerFour.end(), playerFour.begin(), ::toupper);
        if(playerFour == playerOne || playerFour == playerThree || playerFour == playerTwo){
            cout << "You're name cannot be the same as someone else's!\n"; 
        }
        else{
            break;
        }
    }
    player p1(playerOne);
    player p2(playerTwo);
    player p3(playerThree);
    player p4(playerFour);
    cout << "The players are: " << p1.getName() << ", " << p2.getName() << ", " << p3.getName() << ", and " << p4.getName() << "." <<  endl;
/**
* This will be the menu, where the player will be able to choose which game they want to play or quit
*/
    while (loop == true){
        cout << endl << "\nWhat would you like to do? Please enter 1, 2, 3, 4, 5, 6, or 7 \n1. Car Brand Knowledge\n2. Rock-Paper-Scissors\n3. Guess the Number\n4. Scores\n5. Note\n6. View all the Winners\n7. Quit\n\n";
        cin >> choice;

/**
* This will be the car brand knowledge game, the brands class will be used here.
* Players must list the car brands that they know, if they can't think of anymore they can type done to move onto the next player
* All the user inputs will be case insensitive
*/
        if(choice == "1"){
            bool Game1 = false;
            int p1Game1Points = 0;
            int p2Game1Points = 0;
            int p3Game1Points = 0;
            int p4Game1Points = 0;
            carBrands g1;
            g1.setPlayers(p1.getName(), p2.getName(), p3.getName(), p4.getName());
            cout << "Players are: " << g1.getPlayers(0) << ", " << g1.getPlayers(1) << ", " << g1.getPlayers(2) << ", and " << g1.getPlayers(3) << endl;
            g1.openBrands("brands.txt");
            cout << "Name all the car brands you know! Input 'done' when you can't think of anymore and type 'quit' to quit the game." << endl;
            while(Game1 == false){
                while(Game1 == false){
                    g1.setPlayerOneChoice();
                    for(int i = 0; i < 50; i++){
                        if (g1.getPlayerOneChoice() == g1.brands[i]){
                            cout << "Correct!" << endl;
                            p1Game1Points++;
                        }
                    }
                    if (g1.getPlayerOneChoice() == "done"){
                        cout << g1.getPlayers(0) << ", you correctly named " << p1Game1Points << " brands.\n";
                        break;
                    }
                    else if(g1.getPlayerOneChoice() == "quit"){
                        Game1 = true;
                        
                    }
                }
                while(Game1 == false){
                    g1.setPlayerTwoChoice();
                    for(int i = 0; i < 50; i++){
                        if (g1.getPlayerTwoChoice() == g1.brands[i]){
                            cout << "Correct!" << endl;
                            p2Game1Points++;
                        }
                    }
                    if (g1.getPlayerTwoChoice() == "done"){
                        cout << g1.getPlayers(1) << ", you correctly named " << p2Game1Points << " brands.\n";
                        break;
                    }
                    else if(g1.getPlayerTwoChoice() == "quit"){
                        Game1 = true;
                        break;
                    }
                }
                while(Game1 == false){
                    g1.setPlayerThreeChoice();
                    for(int i = 0; i < 50; i++){
                        if (g1.getPlayerThreeChoice() == g1.brands[i]){
                            cout << "Correct!" << endl;
                            p3Game1Points++;
                        }
                    }
                    if (g1.getPlayerThreeChoice() == "done"){
                        cout << g1.getPlayers(2) << ", you correctly named " << p3Game1Points << " brands.\n";
                        break;
                    }
                    else if(g1.getPlayerThreeChoice() == "quit"){
                        Game1 = true;
                        break;
                    }                
                }
                while(Game1 == false){
                    g1.setPlayerFourChoice();
                    for(int i = 0; i < 50; i++){
                        if (g1.getPlayerFourChoice() == g1.brands[i]){
                            cout << "Correct!" << endl;
                            p4Game1Points++;
                        }
                        else if(g1.getPlayerFourChoice() == "quit"){
                            Game1 = true;
                            break;
                    }
                    }
                    if (g1.getPlayerFourChoice() == "done"){
                        cout << g1.getPlayers(3) << ", you correctly named " << p4Game1Points << " brands." << endl;
                        break;
                    }
                }
                break;
            }   
            if(Game1 == false){
            //If one winner
                if(p1Game1Points > p2Game1Points and p1Game1Points > p3Game1Points and p1Game1Points > p4Game1Points){
                    cout << g1.getPlayers(0) << " has won this game!";
                    p1.points++;
                }
                else if(p2Game1Points > p1Game1Points and p2Game1Points > p3Game1Points and p2Game1Points > p4Game1Points){
                    cout << g1.getPlayers(1) << " has won this game!";
                    p2.points++;
                }
                else if(p3Game1Points > p1Game1Points and p3Game1Points > p2Game1Points and p3Game1Points > p4Game1Points){
                    cout << g1.getPlayers(2) << " has won this game!";
                    p3.points++;
                }      
                else if(p4Game1Points > p1Game1Points and p4Game1Points > p2Game1Points and p4Game1Points > p3Game1Points){
                    cout << g1.getPlayers(3) << " has won this game!";
                    p4.points++;
                }
                
            //Two way tie for first place       
               else if(p1Game1Points == p2Game1Points and p1Game1Points > p3Game1Points and p1Game1Points > p4Game1Points){
                    cout << g1.getPlayers(0) << " and " << g1.getPlayers(1) << " have tied! They both will earn points.";
                    p1.points++;
                    p2.points++;
                }   
                else if(p1Game1Points > p2Game1Points and p1Game1Points == p3Game1Points and p1Game1Points > p4Game1Points){
                    cout << g1.getPlayers(0) << " and " << g1.getPlayers(2) << " have tied! They both will earn points.";
                    p1.points++;
                    p3.points++;
                } 
                else if(p1Game1Points > p2Game1Points and p1Game1Points > p3Game1Points and p1Game1Points == p4Game1Points){
                    cout << g1.getPlayers(0) << " and " << g1.getPlayers(3) << " have tied! They both will earn points.";
                    p1.points++;
                    p4.points++;
                } 
                else if(p2Game1Points > p1Game1Points and p2Game1Points == p3Game1Points and p2Game1Points > p4Game1Points){
                    cout << g1.getPlayers(1) << " and " << g1.getPlayers(2) << " have tied! They both will earn points.";
                    p2.points++;
                    p3.points++;
                }
                else if(p2Game1Points > p1Game1Points and p2Game1Points > p3Game1Points and p2Game1Points == p4Game1Points){
                    cout << g1.getPlayers(1) << " and " << g1.getPlayers(3) << " have tied! They both will earn points.";
                    p2.points++;
                    p4.points++;
                } 
                
            //Three way tie for first
            //Everybody except player 4
                else if(p1Game1Points == p2Game1Points and p1Game1Points == p3Game1Points and p1Game1Points > p4Game1Points){
                    cout << g1.getPlayers(0) << " and " << g1.getPlayers(1) << " and " << g1.getPlayers(2) << " have tied! They will earn points.";
                    p1.points++;
                    p2.points++;
                    p3.points++;
                } 
                //Except player 3
                else if(p1Game1Points == p2Game1Points and p1Game1Points > p3Game1Points and p1Game1Points == p4Game1Points){
                    cout << g1.getPlayers(0) << " and " << g1.getPlayers(1) << " and " << g1.getPlayers(3) << " have tied! They will earn points.";
                    p1.points++;
                    p2.points++;
                    p4.points++;
                }
                //Except player 2
                else if(p1Game1Points > p2Game1Points and p1Game1Points == p3Game1Points and p1Game1Points == p4Game1Points){
                    cout << g1.getPlayers(0) << " and " << g1.getPlayers(2) << " and " << g1.getPlayers(3) << " have tied! They will earn points.";
                    p1.points++;
                    p4.points++;
                    p3.points++;
                }
                //Except player 1
                else if(p2Game1Points > p1Game1Points and p2Game1Points == p3Game1Points and p2Game1Points == p4Game1Points){
                    cout << g1.getPlayers(1) << " and " << g1.getPlayers(2) << " and " << g1.getPlayers(3) << " have tied! They will earn points.";
                    p4.points++;
                    p2.points++;
                    p3.points++;
                } 
                //If all tied
                else if(p1Game1Points == p2Game1Points and p1Game1Points == p3Game1Points and p1Game1Points == p4Game1Points){
                    cout << "Everbody tied! Everybody will earn points.";
                    p1.points++;
                    p2.points++;
                    p3.points++;
                    p4.points++;
                } 
            }
        }

/**
* If the user chooses rock paper scissors then they will decide between two players and play the game by inputting their choice. If it's a tie then 
* there will be no points awarded, otherwise a point will go to the winner.
*/
        else if(choice == "2"){
            string rpsPlayer1;
            string rpsPlayer2;
            bool nameLoop = false;
            RPS g2;
            cout << "Because this game is Rock Paper Scissors, it can only have two players, please decide who wants to play.\n";
            while(nameLoop == false){
                cout << "Who is player 1? " << p1.getName() << " (1), " << p2.getName() << " (2), " << p3.getName() << " (3), or " << p4.getName() << " (4)?\n";
                cin >> rpsPlayer1;
                cout << "Who is player 2? " << p1.getName() << " (1), " << p2.getName() << " (2), " << p3.getName() << " (3), or " << p4.getName() << " (4)?\n";
                cin >> rpsPlayer2;
                if(rpsPlayer1 == rpsPlayer2){
                    cout<< "You cannot play against yourself!\n";
                }
                else if(rpsPlayer1 == "1" and rpsPlayer2 == "2"){
                    g2.setPlayerOne(p1.getName());
                    g2.setPlayerTwo(p2.getName());
                    nameLoop = true;
                }
                else if(rpsPlayer1 == "2" and rpsPlayer2 == "1"){
                    g2.setPlayerOne(p2.getName());
                    g2.setPlayerTwo(p1.getName());
                    nameLoop = true;
                }
                else if(rpsPlayer1 == "1" and rpsPlayer2 == "3"){
                    g2.setPlayerOne(p1.getName());
                    g2.setPlayerTwo(p3.getName());
                    nameLoop = true;
                }            
                else if(rpsPlayer1 == "3" and rpsPlayer2 == "1"){
                    g2.setPlayerOne(p3.getName());
                    g2.setPlayerTwo(p1.getName());
                    nameLoop = true;
                }
                else if(rpsPlayer1 == "1" and rpsPlayer2 == "4"){
                    g2.setPlayerOne(p1.getName());
                    g2.setPlayerTwo(p4.getName());
                    nameLoop = true;
                }
                else if(rpsPlayer1 == "4" and rpsPlayer2 == "1"){
                    g2.setPlayerOne(p4.getName());
                    g2.setPlayerTwo(p1.getName());
                    nameLoop = true;
                }            
                else if(rpsPlayer1 == "2" and rpsPlayer2 == "3"){
                    g2.setPlayerOne(p2.getName());
                    g2.setPlayerTwo(p3.getName());
                    nameLoop = true;
                }
                else if(rpsPlayer1 == "3" and rpsPlayer2 == "2"){
                    g2.setPlayerOne(p3.getName());
                    g2.setPlayerTwo(p2.getName());
                    nameLoop = true;
                }
                else if(rpsPlayer1 == "2" and rpsPlayer2 == "4"){
                    g2.setPlayerOne(p2.getName());
                    g2.setPlayerTwo(p4.getName());
                    nameLoop = true;
                }            
                else if(rpsPlayer1 == "4" and rpsPlayer2 == "2"){
                    g2.setPlayerOne(p4.getName());
                    g2.setPlayerTwo(p2.getName());
                    nameLoop = true;
                }
                else if(rpsPlayer1 == "3" and rpsPlayer2 == "4"){
                    g2.setPlayerOne(p3.getName());
                    g2.setPlayerTwo(p4.getName());
                    nameLoop = true;
                }
                else if(rpsPlayer1 == "4" and rpsPlayer2 == "3"){
                    g2.setPlayerOne(p4.getName());
                    g2.setPlayerTwo(p3.getName());
                    nameLoop = true;
                } 
                else{
                    cout << "Please choose the players by entering their corresponding number. 1, 2, 3, or 4.\n";
                }
            }
            cout << g2.getPlayerOne() << " and " << g2.getPlayerTwo() << " are playing.\n";
            if (g2.tie == false){
                g2.setPlayerOneChoice();
                g2.setPlayerTwoChoice();
                cout << g2.getPlayerOne() << " chose " << g2.getPlayerOneChoice() << " and " << g2.getPlayerTwo() << " chose " << g2.getPlayerTwoChoice() << ".\n";
                g2.determineWinner();
                if (g2.getWinner() == p1.getName()){
                    p1.points++;
                    cout << p1.getName() <<" gets a point!";
                }
                else if (g2.getWinner() == p2.getName()){
                    p2.points++;
                    cout << p2.getName() <<" gets a point!";
                }
                else if (g2.getWinner() == p3.getName()){
                    p3.points++;
                    cout << p3.getName() <<" gets a point!";
                }
                else if (g2.getWinner() == p4.getName()){
                    p4.points++;
                    cout << p4.getName() <<" gets a point!";
                }
            }
        }
/**
* If Guess the Number is chosen, all four users will have 8 tries to guess the correct "randomly" generated number. The user with the least amount of tries will win the game
*/
        else if(choice == "3"){
            GTN g3;
            cout << "Try to guess what the random number is! ";
            g3.setPlayerOne(p1.getName());
            g3.setPlayerTwo(p2.getName());
            g3.setPlayerThree(p3.getName());
            g3.setPlayerFour(p4.getName());
            cout << "Players are: " << g3.getPlayerOne() << ", " << g3.getPlayerTwo() << ", " << g3.getPlayerThree() << ", and " << g3.getPlayerFour() << endl;
            g3.p1Turn();
            g3.p2Turn();
            g3.p3Turn();
            g3.p4Turn();
            if(helpCondense == 1){
                if(g3.getP1Tries() < g3.getP2Tries() and g3.getP1Tries() < g3.getP3Tries() and g3.getP1Tries() < g3.getP4Tries()){
                    cout << g3.getPlayerOne() << " has won this game!";
                    p1.points++;
                }
                else if(g3.getP2Tries() < g3.getP1Tries() and g3.getP2Tries() < g3.getP3Tries() and g3.getP2Tries() < g3.getP4Tries()){
                    cout << g3.getPlayerTwo() << " has won this game!";
                    p2.points++;
                }
                else if(g3.getP3Tries() < g3.getP1Tries() and g3.getP3Tries() < g3.getP2Tries() and g3.getP3Tries() < g3.getP4Tries()){
                    cout << g3.getPlayerThree() << " has won this game!";
                    p3.points++;
                }      
                else if(g3.getP4Tries() < g3.getP1Tries() and g3.getP4Tries() < g3.getP2Tries() and g3.getP4Tries() < g3.getP3Tries()){
                    cout << g3.getPlayerFour() << " has won this game!";
                    p4.points++;
                }
                
            //Two way tie for first place       
               else if(g3.getP1Tries() == g3.getP2Tries() and g3.getP1Tries() < g3.getP3Tries() and g3.getP1Tries() < g3.getP4Tries()){
                    cout << g3.getPlayerOne() << " and " << g3.getPlayerTwo() << " have tied! They both will earn points.";
                    p1.points++;
                    p2.points++;
                }   
                else if(g3.getP1Tries() < g3.getP2Tries() and g3.getP1Tries() == g3.getP3Tries() and g3.getP1Tries() < g3.getP4Tries()){
                    cout << g3.getPlayerOne() << " and " << g3.getPlayerThree() << " have tied! They both will earn points.";
                    p1.points++;
                    p3.points++;
                } 
                else if(g3.getP1Tries() < g3.getP2Tries() and g3.getP1Tries() < g3.getP3Tries() and g3.getP1Tries() == g3.getP4Tries()){
                    cout << g3.getPlayerOne() << " and " << g3.getPlayerFour() << " have tied! They both will earn points.";
                    p1.points++;
                    p4.points++;
                } 
                else if(g3.getP2Tries() < g3.getP1Tries() and g3.getP2Tries() == g3.getP3Tries() and g3.getP2Tries() < g3.getP4Tries()){
                    cout << g3.getPlayerTwo() << " and " << g3.getPlayerThree() << " have tied! They both will earn points.";
                    p2.points++;
                    p3.points++;
                }
                else if(g3.getP2Tries() < g3.getP1Tries() and g3.getP2Tries() < g3.getP3Tries() and g3.getP2Tries() == g3.getP4Tries()){
                    cout << g3.getPlayerTwo() << " and " << g3.getPlayerFour() << " have tied! They both will earn points.";
                    p2.points++;
                    p4.points++;
                } 
                
            //Three way tie for first
            //Everybody except player 4
                else if(g3.getP1Tries() == g3.getP2Tries() and g3.getP1Tries() == g3.getP3Tries() and g3.getP1Tries() < g3.getP4Tries()){
                    cout << g3.getPlayerOne() << " and " << g3.getPlayerTwo() << " and " << g3.getPlayerThree() << " have tied! They will earn points.";
                    p1.points++;
                    p2.points++;
                    p3.points++;
                } 
                //Except player 3
                else if(g3.getP1Tries() == g3.getP2Tries() and g3.getP1Tries() < g3.getP3Tries() and g3.getP1Tries() == g3.getP4Tries()){
                    cout << g3.getPlayerOne() << " and " << g3.getPlayerTwo() << " and " << g3.getPlayerFour() << " have tied! They will earn points.";
                    p1.points++;
                    p2.points++;
                    p4.points++;
                }
                //Except player 2
                else if(g3.getP1Tries() < g3.getP2Tries() and g3.getP1Tries() == g3.getP3Tries() and g3.getP1Tries() == g3.getP4Tries()){
                    cout << g3.getPlayerOne() << " and " << g3.getPlayerThree() << " and " << g3.getPlayerFour() << " have tied! They will earn points.";
                    p1.points++;
                    p4.points++;
                    p3.points++;
                }
                //Except player 1
                else if(g3.getP2Tries() < g3.getP1Tries() and g3.getP2Tries() == g3.getP3Tries() and g3.getP2Tries() == g3.getP4Tries()){
                    cout << g3.getPlayerTwo() << " and " << g3.getPlayerThree() << " and " << g3.getPlayerFour() << " have tied! They will earn points.";
                    p4.points++;
                    p2.points++;
                    p3.points++;
                } 
                //If all tied
                else if(g3.getP1Tries() == g3.getP2Tries() and g3.getP1Tries() == g3.getP3Tries() and g3.getP1Tries() == g3.getP4Tries()){
                    cout << "Everbody tied! Everybody will earn points.";
                    p1.points++;
                    p2.points++;
                    p3.points++;
                    p4.points++;
                } 
            }
        }

/**
* If scores is chosen, the scores of each player are outputted.
*/
        else if(choice == "4"){
            string tempHold;
            //int tempPoints[4];
            cout << p1.getName() << " has " << p1.points << " points.";
            cout << endl << p2.getName() << " has " << p2.points << " points.";
            cout << endl << p3.getName() << " has " << p3.points << " points.";
            cout << endl << p4.getName() << " has " << p4.points << " points." << endl;
        }
/**
* If Note is chosen, the player is able to choose from writing a new Note, getting the Note history, or clearing their Note history.
* Depending on what they choose, the chosen player is either able to write a Note, choose an index at which their Note history will be outputted, or clear the NoteHistory array.
*/
        else if(choice == "5"){
            string tempChoice;
            string writer;
            int index;
            cout << "Choose an option (1, 2, or 3):" << endl;
            cout << "1. Write Note" << endl << "2. See Note History" << endl << "3. Erase history" << endl;
            cin >> tempChoice;
            if (tempChoice == "1"){
                cout << "Who is the writer?" << endl;
                cin >> writer;
                if (writer == p1.getName()){
                    p1.writeNote();
                }
                if (writer == p2.getName()){
                    p2.writeNote();
                }
                if (writer == p3.getName()){
                    p3.writeNote();
                }
                if (writer == p4.getName()){
                    p4.writeNote();
                }
                else{
                    cout << "That is not a current player! Going back to main menu.";
                }
            }
            else if (tempChoice == "2"){
                cout << "Who's history?" << endl;
                cin >> writer;
                if (writer == p1.getName()){
                    p1.getNoteHistory();
                }
                else if (writer == p2.getName()){
                    p2.getNoteHistory();
                }
                else if (writer == p3.getName()){
                    p3.getNoteHistory();
                }
                else if (writer == p4.getName()){
                    p4.getNoteHistory();
                }
                else{
                    cout << "That is not a current player! Going back to main menu.";
                }
            }
            else if (tempChoice == "3"){
                cout << "Who's history?" << endl;
                cin >> writer;
                if (writer == p1.getName()){
                    p1.clearHistory();
                }
                else if (writer == p2.getName()){
                    p2.clearHistory();
                }
                else if (writer == p3.getName()){
                    p3.clearHistory();
                }
                else if (writer == p4.getName()){
                    p4.clearHistory();
                }
                else{
                    cout << "That is not a current player! Going back to main menu.";
                }
            }
            else{
                cout << "That is not a valid option! Going back to main menu.";
            }
        }
/**
* This will allow the user to view all the past winners by reading into a file with the list of them.
*/
        else if(choice == "6"){
    string line;
    int i = 0;
    string winners[100];
    ifstream file;
    file.open("winners.txt");
    if (file.is_open()){
        while (getline(file, line)){
            winners[i] = line;
            i++;
        }
        file.close();
        cout << "The winners are: ";
        for(int j = 0; j < i; j++){
            if(j == i-1){
                cout << winners[j] << ".";
            }
            else{
                cout << winners[j] << ", ";
            }
        }
    }
    else{
        cout << "Unable to open file";
    }
        }
        
        
/**
 * This will allow the user to quit, and once the user quits it will see who the final winner is
 * If there is only one winner, it will also add to the list of winners, so that future players can see
 * when they select option 4. If there are ties, it will only announce the winner.
 */
        else if(choice == "7" || choice == "quit" || choice == "Quit"){
            cout << "Thank you for playing! The winner will now be calculated and if there is only one winner, they will also be put onto the winners list.\n";
                string line;
                int i = 0;
                string winners[100];
                ifstream inFile;
                inFile.open("winners.txt");
                if (inFile.is_open()){
                while (getline(inFile, line)){
                    winners[i] = line;
                    i++;
                }
                inFile.close();
    }
            //If one winner
                if(p1.points > p2.points and p1.points > p3.points and p1.points > p4.points){
                    cout << p1.getName() << " has won the game!";
                    winners[i] = p1.getName();
                    int j = 0;
                    ofstream outFile;
                    outFile.open("winners.txt");
                    if (outFile.is_open()){
                        for(int j = 0; j <= i; j++){
                            outFile << winners[j] << endl;
                        }
                    }
                    outFile.close();
                }
                else if(p2.points > p1.points and p2.points > p3.points and p2.points > p4.points){
                    cout << p2.getName() << " has won the game!";
                    winners[i+1] = p2.getName();
                }
                else if(p3.points > p1.points and p3.points > p2.points and p3.points > p4.points){
                    cout << p3.getName() << " has won the game!";
                    winners[i+1] = p3.getName();
                }      
                else if(p4.points > p1.points and p4.points > p2.points and p4.points > p3.points){
                    cout << p4.getName() << " has won the game!";
                    winners[i+1] = p4.getName();
                }
                
            //Two way tie for first place       
               else if(p1.points == p2.points and p1.points > p3.points and p1.points > p4.points){
                    cout << p1.getName() << " and " << p2.getName() << " have tied for first place!";
                }   
                else if(p1.points > p2.points and p1.points == p3.points and p1.points > p4.points){
                    cout << p1.getName() << " and " << p3.getName() << " have tied for first place!";
                } 
                else if(p1.points > p2.points and p1.points > p3.points and p1.points == p4.points){
                    cout << p1.getName() << " and " << p4.getName() << " have tied for first place!";
                } 
                else if(p2.points > p1.points and p2.points == p3.points and p2.points > p4.points){
                    cout << p2.getName() << " and " << p3.getName() << " have tied for first place!";
                }
                else if(p2.points > p1.points and p2.points > p3.points and p2.points == p4.points){
                    cout << p2.getName() << " and " << p4.getName() << " have tied for first place!";
                } 
                
            //Three way tie for first
            //Everybody except player 4
                else if(p1.points == p2.points and p1.points == p3.points and p1.points > p4.points){
                    cout << p1.getName() << " and " << p2.getName() << " and " << p3.getName() << " have tied for first place!";
                } 
                //Except player 3
                else if(p1.points == p2.points and p1.points > p3.points and p1.points == p4.points){
                    cout << p1.getName() << " and " << p2.getName() << " and " << p4.getName() << " have tied for first place!";
                }
                //Except player 2
                else if(p1.points > p2.points and p1.points == p3.points and p1.points == p4.points){
                    cout << p1.getName() << " and " << p3.getName() << " and " << p4.getName() << " have tied for first place!";
                }
                //Except player 1
                else if(p2.points > p1.points and p2.points == p3.points and p2.points == p4.points){
                    cout << p2.getName() << " and " << p3.getName() << " and " << p4.getName() << " have tied for first place!";

                } 
                //If all tied
                else if(p1.points == p2.points and p1.points == p3.points and p1.points == p4.points){
                    cout << "It was a 4 way tie!";
                } 
            loop = false;
        }
/**
* If an invalid choice is inputted, it will prompt the user to enter a valid choice
*/
        else {
            cout << endl << "Please enter a valid option." << endl;
        }
    }
}

#include "gameproject.h"
#include "datastructures.h"
#include <iostream>
#include <string>
using std::string, std::cout, std::cin;

int main(){
    int playerCount;

    cout << "Welcome to the Dungeon!\n" <<
    "How many players are there?\n" <<
    "Choose 2 to 4 players\n";

    cin >> playerCount;

    while (playerCount < 2 || playerCount > 4){
        cout << "Invalid number of players\n" <<
        "Choose 2 to 4 players\n";
        cin >> playerCount;
    }

    GameObject players[playerCount];

    
    return 0;
}
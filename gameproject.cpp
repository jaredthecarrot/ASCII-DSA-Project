#include "gameproject.h"
#include "datastructures.h"
#include <iostream>
#include <string>
using std::string, std::cout, std::cin;

int main(){

    // i want to create a graph of rooms

    Graph<int> rooms;
    Stack<int> s;

    s.push(rooms.addVertex(4));

    s.push(rooms.addVertex(3));

    s.push(rooms.addVertex(2));

    s.push(rooms.addVertex(1));

    int playerCount;

    cout << "Welcome to the Dungeon!\n" <<
    "You are a group of adventurers trying to find the treasure that lies within.\n" <<
    "You must work together to defeat the monsters that guard the treasure.\n" <<
    "There are 4 total levels to the dungeon.\n\n" <<
    "How many players are there?\n" <<
    "Choose 2 to 4 players.\n";

    cin >> playerCount;

    while (playerCount < 2 || playerCount > 4){
        cout << "Invalid number of players.\n" <<
        "Choose 2 to 4 players.\n";
        cin >> playerCount;
    }

    GameObject players[playerCount];
    Inventory inventory[playerCount];

    for (int i = 0; i < playerCount; i++){
        cout << "Player " << i + 1 << ":\n";
        cout << "Do you want to be a (1) warrior or (2) mage?\n";
        int choice;
        cin >> choice;
        while (choice != 1 && choice != 2){
            cout << "Invalid choice\n" <<
            "Do you want to be a (1) warrior or (2) mage?\n";
            cin >> choice;
        }
        if (choice == 1){
            players[i].setHealth(150);
            players[i].setMelee(20);
            players[i].setMagic(5);
            players[i].setDefense(15);
        }
        else{
            players[i].setHealth(100);
            players[i].setMelee(5);
            players[i].setMagic(20);
            players[i].setDefense(10);
        }
    }

    cout << "Warriors have 150 health, 20 melee, 5 magic, and 15 defense.\n" <<
    "Mages have 100 health, 5 melee, 20 magic, and 10 defense.\n";

    // choose a starting weapon, armor, and spell

    for (int i = 0; i < playerCount; i++){
        cout << "Player " << i + 1 << ":\n";
        cout << "Choose a starting weapon:\n" <<
        "(1) Sword\n" <<
        "(2) Axe\n" <<
        "(3) Staff\n" <<
        "(4) Wand\n";
        int choice;
        cin >> choice;
        while (choice != 1 && choice != 2 && choice != 3 && choice != 4){
            cout << "Invalid choice\n" <<
            "Choose a starting weapon:\n" <<
            "(1) Sword\n" <<
            "(2) Axe\n" <<
            "(3) Staff\n" <<
            "(4) Wand\n";
            cin >> choice;
        }
        if (choice == 1){
            inventory[i].addItem("Sword");
        }
        else if (choice == 2){
            inventory[i].addItem("Axe");
        }
        else if (choice == 3){
            inventory[i].addItem("Staff");
        }
        else{
            inventory[i].addItem("Wand");
        }

        cout << "Choose a starting armor:\n" <<
        "(1) Shield\n" <<
        "(2) Helmet\n" <<
        "(3) Robe\n" <<
        "(4) Cloak\n";
        cin >> choice;
        while (choice != 1 && choice != 2 && choice != 3 && choice != 4){

            cout << "Invalid choice\n" <<

            "Choose a starting armor:\n" <<

            "(1) Shield\n" <<

            "(2) Helmet\n" <<

            "(3) Robe\n" <<

            "(4) Cloak\n";

            cin >> choice;

        }
        if (choice == 1){
            inventory[i].addItem("Shield");
        }
        else if (choice == 2){
            inventory[i].addItem("Helmet");
        }
        else if (choice == 3){
            inventory[i].addItem("Robe");
        }
        else{
            inventory[i].addItem("Cloak");
        }

        cout << "Choose a starting spell:\n" <<

        "(1) Fireball\n" <<
        "(2) Icebolt\n" <<
        "(3) Lightning\n" <<
        "(4) Heal\n";

        cin >> choice;

        while (choice != 1 && choice != 2 && choice != 3 && choice != 4){

            cout << "Invalid choice\n" <<

            "Choose a starting spell:\n" <<

            "(1) Fireball\n" <<
            "(2) Icebolt\n" <<
            "(3) Lightning\n" <<
            "(4) Heal\n";

            cin >> choice;
        }
        if (choice == 1){
            inventory[i].addItem("Fireball");
        }
        else if (choice == 2){
            inventory[i].addItem("Icebolt");
        }

        else if (choice == 3){
            inventory[i].addItem("Lightning");
        }

        else{
            inventory[i].addItem("Heal");
        }
    }

    // create enemies

    GameObject enemies_1[playerCount * 2];
    GameObject enemies_2[playerCount * 3];
    GameObject enemies_3[playerCount * 4];
    GameObject enemies_4[(playerCount * 4) + 3];
    int remainingPlayers = playerCount;

    while (remainingPlayers > 0){
        if (s.top() == 1){
            // level for 1st room
        }
        else if (s.top() == 2){
            // level for 2nd room
        }
        else if (s.top() == 3){
            // level for 3rd room
        }
        else if (s.top() == 4){
            // level for 4th room
        }
        else {
            cout << "Congratulations! You have defeated the dungeon!\n";
            return 0;
        }
        
    }

    cout << "Game Over\n";
    
    return 0;
}
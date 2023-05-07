#include "gameproject.h"
#include "datastructures.h"
#include <iostream>
#include <string>
#include <algorithm>
using std::string, std::cout, std::cin;

int main()
{
    Graph<int> rooms;
    Stack<int> s;
    Queue<GameObject> q1, q2; // q1 for players, q2 for enemies

    s.push(rooms.addVertex(3)); // pushes rooms 1, 2, 3 to stack

    s.push(rooms.addVertex(2));

    s.push(rooms.addVertex(1));

    int playerCount;

    cout << "Welcome to the Dungeon!\n"
         << "You are a group of adventurers trying to find the treasure that lies within.\n"
         << "You must work together to defeat the monsters that guard the treasure.\n"
         << "There are 3 total levels to the dungeon.\n\n"
         << "How many players are there?\n"
         << "Choose 2 to 4 players.\n";

    cin >> playerCount;

    while (playerCount < 2 || playerCount > 4)
    {
        cout << "Invalid number of players.\n"
             << "Choose 2 to 4 players.\n";
        cin >> playerCount;
    }

    GameObject players[playerCount];
    Inventory inventory[playerCount]; //  Dictionary ADT for inventory

    for (int i = 0; i < playerCount; i++)
    {
        cout << "Player " << i + 1 << ":\n";
        cout << "Do you want to be a (1) warrior or (2) mage?\n";
        int choice;
        cin >> choice;
        while (choice != 1 && choice != 2)
        {
            cout << "Invalid choice\n"
                 << "Do you want to be a (1) warrior or (2) mage?\n";
            cin >> choice;
        }
        if (choice == 1)
        {
            players[i].setHealth(150);
            players[i].setMelee(20);
            players[i].setMagic(5);
            players[i].setDefense(15);
        }
        else
        {
            players[i].setHealth(100);
            players[i].setMelee(5);
            players[i].setMagic(20);
            players[i].setDefense(10);
        }
    }

    cout << "Warriors have 150 health, 20 melee, 5 magic, and 15 defense.\n"
         << "Mages have 100 health, 5 melee, 20 magic, and 10 defense.\n";

    for (int i = 0; i < playerCount; i++)
    {
        cout << "Player " << i + 1 << ":\n";
        cout << "Choose a starting weapon:\n"
             << "(1) Sword\n"
             << "(2) Axe\n"
             << "(3) Staff\n"
             << "(4) Wand\n";
        int choice;
        cin >> choice;
        while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
        {
            cout << "Invalid choice\n"
                 << "Choose a starting weapon:\n"
                 << "(1) Sword\n"
                 << "(2) Axe\n"
                 << "(3) Staff\n"
                 << "(4) Wand\n";
            cin >> choice;
        }
        if (choice == 1)
        {
            inventory[i].addItem("Sword");
        }
        else if (choice == 2)
        {
            inventory[i].addItem("Axe");
        }
        else if (choice == 3)
        {
            inventory[i].addItem("Staff");
        }
        else
        {
            inventory[i].addItem("Wand");
        }

        cout << "Choose a starting armor:\n"
             << "(1) Shield\n"
             << "(2) Helmet\n"
             << "(3) Robe\n"
             << "(4) Cloak\n";
        cin >> choice;
        while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
        {

            cout << "Invalid choice\n"
                 <<

                "Choose a starting armor:\n"
                 <<

                "(1) Shield\n"
                 <<

                "(2) Helmet\n"
                 <<

                "(3) Robe\n"
                 <<

                "(4) Cloak\n";

            cin >> choice;
        }
        if (choice == 1)
        {
            inventory[i].addItem("Shield");
        }
        else if (choice == 2)
        {
            inventory[i].addItem("Helmet");
        }
        else if (choice == 3)
        {
            inventory[i].addItem("Robe");
        }
        else
        {
            inventory[i].addItem("Cloak");
        }

        cout << "Choose a starting spell:\n"
             << "(1) Fireball\n"
             << "(2) Icebolt\n"
             << "(3) Lightning\n"
             << "(4) Heal\n";

        cin >> choice;

        while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
        {

            cout << "Invalid choice\n"
                 <<

                "Choose a starting spell:\n"
                 <<

                "(1) Fireball\n"
                 << "(2) Icebolt\n"
                 << "(3) Lightning\n"
                 << "(4) Heal\n";

            cin >> choice;
        }
        if (choice == 1)
        {
            inventory[i].addItem("Fireball");
        }
        else if (choice == 2)
        {
            inventory[i].addItem("Icebolt");
        }

        else if (choice == 3)
        {
            inventory[i].addItem("Lightning");
        }

        else
        {
            inventory[i].addItem("Heal");
        }
    }

    for (int i = 0; i < playerCount; i++)
    {
        cout << "Player " << i + 1 << " inventory:\n";
        inventory[i].printItems(); // Prints inventory
    }

    for (int i = 0; i < playerCount; i++)
    {
        GameObject enemies_1[playerCount * 2];
        GameObject enemies_2[playerCount * 3];
        GameObject enemies_3[playerCount * 4];
        int remainingPlayers = playerCount;

        for (int i = 0; i < playerCount; i++)
        {
            q1.enqueue(players[i]);
            for (int i = 0; i < playerCount * 2; i++)
                enemies_1[i].setHealth(30);
            enemies_1[i].setMelee(10);
            enemies_1[i].setMagic(5);
            enemies_1[i].setDefense(10);
            q2.enqueue(enemies_1[i]);
        }

        int currentPlayerIndex = 0;

        cout << "You are now descending to the first level.\n"
             << "Room layout looks like:\n\n";
        rooms.DFS(1);
        cout << '\n'
             << '\n';

        while (true)
        {
            GameObject currentPlayer = players[currentPlayerIndex];
            GameObject enemy = q2.dequeue();
            cout << "It is Player " << currentPlayerIndex + 1 << "'s turn.\n";
            currentPlayer.combat(currentPlayer, enemy);
            if (currentPlayer.getHealth() <= 0)
            {
                cout << "Player " << currentPlayerIndex + 1 << " has died.\n";
                remainingPlayers--;
                if (remainingPlayers == 0)
                {
                    cout << "All players have died.\n"
                         << "Game over.\n";
                    return 0;
                }
            }
            else
            {
                q1.enqueue(currentPlayer);
            }

            if (enemy.getHealth() <= 0)
            {
                cout << "Enemy has died.\n";
            }
            else
            {
                enemy.enemyAttack(currentPlayer);
                q2.enqueue(enemy);
            }

            if (q1.isEmpty())
            {
                cout << "All players have died.\n"
                     << "Game over.\n";
                return 0;
            }

            if (q2.isEmpty())
            {
                cout << "All enemies have died.\n"
                     << "Level 1 complete.\n";
                break;
            }

            currentPlayerIndex = (currentPlayerIndex + 1) % playerCount;
        }

        cout << "You are now descending to the second level.\n"
             << "Beware! The enemies are stronger.\n"
             << "Room layout looks like:\n\n";
        rooms.DFS(2);
        cout << '\n'
             << '\n';
        s.pop();                      // Pops the 1st room
        Queue<GameObject> q1_2, q2_2; // q1 for players, q2 for enemies, 2nd level

        for (int i = 0; i < playerCount; i++)
        {
            q1_2.enqueue(players[i]);
            for (int i = 0; i < playerCount * 3; i++)
                enemies_2[i].setHealth(70);
            enemies_2[i].setMelee(20);
            enemies_2[i].setMagic(15);
            enemies_2[i].setDefense(15);
            q2_2.enqueue(enemies_2[i]);
        }

        currentPlayerIndex = 0;

        while (true)
        {
            GameObject currentPlayer = players[currentPlayerIndex];
            GameObject enemy = q2_2.dequeue();
            cout << "It is Player " << currentPlayerIndex + 1 << "'s turn.\n";
            currentPlayer.combat(currentPlayer, enemy);
            if (currentPlayer.getHealth() <= 0)
            {
                cout << "Player " << currentPlayerIndex + 1 << " has died.\n";
                remainingPlayers--;
                if (remainingPlayers == 0)
                {
                    cout << "All players have died.\n"
                         << "Game over.\n";
                    return 0;
                }
            }
            else
            {
                q1_2.enqueue(currentPlayer);
            }

            if (enemy.getHealth() <= 0)
            {
                cout << "Enemy has died.\n";
            }
            else
            {
                enemy.enemyAttack(currentPlayer);
                q2_2.enqueue(enemy);
            }

            if (q1_2.isEmpty())
            {
                cout << "All players have died.\n"
                     << "Game over.\n";
                return 0;
            }

            if (q2_2.isEmpty())
            {
                cout << "All enemies have died.\n"
                     << "Level 2 complete.\n";
                break;
            }

            currentPlayerIndex = (currentPlayerIndex + 1) % playerCount;
        }

        cout << "You are now descending to the third level.\n"
             << "Beware! Enemies are just as strong, but significantly more!\n"
             << "Health has been granted.\n"
             << "Room layout looks like:\n\n";
        rooms.DFS(3);
        cout << '\n'
             << '\n';
        s.pop();                      // Pop the 2nd room
        Queue<GameObject> q1_3, q2_3; // q1 for players, q2 for enemies, 3rd level

        for (int i = 0; i < playerCount; i++)
        {
            players[i].setHealth(150);
            q1_3.enqueue(players[i]);
            for (int i = 0; i < playerCount * 4; i++)
                enemies_3[i].setHealth(70);
            enemies_3[i].setMelee(20);
            enemies_3[i].setMagic(15);
            enemies_3[i].setDefense(15);
            q2_3.enqueue(enemies_3[i]);
        }

        while (true)
        {
            GameObject currentPlayer = players[currentPlayerIndex];
            GameObject enemy = q2_3.dequeue();
            cout << "It is Player " << currentPlayerIndex + 1 << "'s turn.\n";
            currentPlayer.combat(currentPlayer, enemy);
            if (currentPlayer.getHealth() <= 0)
            {
                cout << "Player " << currentPlayerIndex + 1 << " has died.\n";
                remainingPlayers--;
                if (remainingPlayers == 0)
                {
                    cout << "All players have died.\n"
                         << "Game over.\n";
                    return 0;
                }
            }
            else
            {
                q1_3.enqueue(currentPlayer);
            }

            if (enemy.getHealth() <= 0)
            {
                cout << "Enemy has died.\n";
            }
            else
            {
                enemy.enemyAttack(currentPlayer);
                q2_3.enqueue(enemy);
            }

            if (q1_3.isEmpty())
            {
                cout << "All players have died.\n"
                     << "Game over.\n";
                return 0;
            }

            if (q2_3.isEmpty())
            {
                cout << "All enemies have died.\n"
                     << "Level 3 complete.\n";
                break;
            }

            currentPlayerIndex = (currentPlayerIndex + 1) % playerCount;
        }
        s.pop(); // Pop the 3rd room

        if (s.isEmpty())
        {
            cout << "You have completed the dungeon!\n"
                 << "Congratulations!\n";
            return 0;
        }
        return 0;
    }
    return 0;
}
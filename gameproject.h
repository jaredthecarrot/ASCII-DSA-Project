#ifndef gameproject_h
#define gameproject_h
#include "datastructures.h"
#include <iostream>
#include <string>
using std::string, std::cout, std::cin;

class GameObject
{
private:
    int health, melee, magic, defense, initiative;

public:
    GameObject();
    int getHealth();
    int getMelee();
    int getMagic();
    int getDefense();
    void setHealth(int health);
    void setMelee(int melee);
    void setMagic(int magic);
    void setDefense(int defense);
    void printStats();
    void combat(GameObject player, GameObject &enemy);
    void enemyAttack(GameObject &player);
};

GameObject::GameObject()
{
    health = 100;
    melee = 27;
    magic = 12;
    defense = 14;
}

int GameObject::getHealth() { return health; }

int GameObject::getMelee() { return melee; }

int GameObject::getMagic() { return magic; }

int GameObject::getDefense() { return defense; }

void GameObject::setHealth(int health) { this->health = health; }

void GameObject::setMelee(int melee) { this->melee = melee; }

void GameObject::setMagic(int magic) { this->magic = magic; }

void GameObject::setDefense(int defense) { this->defense = defense; }

void GameObject::printStats()
{
    cout << "Health: " << health << '\n';
    cout << "Melee: " << melee << '\n';
    cout << "Magic: " << magic << '\n';
    cout << "Defense: " << defense << '\n';
    cout << "Initiative: " << initiative << '\n';
}

void GameObject::combat(GameObject attacker, GameObject &defender)
{
    cout << "Would you like to do a (1) melee attack or (2) magic attack?\n";
    int choice;
    cin >> choice;
    while (choice != 1 && choice != 2)
    {
        cout << "Invalid choice. Please enter 1 for melee attack or 2 for magic attack:\n";
        cin >> choice;
    }

    int damage;
    if (choice == 1)
    {
        damage = attacker.getMelee() - defender.getDefense();
    }
    else if (choice == 2)
    {
        damage = attacker.getMagic() - defender.getDefense();
    }
    if (damage < 0)
    {
        damage = 0;
    }

    defender.setHealth(defender.getHealth() - damage);
    cout << "You dealt " << damage << " damage to the enemy.\n";
}

void GameObject::enemyAttack(GameObject &target)
{
    int damage = getMelee() - target.getDefense();
    if (damage < 0)
        damage = 0;
    target.setHealth(target.getHealth() - damage);
    cout << "Enemy dealt " << damage << " damage to the player.\n";
}

class Inventory
{
public:
    Dictionary<string> items;
    Inventory();
    void addItem(string item);
    void removeItem(string item);
    void printItems();
};

Inventory::Inventory()
{
    items = Dictionary<string>();
}

void Inventory::addItem(string item)
{
    items.put(item);
}

void Inventory::removeItem(string item)
{
    items.remove(item);
}

void Inventory::printItems()
{
    for (int i = 0; i < items.size(); i++)
        cout << items.elements[i] << '\n';
}

#endif
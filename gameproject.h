#ifndef gameproject_h
#define gameproject_h
#include "datastructures.h"
#include <iostream>
#include <string>
using std::string, std::cout, std::cin;

class GameObject{
    private:
    int health, melee, magic, defense, speed;
    public:
    GameObject();
    int getHealth();
    int getMelee();
    int getMagic();
    int getDefense();
    int getSpeed();
    void setHealth(int health);
    void setMelee(int melee);
    void setMagic(int magic);
    void setDefense(int defense);
    void setSpeed(int speed);
    void printStats();
};

GameObject::GameObject(){
    health = 100;
    melee = 10;
    magic = 10;
    defense = 10;
    speed = 10;
}

int GameObject::getHealth(){return health;}

int GameObject::getMelee(){return melee;}

int GameObject::getMagic(){return magic;}

int GameObject::getDefense(){return defense;}

int GameObject::getSpeed(){return speed;}

void GameObject::setHealth(int health){this->health = health;}

void GameObject::setMelee(int melee){this->melee = melee;}

void GameObject::setMagic(int magic){this->magic = magic;}

void GameObject::setDefense(int defense){this->defense = defense;}

void GameObject::setSpeed(int speed){this->speed = speed;}

void GameObject::printStats(){
    cout << "Health: " << health << '\n';
    cout << "Melee: " << melee << '\n';
    cout << "Magic: " << magic << '\n';
    cout << "Defense: " << defense << '\n';
    cout << "Speed: " << speed << '\n';
}

class Inventory{
    public:
    Dictionary<string> items;
    Inventory();
    void addItem(string item);
    void removeItem(string item);
    void printItems();
};

Inventory::Inventory(){
    items = Dictionary<string>();
}

void Inventory::addItem(string item){
    items.put(item);
}

void Inventory::removeItem(string item){
    items.remove(item);
}

void Inventory::printItems(){
    for (int i = 0; i < items.size(); i++)
        cout << items.elements[i] << '\n';
}
#endif
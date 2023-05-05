#ifndef datastructures_h
#define datastructures_h
#define SIZE 50
#include <iostream>
using std::cout, std::endl, std::cin;

template <typename E>
class Stack{
    public:
    int t;
    int count;
    E elements[SIZE];
    Stack();
    E push(const E& element);
    E pop();
    E top();
    bool isEmpty();
    int size();
};

template <typename E>
Stack<E>::Stack(){
    t = -1;
    count = 0;
}

template <typename E>
bool Stack<E>::isEmpty(){return t == -1;}

template <typename E>
int Stack<E>::size(){return count;}

template <typename E>
E Stack<E>::push(const E& element){
    if (t == SIZE - 1){
        cout << "Stack is full" << endl;
        return -1;
    }
    elements[++t] = element;
    count++;
    return element;
}

template <typename E>
E Stack<E>::pop(){
    if (t == -1){
        cout << "Stack is empty" << endl;
        return -1;
    }
    E element = elements[t--];
    count--;
    return element;
}

template <typename E>
E Stack<E>::top(){
    if (t == -1){
        cout << "Stack is empty" << endl;
        return -1;
    }
    return elements[t];
}

template <typename E>
class Queue{
    public:
    int f;
    int r;
    int count;
    E elements[SIZE];
    Queue();
    E enqueue(E& element);
    E dequeue();
    E front();
    bool isEmpty();
    int size();
};

template <typename E>
Queue<E>::Queue(){
    f = 0;
    r = 0;
    count = 0;
}

template <typename E>
bool Queue<E>::isEmpty(){return count == 0;}

template <typename E>
int Queue<E>::size(){return count;}

template <typename E>
E Queue<E>::enqueue(E& element){
    if (count == SIZE){
        cout << "Queue is full" << endl;
        return 0;
    }
    elements[r] = element;
    r = (r + 1) % SIZE;
    count++;
    return element;
}

template <typename E>
E Queue<E>::dequeue(){
    if (count == 0){
        cout << "Queue is empty" << endl;
        return 0;
    }
    E element = elements[f];
    f = (f + 1) % SIZE;
    count--;
    return element;
}

template <typename E>
class Dictionary{
    public:
    int count;
    E elements[SIZE];
    Dictionary();
    E put(E& element);
    E find(E& element);
    E remove(E& element);
    bool isEmpty();
    int size();
};

template <typename E>
Dictionary<E>::Dictionary(){
    count = 0;
}

template <typename E>
bool Dictionary<E>::isEmpty(){return count == 0;}

template <typename E>
int Dictionary<E>::size(){return count;}

template <typename E>
E Dictionary<E>::put(E& element){
    if (count == SIZE){
        cout << "Dictionary is full" << endl;
        return 0;
    }
    elements[count++] = element;
    return element;
}

template <typename E>
E Dictionary<E>::find(E& element){
    for (int i = 0; i < count; i++){
        if (elements[i] == element){
            return elements[i];
        }
    }
    return 0;
}

template <typename E>
E Dictionary<E>::remove(E& element){
    for (int i = 0; i < count; i++){
        if (elements[i] == element){
            E temp = elements[i];
            elements[i] = elements[count - 1];
            count--;
            return temp;
        }
    }
    return 0;
}

template <typename E>
class Graph{
    public:
    int count = 0;
    E elements[SIZE];
    Graph();
    E addVertex(const E& element);
    E addEdge(const E& element1, const E& element2);
    E removeVertex(E& element);
    E removeEdge(E& element1, E& element2);
};

template <typename E>
Graph<E>::Graph(){
    count = 0;
}

template <typename E>
E Graph<E>::addVertex(const E& element){
    if (count == SIZE){
        cout << "Graph is full" << endl;
        return -1;
    }
    elements[count++] = element;
    return element;
}

template <typename E>
E Graph<E>::addEdge(const E& element1, const E& element2){
    if (count == 0){
        cout << "Graph is empty" << endl;
        return 0;
    }
    for (int i = 0; i < count; i++){
        if (elements[i] == element1){
            for (int j = 0; j < count; j++){
                if (elements[j] == element2){
                    elements[i].addEdge(element2);
                    elements[j].addEdge(element1);
                    return element1;
                }
            }
        }
    }
    return 0;
}

template <typename E>
E Graph<E>::removeVertex(E& element){
    if (count == 0){
        cout << "Graph is empty" << endl;
        return 0;
    }
    for (int i = 0; i < count; i++){
        if (elements[i] == element){
            E temp = elements[i];
            elements[i] = elements[count - 1];
            count--;
            return temp;
        }
    }
    return 0;
}

template <typename E>
E Graph<E>::removeEdge(E& element1, E& element2){
    if (count == 0){
        cout << "Graph is empty" << endl;
        return 0;
    }
    for (int i = 0; i < count; i++){
        if (elements[i] == element1){
            for (int j = 0; j < count; j++){
                if (elements[j] == element2){
                    elements[i].removeEdge(element2);
                    elements[j].removeEdge(element1);
                    return element1;
                }
            }
        }
    }
    return 0;
}

#endif
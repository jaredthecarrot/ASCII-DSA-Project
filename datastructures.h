#ifndef datastructures.h
#define datastructures.h
#define SIZE 10

template <typename E>
class Stack{
    private:
    int top;
    int size;
    E elements[SIZE];
    public:
    Stack();
    E push(E& element);
    E pop();
    E top();
    bool isEmpty();
    int size();
};

template <typename E>
Stack<E>::Stack(){
    top = -1;
    size = 0;
    for (int i = 0; i < SIZE; i++){
        elements[i] = NULL;
    }
}

template <typename E>
bool Stack<E>::isEmpty(){return top == -1;}

template <typename E>
int Stack<E>::size(){return size};

template <typename E>
E Stack<E>::push(E& element){
    if (top == SIZE - 1){
        cout << "Stack is full" << endl;
        return NULL;
    }
    elements[++top] = element;
    size++;
    return element;
}

template <typename E>
E Stack<E>::pop(){
    if (top == -1){
        cout << "Stack is empty" << endl;
        return NULL;
    }
    E element = elements[top--];
    size--;
    return element;
}

template <typename E>
E Stack<E>::top(){
    if (top == -1){
        cout << "Stack is empty" << endl;
        return NULL;
    }
    return elements[top];
}

template <typename E>
class Queue{
    private:
    int front;
    int rear;
    int size;
    E elements[SIZE];
    public:
    Queue();
    E enqueue(E& element);
    E dequeue();
    E front();
    bool isEmpty();
    int size();
};

template <typename E>
Queue<E>::Queue(){
    front = 0;
    back = 0;
    size = 0;
    for (int i = 0; i < SIZE; i++){
        elements[i] = NULL;
    }
}

template <typename E>
bool Queue<E>::isEmpty(){return size == 0;}

template <typename E>
int Queue<E>::size(){return size;}

template <typename E>
E Queue<E>::enqueue(E& element){
    if (size == SIZE){
        cout << "Queue is full" << endl;
        return NULL;
    }
    elements[rear] = element;
    rear = (rear + 1) % SIZE;
    size++;
    return element;
}

template <typename E>
E Queue<E>::dequeue(){
    if (size == 0){
        cout << "Queue is empty" << endl;
        return NULL;
    }
    E element = elements[front];
    front = (front + 1) % SIZE;
    size--;
    return element;
}

template <typename E>
class Dictionary{
    private:
    int size;
    E elements[SIZE];
    public:
    Dictionary();
    E put(E& element);
    E find(E& element);
    E remove(E& element);
    bool isEmpty();
    int size();
};

template <typename E>
Dictionary<E>::Dictionary(){
    size = 0;
    for (int i = 0; i < SIZE; i++){
        elements[i] = NULL;
    }
}

template <typename E>
bool Dictionary<E>::isEmpty(){return size == 0;}

template <typename E>
int Dictionary<E>::size(){return size;}

template <typename E>
E Dictionary<E>::put(E& element){
    if (size == SIZE){
        cout << "Dictionary is full" << endl;
        return NULL;
    }
    elements[size++] = element;
    return element;
}

template <typename E>
E Dictionary<E>::find(E& element){
    for (int i = 0; i < size; i++){
        if (elements[i] == element){
            return elements[i];
        }
    }
    return NULL;
}

template <typename E>
E Dictionary<E>::remove(E& element){
    for (int i = 0; i < size; i++){
        if (elements[i] == element){
            E temp = elements[i];
            elements[i] = elements[size - 1];
            size--;
            return temp;
        }
    }
    return NULL;
}

template <typename E>
class Graph{
    private:
    public:
};

#endif
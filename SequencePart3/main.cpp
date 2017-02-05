#include <iostream>
#include <cassert>
using namespace std;

template <class T>
class Sequence<T> {

public:
    static const int CAPACITY = 30;
    Sequence();
    ~Sequence();
    void start();
    void advance();
    void insert(const T &entry);
    void attach(const T &entry);
    void remove_current();
    int size() const;
    bool is_item() const;
    T current() const;
    //function I created
    void printItems();
    void printCurrentIndex();
    void printUsed();
    //Homework 2 methods to be added
    void addFront(const T &entry);
    T removeFront();
    void addEnd(const double &entry);
    void makeCurrentLastItem();
    //operator overloading methods
    Sequence operator+(Sequence &sequence);
    Sequence operator+=(Sequence &sequence);

private:
    T data[CAPACITY];
    int used;
    int current_index;

};

Sequence<T>::Sequence() {
    current_index = 0;
    used = 0;
}

Sequence<T>::~Sequence() {

}

//put current index at the beginning
void Sequence<T>::start() {
    current_index = 0;
}

void Sequence<T>::advance() {
    assert(is_item());

    current_index++;
}

// inserts an item to where the current_index is at
void Sequence<T>::insert(const T &entry) {
    // checks size of the bag is less than the CAPACITY(30). If greater, throw an error
    assert(size() < CAPACITY);

    // if the the current index is greater than the size of how many items you inserted into the bag, set current index to zero.
    if (!is_item()) {
        current_index = 0;
    }

    // move all the inserted values up a position
    for (int i = used; i > current_index; i--) {
        data[i] = data[i - 1];
    }

    // insert the new value to the beginning of the array
    data[current_index] = entry;
    // increment the size of the bag
    used++;
}

void Sequence<T>::attach(const T &entry) {
    // check if the size of the bag is less than the capacity, if greater, throw an error
    assert(size() < CAPACITY);

    // i dont know what this does yet
    if (!is_item()) {
        data[used - 1] = entry;
        return;
    }

    for (int i = used; i > current_index ; i--) {
        data[i + 1] = data[i];
    }

    data[++current_index] = entry;
    used++;
}

void Sequence<T>::remove_current() {
    assert(is_item());

    for (int i = current_index; i < used; i++) {
        data[i] = data[i + 1];
    }
    used--;
}

int Sequence<T>::size() const {
    return used;
}

//
bool Sequence<T>::is_item() const {
    return current_index < used;
}

T Sequence<T>::current() const {
    assert(is_item());

    return data[current_index];
}

// function I created
void Sequence<T>::printItems() {
    cout << endl << "All the items:" << endl;
    for (int i = 0; i < used; i++) { // use 30 or used as a condition to test how bag looks like
        cout << data[i] << endl;
    }
}

void Sequence<T>::printCurrentIndex() {
    cout << endl << "current index: " << current_index << endl;
}

void Sequence<T>::printUsed() {
    cout << endl << "used: " << used << endl;
}

//Homework 2 methods to be added
void Sequence<T>::addFront(const T &entry) {
    for (int i = used - 1; i >= 0; i--) {
        data[i + 1] = data[i];
    }

    data[0] = entry;
    used++;
}

T Sequence<T>::removeFront() {
    T dataRemoved = data[0];

    for (int i = 0; i < used; i++) {
        data[i] = data[i + 1];
    }

    used--;
    return dataRemoved;
}

void Sequence<T>::addEnd(const T &entry) {
    data[used++] = entry;
}

void Sequence<T>::makeCurrentLastItem() {
    current_index = used - 1;
}

Sequence Sequence<T>::operator+(Sequence &sequence) {
    Sequence brandNew;

    for (int i = 0; i < used; i++) {
        brandNew.addEnd(data[i]);
    }

    for (int i = 0; i < used; i++) {
        brandNew.addEnd(sequence.data[i]);
    }

    return brandNew;
}

Sequence Sequence<T>::operator+=(Sequence &sequence) {
    for (int i = 0; i < sequence.used; i++) {
        addEnd(sequence.data[i]);
    }
}

int main() {
    Sequence *bag = new Sequence;

    bag->insert(1);
    bag->insert(2);
    bag->insert(3);
    cout << bag->current() << endl;
    bag->advance();
    cout << bag->current() << endl;
    bag->advance();
    cout << bag->current() << endl;
    bag->printItems();
    bag->printCurrentIndex();
    bag->insert(4);
    bag->printItems();
    bag->remove_current();
    bag->printItems();
    bag->printCurrentIndex();
    bag->printUsed();
    bag->insert(5);
    bag->printItems();
    bag->printCurrentIndex();
    bag->printUsed();
    bag->attach(6);
    bag->printItems();
    bag->printCurrentIndex();
    bag->printUsed();
    bag->addFront(7);
    bag->printItems();
    bag->printCurrentIndex();
    bag->printUsed();
    bag->removeFront();
    bag->printItems();
    bag->printCurrentIndex();
    bag->printUsed();
    bag->addEnd(8);
    bag->printItems();
    bag->printCurrentIndex();
    bag->printUsed();
    bag->makeCurrentLastItem();
    bag->printItems();
    bag->printCurrentIndex();
    bag->printUsed();

    Sequence *bag2 = new Sequence;
    bag2->addEnd(9);
    bag2->addEnd(10);
    bag2->addEnd(11);
    bag2->addEnd(12);
    bag2->printItems();

    Sequence bag3 = *bag + *bag2;
    bag3.printItems();
    bag3.printCurrentIndex();
    bag3.printUsed();

    *bag += *bag2;

    bag->printItems();
    bag->printCurrentIndex();
    bag->printUsed();
    return 0;
}
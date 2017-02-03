#include <iostream>
#include <cassert>
using namespace std;

//

class Sequence {

public:
    static const int CAPACITY = 30;
    Sequence();
    void start();
    void advance();
    void insert(const double &entry);
    void attach(const double &entry);
    void remove_current();
    int size() const;
    bool is_item() const;
    double current() const;
    //function I created
    void printItems();
    void printCurrentIndex();
    void printUsed();
    //Homework 2 methods to be added
    void addFront(const double &entry);
    double removeFront();
    void addEnd(const double &entry);
    void makeCurrentLastItem();
    //operator overloading methods
    Sequence operator+(Sequence &sequence);
    Sequence operator+=(Sequence &sequence);

private:
    double data[CAPACITY];
    int used;
    int current_index;

};

Sequence::Sequence() {
    current_index = 0;
    used = 0;
}

//put current index at the beginning
void Sequence::start() {
    current_index = 0;
}

void Sequence::advance() {
    assert(is_item());

    current_index++;
}

// inserts an item to where the current_index is at
void Sequence::insert(const double &entry) {
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

void Sequence::attach(const double &entry) {
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

void Sequence::remove_current() {
    assert(is_item());

    for (int i = current_index; i < used; i++) {
        data[i] = data[i + 1];
    }
    used--;
}

int Sequence::size() const {
    return used;
}

// 
bool Sequence::is_item() const {
    return current_index < used;
}

double Sequence::current() const {
    assert(is_item());

    return data[current_index];
}

// function I created
void Sequence::printItems() {
    cout << endl << "All the items:" << endl;
    for (int i = 0; i < used; i++) { // use 30 or used as a condition to test how bag looks like
        cout << data[i] << endl;
    }
}

void Sequence::printCurrentIndex() {
    cout << endl << "current index: " << current_index << endl;
}

void Sequence::printUsed() {
    cout << endl << "used: " << used << endl;
}

//Homework 2 methods to be added
void Sequence::addFront(const double &entry) {
    for (int i = used - 1; i >= 0; i--) {
        data[i + 1] = data[i];
    }

    data[0] = entry;
    used++;
}

double Sequence::removeFront() {
    double dataRemoved = data[0];

    for (int i = 0; i < used; i++) {
        data[i] = data[i + 1];
    }

    used--;
    return dataRemoved;
}

void Sequence::addEnd(const double &entry) {
    data[used++] = entry;
}

void Sequence::makeCurrentLastItem() {
    current_index = used - 1;
}

Sequence Sequence::operator+(Sequence &sequence) {
    Sequence brandNew;

    for (int i = 0; i < used; i++) {
        brandNew.addEnd(data[i]);
    }

    for (int i = 0; i < sequence.used; i++) {
        brandNew.addEnd(sequence.data[i]);
    }

    return brandNew;
}

Sequence Sequence::operator+=(Sequence &sequence) {
    for (int i = 0; i < sequence.used; i++) {
        addEnd(sequence.data[i]);
    }
}

int main() {
    Sequence bag;

    bag.insert(1);
    bag.insert(2);
    bag.insert(3);
    cout << bag.current() << endl;
    bag.advance();
    cout << bag.current() << endl;
    bag.advance();
    cout << bag.current() << endl;
    bag.printItems();
    bag.printCurrentIndex();
    bag.insert(4);
    bag.printItems();
    bag.remove_current();
    bag.printItems();
    bag.printCurrentIndex();
    bag.printUsed();
    bag.insert(5);
    bag.printItems();
    bag.printCurrentIndex();
    bag.printUsed();
    bag.attach(6);
    bag.printItems();
    bag.printCurrentIndex();
    bag.printUsed();
    bag.addFront(7);
    bag.printItems();
    bag.printCurrentIndex();
    bag.printUsed();
    bag.removeFront();
    bag.printItems();
    bag.printCurrentIndex();
    bag.printUsed();
    bag.addEnd(8);
    bag.printItems();
    bag.printCurrentIndex();
    bag.printUsed();
    bag.makeCurrentLastItem();
    bag.printItems();
    bag.printCurrentIndex();
    bag.printUsed();

    Sequence bag2;
    bag2.addEnd(9);
    bag2.addEnd(10);
    bag2.addEnd(11);
    bag2.addEnd(12);
    bag2.printItems();

    Sequence bag3 = bag + bag2;
    bag3.printItems();
    bag3.printCurrentIndex();
    bag3.printUsed();

    bag += bag2;

    bag.printItems();
    bag.printCurrentIndex();
    bag.printUsed();
    return 0;
}
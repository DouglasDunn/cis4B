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
    return 0;
}
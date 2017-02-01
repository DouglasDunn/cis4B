#include <iostream>
using namespace std;

//

class Sequence {

public:
    static const int CAPACITY = 30;
    Sequence();
    void start();
    void advance();
    void insert(const double &entry);


private:
    double data[CAPACITY];
    int used;
    int current_index;

};

Sequence::Sequence() {
    current_index = -1;
}

void Sequence::start() {

}

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
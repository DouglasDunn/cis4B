#include <iostream>

using namespace std;

class Statistician {

private:
    double sum;
    int count;
    double last;
    double smallest;
    double largest;

public:
    Statistician();
    void next_number(double val);
    double getSum() const;
    int getLength() const;
    double getLast() const;
    double getMean() const;
    double getSmallest() const;
    double getLargest() const;

};

Statistician::Statistician() {
    count = 0;
    sum = 0;
}

void Statistician::next_number(double val) {

    if (count == 0) {
        smallest = val;
        largest = val;
    }

    sum += val;
    count++;
    last = val;

    if (val < smallest) {
        smallest = val;
    } else if (val > largest) {
        largest = val;
    }
}

double Statistician::getSum() const {
    return sum;
}

int Statistician::getLength() const {
    return count;
}

double Statistician::getLast() const {
    return last;
}

double Statistician::getMean() const {
    return sum / count;
}

double Statistician::getSmallest() const {
    return smallest;
}

double Statistician::getLargest() const {
    return largest;
}

// assert(length!=0) is the precondition. Have to include the cassert library

int main() {
    Statistician s;
    s.next_number(2.2);
    s.next_number(1.2);
    s.next_number(4.2);
    s.next_number(3.2);
    // 10.8
    cout << s.getSum() << endl;
    cout << s.getLength() << endl;
    cout << s.getLast() << endl;
    cout << s.getMean() << endl; // 2.7
    cout << s.getSmallest() << endl;
    cout << s.getLargest() << endl;
    return 0;
}
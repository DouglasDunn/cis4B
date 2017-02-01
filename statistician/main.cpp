#include <iostream>
#include <cassert>

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
    void erase();
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
    assert(count != 0);
    return last;
}

double Statistician::getMean() const {
    assert(count != 0);
    return sum / count;
}

double Statistician::getSmallest() const {
    assert(count != 0);
    return smallest;
}

double Statistician::getLargest() const {
    assert(count != 0);
    return largest;
}

void Statistician::erase() {
    count = 0;
    sum = 0;
}

int main() {
    Statistician s;
    s.next_number(2.2);
    s.next_number(1.2);
    s.next_number(4.2);
    s.next_number(3.2);
    cout << "The sum is: " << s.getSum() << endl;
    cout << "The length is: " << s.getLength() << endl;
    cout << "The last number is: " << s.getLast() << endl;
    cout << "The mean is: " << s.getMean() << endl;
    cout << "The smallest is: " << s.getSmallest() << endl;
    cout << "The largest is: " << s.getLargest() << endl;
    s.erase();
    cout << "After the erase." << endl;
    cout << "The sum is: " << s.getSum() << endl;
    cout << "The length is: " << s.getLength() << endl;
    return 0;
}
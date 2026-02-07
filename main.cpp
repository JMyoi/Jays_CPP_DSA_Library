#include <iostream>
#include "item.h"
#include "algo.h"

using namespace std; 

int main() {

    Item item1(5);
    cout << "The value of item1 is: " << item1.getValue() << endl;
    cout<< "The sum of 3 and 4 is: " << add(3, 4) << endl;
    return 0;
}
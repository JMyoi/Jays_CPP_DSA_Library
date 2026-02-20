#include <iostream>
#include <vector>
#include "linked_list.h"
#include "array_list.h"
using namespace std; 



int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.print();
    list.printR();


    return 0;
}
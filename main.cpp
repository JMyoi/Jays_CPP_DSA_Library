#include <iostream>
#include <vector>
#include "linked_list.h"
#include "array_list.h"
using namespace std; 



int main() {
    LinkedList list;
    list.insertFront(1);
    list.insertFront(2);
    list.insertFront(3);
    list.insertFront(4);
    list.insertFront(5);
    list.print();
    list.printRec();


    return 0;
}
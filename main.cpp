#include <iostream>
#include <vector>
#include <limits>
#include "test_bench.h"
#include "misc.h"
using namespace std;




int main(){
    int choice = -1;

    do {
        cout << "\n========================================" << endl;
        cout << "        DSA Library Test Menu" << endl;
        cout << "========================================" << endl;
        cout << "1. Run ArrayList Test Bench" << endl;
        cout << "2. Run LinkedList Test Bench" << endl;
        cout << "3. Run HashMap Chaining Test Bench" << endl;
        cout << "4. Run HashMap Open Addressing Test Bench" << endl;
        cout << "5. Run Stack Test Bench" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            if (cin.eof()) {
                cout << "Input stream closed. Exiting test menu." << endl;
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number from 0 to 5." << endl;
            continue;
        }

        cout << endl;

        switch (choice) {
            case 1:
                ArrayListTest();
                break;
            case 2:
                LinkedListTest();
                break;
            case 3:
                HashMapChainingTest();
                break;
            case 4:
                HashMapOATest();
                break;
            case 5:
                StackTest();
                break;
            case 0:
                cout << "Exiting test menu." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number from 0 to 5." << endl;
                break;
        }
    } while (choice != 0);
    
    return 0;
} 



#include <iostream>
#include <vector>
#include "array_list.h"
using namespace std; 



int main() {
   ArrayList L1;
   //populate array
   for(int i = 0; i<10; i++){
    L1.Append(i);
   }
   L1.Insert(3, 67);
   L1.Insert(0, 67);
   L1.Insert(15, 67); // should be out of range.
   L1.Insert(12, 67); //inserting at end 
   cout<<"size: "<<L1.Size()<<" Capacity: "<<L1.Capacity()<<endl;
   
   L1.Display();




    return 0;
}
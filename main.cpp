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
   L1.Delete(10);
   L1.Delete(9);
   L1.Delete(0);

   L1.Display();
   cout<<"size: "<<L1.Size()<<" Capacity: "<<L1.Capacity()<<endl;


    return 0;
}
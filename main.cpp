#include <iostream>
#include "array_list.h"
using namespace std; 



int main() {
   ArrayList L1;
   for(int i = 0; i<12; i++){
    L1.Append(i);
   }
   
   L1.Display();

    return 0;
}
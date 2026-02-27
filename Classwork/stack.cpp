/* 
 Output:

Enter size of stack1: 5

Enter size of stack2: 5

Enter element of stack1: 1

Enter element of stack1: 2

Enter element of stack1: 3

Enter element of stack1: 4

Enter element of stack1: 5

Enter element of stack2: 6

Enter element of stack2: 7

Enter element of stack2: 8

Enter element of stack2: 9

Enter element of stack2: 10

displaying S3
=============
element: 10

element: 9

element: 8

element: 7

element: 6

element: 5

element: 4

element: 3

element: 2

element: 1
 
 
 */
#include <iostream> //example of operator overloading
#include <stack>
using namespace std;


template<class T>
class Stack {
public:
   Stack(int n); 
   Stack(Stack<T>& s); //copy constructor
   ~Stack() {delete [] stackPtr;}   // destructor
   Stack<T> operator +  (const Stack<T>& s2) const; //overloading +
   Stack<T>& operator = (const Stack<T>& s); //overloading assignment     
   bool Push (const T& element);  // Push element onto stack
   bool Pop (T& element);  // Pop element off stack
private:
   int size; // size of stack
   int top;  // location of the top element
   T *stackPtr; // pointer to stack 
   bool Isempty (){return (top == -1);}
   bool Isfull () {return (top == size - 1);}
};

template<class T>
Stack<T>& Stack<T> :: operator = (const Stack<T>& s) // overloading assignemnt
{ 
   if (&s != this) {
     delete [ ] stackPtr;
     size=s.size;
     top=s.top;     
     stackPtr= new T [size];
     for (int i=0; i < size; i++)
         stackPtr[i]=s.stackPtr[i];
    }
    return *this; 
}

template<class T>
Stack<T>  Stack<T> :: operator + (const Stack<T>& s2) const{
   // totsize = size of stack1 + size of stack2 
   // do your work here
   // + operator what is does is to concatenate two stacks
   // s1 and s2
   // example s1={1,3} and s2={4,6,7,8}, suppose that size s1=3, and size s2=7
   // top of stack1 = 1 (top element = 3}, top of stack2 = 3 (top element = 8)
   // totsize= 10 (that is size of s1 + size of s2)
   // temp={1,3,4,6,7,8}, where the top is 5 and the top element is 8

   int totsize = size + s2.size;
   Stack<T> temp(totsize);
   //populate new stack with s1 elements
   for(int i = 0; i<top+1 ;i++){
      temp.stackPtr[++temp.top] = stackPtr[i];
   }
   //populate new stack with s2 elements
   for(int i = 0; i<s2.top + 1; i++){
      temp.stackPtr[++temp.top] = s2.stackPtr[i];
   }
   return temp;
} 

template<class T>
Stack<T> :: Stack (Stack<T>& s) //copy constructor
{ size=s.size;
  stackPtr = new T [size];
  top=s.top;
  for (int i=0; i < size; i++)
   stackPtr[i]=s.stackPtr[i]; // allocate space for size elements of type T
} 

template<class T>
Stack<T> :: Stack (int n)
{ 
  size = n > 0 ? n : 10;
  top = -1; // empty stack
  stackPtr = new T [size]; // allocate space for size elements of type T
}

template<class T>
bool  Stack<T>::Push (const T& element)
{
  if ( !Isfull() ) {
     stackPtr[++top]=element;
     return (true);
  } 
   return (false);     
  
}

template<class T>
bool Stack<T>::Pop  (T& element)
{
  if ( !Isempty() ) {
     element=stackPtr[top--];
     return true;
  }
  return false;
}

int main(){
  int size1, size2, element;
  cout  << endl << "Enter size of stack1: " ;
  cin >> size1;
  cout  << endl << "Enter size of stack2: " ;
  cin >> size2;
  Stack< int > intS1 (size1), intS2 (size2), intS3 (1);
  //create stack1

  //should not be a do while loop because we want to stop when the stack is full, not after it is full.
  //a for loop is better and does not ask an extra time
   for(int i = 0; i<size1; i++){
      cout << endl << "Enter element of stack1: ";
      cin >> element;
      if(!intS1.Push(element)){
         cout << "Stack is full. Cannot push more elements." << endl;
         break;
      }
   }
   
    // create stack2
   for(int i = 0; i<size2; i++){
      cout << endl << "Enter element of stack2: ";
      cin >> element;
      if(!intS2.Push(element)){
         cout << "Stack is full. Cannot push more elements." << endl;
         break;
      }
  }

  intS3 = intS1 + intS2; // calls overloaded + and assignemtn operator.

  cout << endl << "displaying S3";
  cout << endl << "=============";  
  while ( intS3.Pop(element)){
     cout << endl << "element: " << element;
     cout << endl;
  }
 }
 
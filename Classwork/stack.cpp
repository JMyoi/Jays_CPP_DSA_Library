#include <iostream> //example of operator overloading
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
     top=s.top;     stackPtr= new T [size];
     for (int i=0; i < size; i++)
         stackPtr[i]=s.stackPtr[i];
    }
    return *this; 
}
template<class T>
Stack<T>  Stack<T> :: operator + (const Stack<T>& s2) const
{
   Stack<T> temp(totsize); // totsize = size of stack1 + size of stack2 
   // do your work here
   // + operator what is does is to concatenate two stacks
   // s1 and s2
   // example s1={1,3} and s2={4,6,7,8}, suppose that size s1=3, and size s2=7
   // top of stack1 = 1 (top element = 3}, top of stack2 = 3 (top element = 8)
   // totsize= 10 (that is size of s1 + size of s2)
   // temp={1,3,4,6,7,8}, where the top is 5 and the top element is 8
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
  size = n > 0 ? n :10;
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

int main()
{
  int size1, size2, element;
  cout  << endl << "Enter size of stack1: " ;
  cin >> size1;
  cout  << endl << "Enter size of stack2: " ;
  cin >> size2;
  Stack< int > intS1 (size1), intS2 (size2), intS3 (1);
  //create stack1
  do
  {  cout << endl << "Enter element of stack1: ";
     cin >> element;
  }  while (intS1.Push(element));
   
    // create stack2
  do
  {  cout << endl << "Enter element of stack2: ";
     cin >> element;
  }  while (intS2.Push(element));

  intS3 = intS1 + intS2;


  cout << endl << "displaying S3";
  cout << endl << "=============";  
  while ( intS3.Pop(element))
       cout << endl << "element: " << element;
       cout << endl;
 }
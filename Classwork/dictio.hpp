#pragma once
#include <iostream>

//exception is thrown if wrong input
class BadInput {
public:
  BadInput (){};
};

template <class E, class K>
struct Node {
  E data;
  Node<E,K>  *next;
};

template <class E, class K>
class SortedChain {
public:
  SortedChain() {first=0;}
  ~SortedChain();
  bool IsEmpty() {return (first==0);}
  //int Length() const;
  bool Search(const K& k, E& e) const;
  SortedChain<E,K>& Delete(const K& k, E& e);
  int Insert (const K& k,const E& e);
  void Output() const;
private:
  Node<E,K> *first;
};

template <class E, class K>
SortedChain<E,K>::~SortedChain(){
   Node<E,K> *current=first;
   while (first)
     { current=first->next;
       delete first;
       first=current;
     }
}

template <class E, class K>
bool SortedChain<E,K>::Search(const K& k, E& e) const {
  Node<E,K> *current = first;
  while (current && current->data.Key() < k)
    current = current->next;
  if (current && current->data.Key() == k) {
    e = current->data;
    return true;
  }
  return false;
}

template <class E, class K>
SortedChain<E,K>& SortedChain<E,K>::Delete(const K& k, E& e)
{
   Node<E,K> *prior=first, *current=first;
   while (current && current->data.Key() < k){  //search until key=k or key > k
       prior=current;
       current=current->next;
   }
   if (current && current->data.Key() == k) {
       e=current->data;
       if (first == current) //delete first node
          first=current->next;
       else
           prior->next=current->next;
       delete current;
       return *this;
   }
   else
       throw BadInput();
}

template <class E, class K>
int SortedChain<E,K>::Insert(const K& k, const E& e){
   int cmp = 0;
   Node<E,K> *prior=first, *current=first;
   while (current && (current->data).Key() < k){
       cmp++;   // count the Key() < k comparison
       prior=current;
       current=current->next;
   }
   if (current && (current->data).Key() == k)
        throw BadInput(); //another node with same key
   else {
       Node<E,K> *newp;
       newp=new Node<E,K>;
       if (first == current) { //we like to insert on first position
          first=newp;
       }
       else
           prior->next=newp;
       newp->next = current;
       newp->data=e;
       return cmp;
   }
}

template <class E, class K>
void SortedChain<E,K>::Output() const{
   Node <E,K> *current=first;
   std::cout <<  std::endl;
   while (current) {
     std::cout << current->data.Key() << current->data.Value() << " ->";
     current=current->next;
   }
}



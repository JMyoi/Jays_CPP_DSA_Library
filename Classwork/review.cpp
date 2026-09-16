#include <iostream>
using namespace std;

class Node {
	public:
		Node(int value = 0) {
			numVal = value;
		}
		~Node() {
			cout << numVal << endl;
		}
		int numVal;
		Node* next;
};
//linked list has a head value which points to the chain of values.
class LinkedList {
public:
	LinkedList();
	~LinkedList();
	void Prepend(int dataValue);

	Node* head;
};

LinkedList::LinkedList() {
	head = nullptr;
}

LinkedList::~LinkedList() {
	while (head) { // while head is not nullptr and points to another node
		Node* next = head->next;
		delete head;
		head = next;
	}
	cout << "Destructor for link list completed\n";
}

void LinkedList::Prepend(int dataValue) {
	Node* newNode = new Node(dataValue);
	newNode->next = head;
	head = newNode;
}
int main() {
	LinkedList* list = new LinkedList();
	list->Prepend(7);
	list->Prepend(6);
	list->Prepend(3);
	list->Prepend(1);

	delete list;

	return 0;
}
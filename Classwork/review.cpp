#include <iostream>
using namespace std;

class MyClass {
public:
	MyClass();
	MyClass(const MyClass& origObject);
	MyClass& operator=(const MyClass& objToCopy);
	~MyClass();

	void SetDataObject(const int setVal) { *dataObject = setVal; }
	int GetDataObject() const { return *dataObject; }

private:
	int* dataObject;
};
//default constructor
MyClass::MyClass() {
	dataObject = new int;
	*dataObject = 0;
}
//copy constructor
MyClass::MyClass(const MyClass& origObject) {
	cout << "Copy Constructor Called" << endl;
	dataObject = new int;
	*dataObject = *(origObject.dataObject);
}
//copy Assignment
MyClass& MyClass::operator=(const MyClass& objToCopy) {
	cout << "Assignment operator called.\n";
	if (this != &objToCopy) { // don't self assign
		delete dataObject; // delete old dynamic data to make space for copy
		dataObject = new int; // allocate new dynamic memory
		*dataObject = *(objToCopy.dataObject); // copy dataObject
	}
	return *this; 
}
//destructor
MyClass::~MyClass() {
	delete dataObject;
}

void foo(MyClass localObj) {
	localObj.SetDataObject(68);
}

int main() {
	MyClass a;
	MyClass b;

	a.SetDataObject(6);
	//copy class object using copy assignment operator
	b = a;

	b.SetDataObject(7);
	cout << "a: " << a.GetDataObject() << endl;
	cout << "b: " << b.GetDataObject() << endl;

	return 0;
}
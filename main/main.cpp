#include "SList.h"

int main()
{
	SList<int> lst; //тест гита на VS
	lst.push_back(1);
	lst.push_back(5);
	lst.push_back(100);

	cout << "Size: " << lst.GetSize() << endl;
	cout << lst << endl;
	
	cout << endl << "Popping front" << endl;
	lst.pop_front();
	cout << lst << endl;

	cout << endl << "Inserting 99 at 1, 2 at 1, 33 at 2" << endl;
	lst.insert(99, 1);
	lst.insert(2, 1);
	lst.insert(33, 2);
	cout << lst << endl;

	cout << endl << "Removing element at [2]" << endl;
	lst.remove(2);
	cout << lst << endl;

	cout << endl << "Popping back" << endl;
	lst.pop_back();
	cout << lst << endl;

	SList<int> lst2(lst);

	SList<int> a;
	a.push_back(123);

	SList<int> b(a);
}
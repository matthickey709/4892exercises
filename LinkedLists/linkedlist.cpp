#include "linkedlist.h"
#include <iostream>

using namespace std;

template<typename T>
ostream& operator << (ostream& o, const list<T>& v)
{
	o << "[";
	for (const auto& x : v)
	{
		o << " " << x;
	}
	o << " ]";

	return o;
}


int main(int argc, char const *argv[]) {
    list<int> myLinkedList = {4, 5, 10, 30, 35, 100};
    vector<int> myVector = {4, 5, 10, 30, 35, 100};

    // cout << "Contents of list/vector: " << myVector << "\n";

    deleteMultiplesof10(myVector);
    deleteMultiplesof10(myLinkedList);

    // cout << "Contents of list/vector: " << myVector << "\n";

    cout << "Contents of list/vector: " << myLinkedList << "\n";

    return 0;
}

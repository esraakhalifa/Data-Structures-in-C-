#include <iostream>
#include "LinkedList.h"

using namespace std;


int main()
{
    LinkedList L;
    L.add(25);
    L.add(50);
    L.add(45);
    L.add(55);
    L.display();
    L.add(57);
    L.add(57);
    L.add(57);
    L.InsertAfter(55,25);
    L.display();
    L.InsertBefore(32,45);
    L.display();
    cout << L.GetCount() << endl;
    cout << L.GetDataByIndex(0) << endl;
    cout << L.GetDataByIndex(4) << endl;
    cout << L.GetDataByIndex(8) << endl;
    cout << L.GetDataByIndex(55) << endl;
    L.removeAll(57);
    L.display();
    cout << L.GetCount() << endl;
    L.removeNode(32);
    L.display();
    cout << L.GetCount() << endl;

    return 0;
}

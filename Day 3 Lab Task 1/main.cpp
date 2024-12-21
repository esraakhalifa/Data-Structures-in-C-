#include <iostream>
#include "LinkedList.h"
using namespace std;

int Find(int target, int Array[], int ArraySize)
{
    for (int i = 0; i < ArraySize; i++)
    {
        if (Array[i] == target) return i;
    }
    return -1;
}

LinkedList findAll(int target, int Array[], int ArraySize)
{
    LinkedList ll;
    for (int i = 0; i < ArraySize; i++)
    {
        if (Array[i] == target)
        {
            ll.add(i);
        }
    }
    return ll;
}

int main()
{
    int arr[7]={56,34,8,9,92,0,2};
    int arr2[7]={55,55,8,9,92,0,55};
    cout << Find(2,arr,7) << endl;
    LinkedList result = findAll(55,arr2,7);
    result.display();
    return 0;
}

#include <iostream>
#include "LinkedList.h"
using namespace std;

void swapData(Node *Node1, Node *Node2)
{
    int temp = Node1->data;
    Node1->data = Node2->data;
    Node2->data = temp;
}
//void swapNode(Node &Node1, Node &Node2);

void BubbleSort(LinkedList &ll) {
    Node * current = ll.head;
    int sorted = 0;
    Node * lastSorted = NULL;
    for (int outer = 0; sorted == 0; outer++) {
        sorted = 1;
        Node * current = ll.head;
        while(current->next != NULL) {
            Node * nextNode = current->next;
            if (current->data > nextNode->data) {
                swapData(current, nextNode);
                sorted = 0;
            }
            current = current->next;
        }
        lastSorted = current;
    }
}

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
    L.InsertBefore(32,45);
    L.display();
    BubbleSort(L);
    L.display();

    return 0;
}

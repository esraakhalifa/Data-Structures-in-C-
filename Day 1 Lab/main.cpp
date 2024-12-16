#include <iostream>

using namespace std;

class Node{
public:
    Node * prev;
    Node * next;
    int data;
    Node(int data)

    {
        this -> data = data;
        prev = NULL;
        next = NULL;
    }
};
class LinkedList
{
public:
    Node * head;
    Node * tail;
    LinkedList()
    {
        head = tail = NULL;
    }
    void add(int data)
    {
        Node *newNode = new Node(data);
        if ( head == NULL)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;

    }
    void removeNode(int data)
    {
        Node * current = head;
        while(current != NULL)
        {
            if(current -> data == data)
            {
                if (current == head)
                {
                    //head -> next -> prev = current;
                    head = current -> next;
                    if ( head != NULL)
                    {
                        head->prev = NULL;
                    }
                    else
                    {
                        tail = NULL;
                    }

                }
                else if (current == tail)
                {
                    tail = current -> prev;
                    tail -> next = NULL;
                }
                else{
                    Node * A = current->prev;
                    Node * B = current->next;
                    A->next = B;
                    B->prev = A;
                }
                delete current;
                return;
            }
            current = current -> next;
        }
    }
    void removeAll(int data)
    {

        Node * current = head;
        if (current == NULL)
        {
            cout << "Linked list is empty.\n";
            return;
        }
        while(current != NULL)
        {
            Node * temp = current;
            if (current -> data == data)
            {
                removeNode(current -> data);
            }
            current = temp ->next;
        }
    }
};

int main()
{
    LinkedList L;
    L.add(25);
    L.add(50);
    L.add(45);
    return 0;
}

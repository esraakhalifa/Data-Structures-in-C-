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
                    head = current -> next;
                    if ( head != NULL) // not the only node in the list
                    {
                        head->prev = NULL;
                    }
                    else // only node in the list
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
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
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
            Node * temp = current->next; // saving the next node before removal
            if (current -> data == data)
            {
                removeNode(current -> data);
            }
            current = temp;
        }
    }
    int InsertAfter(int data, int afterData)
    {
        Node * newNode = new Node(data);
        Node * current = head;
        while(current != NULL)
        {
            if (current -> data == afterData)
            {
                newNode->prev = current;
                newNode->next = current->next;
                if (current->next != NULL)current->next->prev = newNode;
                else tail = newNode;
                current->next = newNode;
                return 1;
            }
            current = current->next;
        }
        return 0;
    }
    int InsertBefore(int data, int beforeData)
    {
        Node * newNode = new Node(data);
        Node * current = head;
        while(current != NULL)
        {
            if (current -> data == beforeData)
            {
                newNode->prev = current->prev;
                newNode->next = current;
                if (current->prev != NULL)current->prev->next = newNode;
                else head = newNode;
                current->prev = newNode;
                return 1;
            }
            current = current->next;
        }
        return 0;
    }

    int GetCount()
    {
        Node * current = head;
        int nodeCount = 0;
        while(current != NULL)
        {
            nodeCount++;
            current = current->next;
        }
        return nodeCount;
    }

    int GetDataByIndex(int index)
    {
        Node * current = head;
        int currenIndex = 0;
        while(current != NULL)
        {
            //nodeCount++;
            if (currenIndex == index)
            {
                return current->data;
            }
            current = current->next;
            currenIndex++;
        }
        return -1;
    }
    void display()
    {
        Node * current = head;
        if(current == NULL) cout << "Linked list is empty!\n";
        else{
            while(current != NULL)
            {
                cout << current->data << " ";
                current = current -> next;
            }
            cout << endl;
        }
    }
};

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

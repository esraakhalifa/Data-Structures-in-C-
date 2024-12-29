#include <iostream>
#include "LinkedList.h"

using namespace std;

Node::Node(int data)
{
    this->data = data;
    prev = NULL;
    next = NULL;
}

LinkedList::LinkedList()
{
    head = tail = NULL;
}

void LinkedList::add(int data)
{
    Node* newNode = new Node(data);
    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void LinkedList::removeNode(int data)
{
    Node* current = head;
    while (current != NULL)
    {
        if (current->data == data)
        {
            if (current == head)
            {
                head = current->next;
                if (head != NULL) // not the only node in the list
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
                tail = current->prev;
                tail->next = NULL;
            }
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            return;
        }
        current = current->next;
    }
}

void LinkedList::removeAll(int data)
{
    Node* current = head;
    if (current == NULL)
    {
        cout << "Linked list is empty.\n";
        return;
    }
    while (current != NULL)
    {
        Node* temp = current->next; // saving the next node before removal
        if (current->data == data)
        {
            removeNode(current->data);
        }
        current = temp;
    }
}

int LinkedList::InsertAfter(int data, int afterData)
{
    Node* newNode = new Node(data);
    Node* current = head;
    while (current != NULL)
    {
        if (current->data == afterData)
        {
            newNode->prev = current;
            newNode->next = current->next;
            if (current->next != NULL)
                current->next->prev = newNode;
            else
                tail = newNode;
            current->next = newNode;
            return 1;
        }
        current = current->next;
    }
    return 0;
}


int LinkedList::InsertBefore(int data, int beforeData)
{
    Node* newNode = new Node(data);
    Node* current = head;
    while (current != NULL)
    {
        if (current->data == beforeData)
        {
            newNode->prev = current->prev;
            newNode->next = current;
            if (current->prev != NULL)
                current->prev->next = newNode;
            else
                head = newNode;
            current->prev = newNode;
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int LinkedList::GetCount()
{
    Node* current = head;
    int nodeCount = 0;
    while (current != NULL)
    {
        nodeCount++;
        current = current->next;
    }
    return nodeCount;
}

int LinkedList::GetDataByIndex(int index)
{
    Node* current = head;
    int currentIndex = 0;
    while (current != NULL)
    {
        if (currentIndex == index)
        {
            return current->data;
        }
        current = current->next;
        currentIndex++;
    }
    return -1;
}
Node* LinkedList::GetNodeByIndex(int index)
{
    Node* current = head;
    int currentIndex = 0;
    while (current != NULL)
    {
        if (currentIndex == index)
        {
            return current;
        }
        current = current->next;
        currentIndex++;
    }
    return NULL;

}

void LinkedList::display()
{
    Node* current = head;
    if (current == NULL)
        cout << "Linked list is empty!\n";
    else
    {
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}


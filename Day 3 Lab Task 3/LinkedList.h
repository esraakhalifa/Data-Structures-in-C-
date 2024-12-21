#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class Node{
public:
    Node * prev;
    Node * next;
    int data;
    Node(int data);
};

class LinkedList {
public:
    Node * head;
    Node * tail;
    LinkedList();
    void add(int data);
    void removeNode(int data);
    void removeAll(int data);
    int InsertAfter(int data, int afterData);
    int InsertBefore(int data, int beforeData);
    int GetCount();
    int GetDataByIndex(int index);
    void display();

};

#endif // LINKEDLIST_H



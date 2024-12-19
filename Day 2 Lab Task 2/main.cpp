#include <iostream>

/* Improvements for to be applied:
    1==> Using header files for the prototypes and cpp files for implementations and testing
    2==> Using exception handling with throwing error messages and try and catch blocks instead of the -1 and hard coded messages
    3==> Implementing the queue using array
*/

using namespace std;

class QueueNode
{
public:
    int data;
    QueueNode * prev;
    QueueNode * next;
    QueueNode(int data)

    {
        this -> data = data;
        prev = NULL;
        next = NULL;
    }
};

class QueueLinkedList
{
public:
    QueueNode * Front;
    QueueNode * Rear;
    QueueLinkedList()
    {
        Front = Rear = NULL;
    }
    void enqueue(int data)
    {
        QueueNode * newNode = new QueueNode(data);
        if(Rear == NULL) Front = Rear = newNode;
        else{
            newNode->prev = Rear;
            Rear->next = newNode;
            Rear = newNode;
        }
    }
    void dequeue()
    {
        if (Front == NULL)
        {
            cout << "Queue is already empty!\n";
            return;
        }
        else if (Front->next == NULL)
        {
            delete Front;
            Front = Rear = NULL;
        }
        else{
            Front = Front -> next;
            delete Front->prev;
            Front->prev = NULL;
        }

    }
    /*int isEmpty()
    {
        if (Front == NULL) return 1;
        else return 0;
    }*/
    int GetFront()
    {
        if (Front == NULL)
        {
            cout << "Queue is already empty!\n";
            return -1;
        }
        return Front->data;
    }
    int GetRear()
    {
        if (Front == NULL)
        {
            cout << "Queue is already empty!\n";
            return -1;
        }
        return Rear->data;
    }
    void display()
    {
        QueueNode * current = Front;
        if(current == NULL)
        {
            cout << "Queue is empty!\n";
            return;
        }
        else{
            while(current != NULL)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    cout << "Testing the queue implementation using linked list:\n";
    QueueLinkedList q1;
    q1.enqueue(24);
    q1.enqueue(23);
    q1.enqueue(26);
    q1.enqueue(27);
    q1.enqueue(28);
    q1.enqueue(29);
    q1.enqueue(22);
    q1.display();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.display();
    cout << q1.GetFront() << endl;
    cout << q1.GetRear() << endl;
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    cout << q1.GetFront() << endl;
    cout << q1.GetRear() << endl;
    q1.display();
    return 0;
}

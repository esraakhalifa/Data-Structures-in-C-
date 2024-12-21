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
            return 0;
        }
        return Front->data;
    }
    int GetRear()
    {
        if (Front == NULL)
        {
            cout << "Queue is already empty!\n";
            return 0;
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

class QueueCircularArray
{
public:
    int Size;
    int Front;
    int Rear;
    int * items;
    QueueCircularArray(int Size = 5)
    {
        this->Size = Size;
        Front = Rear = -1;
        items = new int[Size];
    }
    int isEmpty()
    {
        if(Rear == Front && Rear == - 1) return 1;
        else return 0;
    }
    int isFull()
    {
        if ((Rear == Front - 1) || (Rear == Size - 1 && Front == 0)) return 1;
        else return 0;
    }
    int enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue is full!\n";
            return 0;
        }
        if (isEmpty()) // adding the first element
        {
            Front = Rear = 0;
        }
        else if (Rear == Size - 1 && Front != 0) //wrapping things up
        {
            Rear = 0;
        }
        else
        {
            Rear++;
        }
        items[Rear] = data;
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return 0;
        }
        items[Front] = 0;
        if (Rear == Front) Rear = Front = -1; //dequeue last element
        else if (Front == Size - 1) //wrap things up
        {
            Front = 0;
        }
        else { //normal case
            Front++;
        }
    }
    int GetRear()
    {
        if (Rear == -1)
        {
            cout << "Queue is empty!\n";
            return 0;
        }
        else return items[Rear];
    }
    int GetFront()
    {
        if (Front == -1)
        {
            cout << "Queue is empty!\n";
            return 0;
        }
        else return items[Front];
    }
    void display()
    {
        if (isEmpty())
            cout << "Queue is empty!\n";
        else
        {
            cout << "Queue elements: ";
            for (int i = Front; i != (Rear + 1) % Size; i = (i + 1) % Size)
            {
                cout << items[i] << " ";
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
    cout << "Testing the queue implementation using circular array:\n";
    QueueCircularArray q2(10);
    q2.enqueue(24);
    q2.enqueue(23);
    q2.enqueue(26);
    q2.enqueue(27);
    q2.enqueue(28);
    q2.enqueue(29);
    q2.enqueue(22);
    q2.display();
    q2.dequeue();
    q2.dequeue();
    q2.dequeue();
    q2.display();
    cout << q2.GetFront() << endl;
    cout << q2.GetRear() << endl;
    q2.dequeue();
    q2.dequeue();
    q2.dequeue();
    q2.dequeue();
    q2.dequeue();
    cout << q2.GetFront() << endl;
    cout << q2.GetRear() << endl;
    q2.display();
    return 0;
}

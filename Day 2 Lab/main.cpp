#include <iostream>

using namespace std;

class StackNode{
public:
    int data;
    StackNode * next;
    StackNode * prev;
    StackNode(int data)

    {
        this -> data = data;
        prev = NULL;
        next = NULL;
    }
};

class StackLinkedList{
public:
    StackNode * top;
    StackLinkedList()
    {
        top = NULL;
    }
    void push(int data)
    {
        StackNode * newNode = new StackNode(data);
        newNode->prev = top;
        if (top != NULL)
        {
            top->next = newNode;

        }
        top = newNode;
    }
    void pop()
    {
        if (top == NULL) cout << "Stack is empty!\n";
        else
        {
            top = top ->prev;
            delete top->next;
            top->next = NULL;
        }
    }
    void display()
    {
        StackNode * current = top;
        if(current == NULL) cout << "Stack is empty!\n";
        else{
            while(current != NULL)
            {
                cout << current->data << " ";
                current = current->prev;
            }
            cout << endl;
        }
    }
    int peek()
    {
        return top->data;
    }
};
class StackArray{

private:
    int size;
    int top;
    int * items;
    static int count;
public:
    StackArray(int size= 0)
    {
        this->size = size;
        top = -1;
        items = new int [size];
        count++;
    }
    StackArray(const StackArray &S)
    {
        this->size = S.size;
        this->top = S.top;
        this->items = new int[size];
        for (int i = 0; i < top + 1; i++)
        {
            this->items[i]=S.items[i];
        }
        count++;

    }

    int push(int data)
    {
        if(top == size - 1)
        {

            throw runtime_error("Stack is full.");
        }
        top++;
        items[top] = data;
        return 1;
    }
    void pop()
    {
        if (top == -1)
        {

            throw runtime_error("Stack is already empty.");
        }
        items[top] = 0;
        top--;

    }
    int peek()
    {
        return items[top];
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << items[i] << " ";
        }
        cout << endl;

    }
    ~StackArray()
    {
        delete [] items;
        count--;
    }
    StackArray operator=( StackArray &S)
    {
        delete[] items;
        size = S.size;
        top = S.top;
        items = new int[size];
        for (int i = 0; i < top + 1; i++)
        {
            items[i]=S.items[i];
        }
        cout << " = operator called!\n";
        return *this;
    }

};
int StackArray::count = 0;

int main()
{
    cout << "Testing the stack implementation using linked list:\n";
    StackLinkedList stack1;
    stack1.push(22);
    stack1.push(23);
    stack1.push(25);
    stack1.push(27);
    stack1.push(28);
    stack1.push(29);
    stack1.push(30);
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.display();
    cout << stack1.peek() << endl;
    cout << "Testing the stack implementation using array:\n";
    StackArray stack2(10);
    stack2.push(22);
    stack2.push(23);
    stack2.push(25);
    stack2.push(27);
    stack2.push(28);
    stack2.push(29);
    stack2.push(30);
    stack2.pop();
    stack2.pop();
    stack2.pop();
    stack2.display();
    cout << stack2.peek() << endl;
    return 0;
}

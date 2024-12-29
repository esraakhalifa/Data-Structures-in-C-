#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node * left;
    Node * right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class Tree
{
    private:
    Node * root;
    Node * GetNodeByData(int data)
    {
        Node * current = root;
        while(current != NULL)
        {
            if (data == current->data) return current;
            else if( data > current->data) current = current->right;
            else current = current->left;
        }
        return NULL;
    }
    Node * GetParentNode(Node * node)
    {
        Node * parent = root;
        while(parent != NULL)
        {

            if (node == parent->right || node == parent->left) return parent;
            else if (node->data > parent->data) parent = parent->right;
            else parent= parent->left;
        }
        return NULL;
    }
    Node * GetMaxRightNode(Node * node)
    {
        Node * current = node;
        while(current->right!=NULL)
        {
            current=current->right;
        }
        return current;
    }
    void display(Node * node)
    {
        if (node == NULL) return;
        display(node->left);
        cout << node-> data << "  ";
        display(node->right);
    }
    public:
        Tree(){root = NULL;}
        void add(int data)
        {
            Node * NewNode = new Node(data);
            if (root == NULL) root = NewNode;
            else{
                Node * current = root;
                Node * parent = NULL;
                while(current != NULL)
                {

                    parent = current;
                    if (data > current->data)current = current->right;
                    else current = current->left;
                }
                if (data > parent ->data) parent->right = NewNode;
                else parent ->left = NewNode;
            }
        }
        int DataIsFoundInTree(int data)
        {

            if (GetNodeByData(data) == NULL) return 0;
            return 1;
        }
        int GetParentByData(int data)
        {

            Node * node = GetNodeByData(data);
            if (node == root) throw "Node is the root. Root does not have a parent.";
            if (node != NULL)
            {
                Node * parent = GetParentNode(node);
                if (parent != NULL) return parent->data;
            }
            else throw "Node is not found. It does not have a parent.";
        }
        int GetMaxRightByData(int data)
        {
            Node * node = GetNodeByData(data);
            if (node == NULL) throw "Node is not found.";
            Node * MaxRight = GetMaxRightNode(node);
            return MaxRight->data;
        }
        void Remove(int data)
        {
            Node * node = GetNodeByData(data);
            if (node == NULL) throw "Error: The node is not found";
            if (node == root)
            {
                if (root->left == NULL && root->right == NULL) root = NULL;
                else if (root->left == NULL) root = root->right;
                else if (root->right == NULL) root = root-> left;
                else {
                    Node * NewRoot = root -> left;
                    Node * MaxRight = GetMaxRightNode(NewRoot);
                    MaxRight->right=root->right;
                    root=NewRoot;
                }
            }
            else{
                Node * parent = GetParentNode(node);
                Node * NewChild = NULL;
                if (node->left==NULL && node->right ==NULL)NewChild=NULL;
                else if (node->left == NULL) NewChild = node->right;
                else if (node->right == NULL) NewChild = node->left;
                else{
                    Node * NewParent = node -> left;
                    Node * MaxRight = GetMaxRightNode(NewParent);
                    MaxRight->right=node->right;
                    NewChild=NewParent;
                }
                if (parent->right==node) parent->right=NewChild;
                else parent->left=NewChild;
            }
            delete node;
        }

        void displayAll(){display(root);}

};
int main()
{
    Tree tree;
    tree.add(14);
    tree.add(12);
    tree.add(23);
    tree.add(11);
    tree.add(24);
    tree.add(22);
    tree.add(13);
    tree.Remove(14);
    tree.displayAll();
    return 0;
}

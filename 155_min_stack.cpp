#include<iostream>
using namespace std;

class Node
{
public:
    int val;
    int minVal;
    Node* next;
};

class MinStack {
    Node* node;
    // int minVal;
public:
    MinStack() {
        node = NULL;
    }
    
    void push(int val)
    {
        Node* temp = new Node;
        temp->val = val;
        if(node == NULL)
        {
            temp->next = NULL;
            node = temp;
            temp->minVal = val;
        }
        else
        {
            temp->next = node;
            temp->minVal = min(node->minVal,val);
            node = temp;
        }
    }
    
    void pop()
    {
        Node* temp = node;
        node = node->next;
        delete temp;
        temp = NULL;
    }
    
    int top()
    {
        return node->val;   
    }
    
    int getMin()
    {
        return node->minVal;  
    }
};

int main()
{
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << "min: " << obj->getMin() << endl;;
    obj->pop();
    cout << "top: " << obj->top() << endl;
    cout << "min: " << obj->getMin() << endl;;
    cout << endl << "La fin!" << endl;
}
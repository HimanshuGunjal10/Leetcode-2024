#include<iostream>
using namespace std;

class Node
{
public:
    int val;
    int minVal;
    Node* next;

    Node(int v)
    {
        val = v;
        minVal = INT_MAX;
        next = nullptr;
    }
};

class MinStack
{
private:
    Node* node;
public:
    MinStack();
    void push(int val);
    void pop();
    int top();
    int getMin();
};
MinStack::MinStack()
{
    node = nullptr;
}
void MinStack::push(int val)
{
    Node* topNode = new Node(val);
    if(node == nullptr) // first node
    {
        node = topNode;
        node->minVal = val;
    }
    else
    {
        topNode->minVal = min(val,node->minVal);
        topNode->next = node;
        node = topNode;
    }
}
void MinStack::pop()
{
    if(node == nullptr)
        return;
    Node* temp = node;
    node = node->next;
    delete temp;
}
int MinStack::top()
{
    return node->val;
}
int MinStack::getMin()
{
    return node->minVal;
}

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
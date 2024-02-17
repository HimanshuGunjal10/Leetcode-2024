#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}

};

class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) // missed slow check
        {
            if(slow == fast)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
/*
while(slow && fast && fast->next). Had missed slow check. Move first , then check if slow == fast  O(n) O(1)

*/

    bool hasCycle_1(ListNode *head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }   
        return false; 
    }
};

void print_list(struct ListNode* head)
{
    int count = 0;
    while(head && ++count<22)
    {
        cout << head->val << "-";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    struct ListNode head;
    struct ListNode* node_ptr = &head;
    struct ListNode* pos = NULL;
    
    for(int i=1; i<10; i++)
    {
        struct ListNode* temp = new ListNode(i);
        node_ptr->next = temp;
        node_ptr = temp;
        if(i==6)
            pos = node_ptr;
    }
    node_ptr->next = pos; //make a cycle
    
    cout << "list: ";
    print_list(&head);

    Solution sol;
    
    cout << "List has cycle: " << sol.hasCycle(&head);

    cout << endl << "La fin!" << endl;
}
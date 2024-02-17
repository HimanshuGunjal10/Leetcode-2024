#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        if(head == nullptr)
            return nullptr;
        
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

/*
prev, curr and next pointers. while curr and return prev. O(n) O(1)
*/

    ListNode* reverseList_1(ListNode* head)
    {
        if(head == NULL)
            return NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = curr->next;

        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

void print_list(struct ListNode* head)
{
    while(head)
    {
        cout << head->val << "-";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    struct ListNode head;
    struct ListNode* node_ptr = &head;
    
    for(int i=1; i<2; i++)
    {
        struct ListNode* temp = new ListNode(i);
        node_ptr->next = temp;
        node_ptr = temp;        
    }
    
    cout << "list: ";
    print_list(&head);

    Solution sol;
    struct ListNode* res = sol.reverseList(&head);
    
    cout << "reverse list: ";
    print_list(res);

    cout << endl << "La fin!" << endl;
}
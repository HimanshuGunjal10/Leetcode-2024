#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}

};

void print_list(struct ListNode*);

class Solution
{
public:
   void reorderList(ListNode* head)
    {
        //1. use Floyd's algo to find the midpoint
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* l1 = head;
        ListNode* l2 = slow->next;

        //2. reverse the second list
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* curr = l2;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        //prev is my last node
        l2 = prev;
        //break the link
        slow->next = nullptr;

        //3. stitch the two lists together now.
        ListNode* temp1;
        ListNode* temp2;

        while(l2)
        {
            temp1 = l1->next;
            temp2 = l2->next;
            l1->next = l2;
            l2->next = temp1;
            l1 = temp1;
            l2 = temp2;
        }
    }
/*
1. use Floyd's algo to find the midpoint; l1->next = nullptr 2. reverse second half 3. stich together.
*/

   void reorderList_1(ListNode* head)
   {
        if(head == NULL || head->next == NULL)
            return;

        /* FLoyd's algo to find mid point */        
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        /* reverse the second half */
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        ListNode* next = curr->next;

        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        ListNode* second = prev;
        slow->next = NULL;

        print_list(head);
        print_list(prev);

        /* reordering */
        ListNode* left = head;
        ListNode* right = second;

        ListNode *temp1, *temp2;

        while(right)
        {
            temp1 = left->next;
            temp2 = right->next;
            left->next = right;
            right->next = temp1;
            left = temp1;
            right = temp2;
        }

        print_list(head);
   }
};

void print_list(struct ListNode* head)
{
    while(head)
    {
        cout << head->val << "-";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    struct ListNode head(1);
    struct ListNode* node_ptr = &head;
    struct ListNode* pos = NULL;
    
    for(int i=2; i<7; i++)
    {
        struct ListNode* temp = new ListNode(i);
        node_ptr->next = temp;
        node_ptr = temp;
    }
    
    cout << "list: ";
    print_list(&head);
    
    Solution sol;
    sol.reorderList(&head);
    cout << "Reordered list: ";
    print_list(&head);

    cout << endl << "La fin!" << endl;
}
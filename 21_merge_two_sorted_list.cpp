#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}

};

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* head = NULL;
        ListNode* dummyHead = new ListNode(0); //made this change
        ListNode* curr = dummyHead;

        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if(list1)
            curr->next = list1;
        if(list2)
            curr->next = list2;
        //
        return dummyHead->next;
    }

    /*
    ListNode* dummy = new ListNode(0); return dummy->next check concise code O(n) O(1)
    */

    ListNode* mergeTwoLists_1(ListNode* list1, ListNode* list2)
    {
        ListNode* dummy = new ListNode(0); //made this change
        ListNode* itr = dummy;
        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                itr->next = list1;
                list1 = list1->next;
            }
            else
            {
                itr->next = list2;
                list2 = list2->next;
            }
            itr = itr->next;
        }
        if(list1)
            itr->next = list1;
        if(list2)
            itr->next = list2;

        return dummy->next;
    }
};

void print_list(struct ListNode* head)
{
    int count = 0;
    while(head)
    {
        cout << head->val << "-";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    struct ListNode list1(1);
    struct ListNode list2(2);
    struct ListNode* l1_ptr = &list1;
    struct ListNode* l2_ptr = &list2;
    
    for(int i=3; i<20; i++)
    {
        struct ListNode* temp = new ListNode(i);
        if(i&1)
        {
            l1_ptr->next = temp;
            l1_ptr = temp;
        }
        else
        {
            l2_ptr->next = temp;
            l2_ptr = temp;
        }
    }
    
    cout << "list1: ";
    print_list(&list1);
    cout << "list2: ";
    print_list(&list2);
    
    Solution sol;
    ListNode* result = sol.mergeTwoLists(&list1, &list2);    

    cout << "After sorting: " << endl;
    print_list(result);

    cout << endl << "La fin!" << endl;
}
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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* left = head;
        ListNode* right = head;
        ListNode* prev = nullptr;
        int k = n;
        while(k && right)
        {
            right = right->next;
            k--;
        }
        while(right)
        {
            prev = left;
            right = right->next;
            left = left->next;
        }
        if(prev == nullptr)
            return head->next;

        ListNode* del = left;
        prev->next = left->next;
        delete del;

        return head;
    }


    ListNode* removeNthFromEnd_1(ListNode* head, int n)
    {
        if(head == NULL)
            return NULL;

        if(head->next == NULL && n == 1)
            return NULL;

        /* two pointer approach left and right gap will be n */
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* left = dummy;
        ListNode* right = head;
        for(int i=0; i<n; i++)
        {
            if(right == NULL)
                return NULL;
            right = right->next;
        }

        /* iterate to reach (n-1)th node */
        while(right)
        {
            left = left->next;
            right = right->next;
        }

        /* delete the node */
        ListNode* del = left->next;
        if(del == head) // Important !!!
            return head->next;
        left->next = left->next->next;
        del = NULL;
        delete dummy;
        dummy = NULL;

        return head;
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
    
    for(int i=2; i<3; i++)
    {
        struct ListNode* temp = new ListNode(i);
        node_ptr->next = temp;
        node_ptr = temp;
    }
    
    cout << "list: ";
    print_list(&head);
    
    Solution sol;
    ListNode* res = sol.removeNthFromEnd(&head, 2);
    print_list(res);

    cout << endl << "La fin!" << endl;
}
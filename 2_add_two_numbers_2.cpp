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

void print_list(struct ListNode* head)
{
    while(head)
    {
        cout << head->val << "-";
        head = head->next;
    }
    cout << endl;
}

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* result = new ListNode(0);
        ListNode* head = result;
        int carry = 0;
        int sum = 0;
        int l1val = 0, l2val = 0;
        while(l1 || l2)
        {
            l1val = (l1)? l1->val : 0;
            l2val = (l2)? l2->val : 0;

            sum = l1val + l2val + carry;
            if(sum > 9)
            {
                carry = 1;
                sum = sum % 10;
            }
            else
                carry = 0;
            ListNode* temp = new ListNode(sum);
            result->next = temp;
            result = temp;
            if(l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if(carry)
        {
            ListNode* temp = new ListNode(1);
            result->next = temp;
        }
        return head->next;
    }
};

int main()
{
    struct ListNode l1(1);
    struct ListNode l2(6);
    struct ListNode* l1_p = &l1;
    struct ListNode* l2_p = &l2;

    
    for(int i=2; i<5; i++)
    {
        struct ListNode* temp1 = new ListNode(i);
        struct ListNode* temp2 = new ListNode(i+2);
        l1_p->next = temp1;
        l1_p = temp1;
        l2_p->next = temp2;
        l2_p = temp2;
    }
    
    print_list(&l1);
    print_list(&l2);

    Solution sol;
    ListNode* res = sol.addTwoNumbers(&l1, &l2);
    print_list(res);

    cout << endl << "La fin!" << endl;
}
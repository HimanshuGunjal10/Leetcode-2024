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
        ListNode* head = new ListNode(0);
        ListNode* node = head;
        int sum = 0;
        int carry = 0;
        int digit = 0;
        while(l1 && l2)
        {
            sum = carry + l1->val + l2->val;
            carry = sum/10;
            digit = sum % 10;
            node->next = new ListNode(digit);
            node = node->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            sum = carry + l1->val;
            carry = sum/10;
            digit = sum%10;
            node->next = new ListNode(digit);
            node = node->next;
            l1 = l1->next;
        }
        while(l2)
        {
            sum = carry + l2->val;
            carry = sum/10;
            digit = sum%10;
            node->next = new ListNode(digit);
            node = node->next;
            l2 = l2->next;
        }
        if(carry)
        {
            node->next = new ListNode(carry);
        }
        ListNode* resultHead = head->next;
        delete head;
        return resultHead;
    }
/*
while(l1&&l2) then while(l1) while(l2) loops. carry = sum/10, digit = sum%10. check carry at the end. O(n) O(1)
*/



    ListNode* addTwoNumbers_1(ListNode* l1, ListNode* l2)
    {
        /* Note: check my old LeetCode solution which is better
        https://leetcode.com/problems/add-two-numbers/submissions/238445933/ */
        
        ListNode* result = new ListNode(0);
        ListNode* head = result;
        int carry = 0;
        int sum = 0;
        while(l1 && l2)
        {
            sum = l1->val + l2->val + carry;
            if(sum>9)
            {
                carry = 1;
                sum = sum % 10;
            }
            else
                carry = 0;
            ListNode* temp = new ListNode(sum);
            result->next = temp;
            result = temp;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            sum = l1->val + carry;
            if(sum>9)
            {
                carry = 1;
                sum = sum % 10;
            }
            else
                carry = 0;
            ListNode* temp = new ListNode(sum);
            result->next = temp;
            result = temp;
            l1 = l1->next;
        }
        while(l2)
        {
            sum = l1->val + carry;
            if(sum>9)
            {
                carry = 1;
                sum = sum % 10;
            }
            else
                carry = 0;
            ListNode* temp = new ListNode(sum);
            result->next = temp;
            result = temp;
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
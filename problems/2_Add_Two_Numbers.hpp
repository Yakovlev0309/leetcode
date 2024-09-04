#include "../leetcode.h"
#include <initializer_list>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void printList(ListNode* head)
{
    cout << "ListNode:" << endl;
    while (head != nullptr)
    {
        cout << head->val << endl;
        head = head->next;
    }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    int overflow = 0;
    int result;
    ListNode* l = new ListNode();
    ListNode* current = l;
    while (l1 || l2)
    {
        if (l1)
        {
            if (l2)
            {
                result = l1->val + l2->val + overflow;
                if (result < 10)
                {
                    current->next = new ListNode(result);
                    overflow = 0;
                }
                else
                {
                    current->next = new ListNode(result - 10);
                    overflow = 1;
                }
            }
            else
            {
                result = l1->val + overflow;
                if (result < 10)
                {
                    current->next = new ListNode(result);
                    overflow = 0;
                }
                else
                {
                    current->next = new ListNode(result - 10);
                    overflow = 1;
                }
            }
        }
        else
        {
            if (l2)
            {
                result = l2->val + overflow;
                if (result < 10)
                {
                    current->next = new ListNode(result);
                    overflow = 0;
                }
                else
                {
                    current->next = new ListNode(result - 10);
                    overflow = 1;
                }
            }
        }
        if (l1)
        {
            l1 = l1->next;
        }
        if (l2)
        {
            l2 = l2->next;
        }
        current = current->next;
    }
    if (overflow == 1)
    {
        current->next = new ListNode(1);
    }
    return l->next;
}

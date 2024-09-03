#include "../leetcode.h"

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

ListNode* swapPairs(ListNode* head)
{
    ListNode* prehead = new ListNode(0, head);
    ListNode* current = prehead;
    ListNode* left, * right;
    int count = 0;
    while (current != nullptr)
    {
        if (count % 2 == 0)
        {
            if (current->next != nullptr)
            {
                if (current->next->next != nullptr)
                {
                    left = current->next;
                    right = current->next->next;

                    current->next = right;
                    left->next = right->next;
                    right->next = left;
                }
            }
        }
        current = current->next;
        count++;
    }
    return prehead->next;
}

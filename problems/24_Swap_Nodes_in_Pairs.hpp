#include "../leetcode.h"
#include "../src/list_node.hpp"

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

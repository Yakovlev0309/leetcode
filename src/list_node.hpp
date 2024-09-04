#include <iostream>

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
    std::cout << "ListNode:" << std::endl;
    while (head != nullptr)
    {
        std::cout << head->val << std::endl;
        head = head->next;
    }
}

#include "../leetcode.h"
#include "../src/list_node.hpp"

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    std::vector<int> vec;

    ListNode* current;
    for (ListNode* list : lists)
    {
        current = list;
        while (current != nullptr)
        {
            vec.push_back(current->val);
            current = current->next;
        }
    }

    std::sort(vec.begin(), vec.end());

    if (vec.size() > 0)
    {
        ListNode* result = new ListNode(vec[0]);
        ListNode* current = result;
        for (int i = 1; i < vec.size(); ++i)
        {
            current->next = new ListNode(vec[i]);
            current = current->next;
        }
        return result;
    }
    return nullptr;
}

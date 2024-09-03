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

// ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
// {
//     std::vector<int> vec;

//     while (list1 != nullptr)
//     {
//         vec.push_back(list1->val);
//         list1 = list1->next;
//     }
//     while (list2 != nullptr)
//     {
//         vec.push_back(list2->val);
//         list2 = list2->next;
//     }

//     std::sort(vec.begin(), vec.end());

//     if (vec.size() > 0)
//     {
//         ListNode* result = new ListNode(vec[0]);
//         ListNode* current = result;
//         for (int i = 1; i < vec.size(); ++i)
//         {
//             current->next = new ListNode(vec[i]);
//             current = current->next;
//         }
//         return result;
//     }
//     return nullptr;
// }

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    ListNode* result = nullptr;
    if (list1 != nullptr)
    {
        if (list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                result = new ListNode(list1->val);
                list1 = list1->next;
            }
            else
            {
                result = new ListNode(list2->val);
                list2 = list2->next;
            }
        }
        else
        {
            result = new ListNode(list1->val);
            list1 = list1->next;
        }
    }
    else
    {
        if (list2 != nullptr)
        {
            result = new ListNode(list2->val);
            list2 = list2->next;
        }
        else
        {
            return nullptr;
        }
    }
    ListNode* current = result;
    while (list1 != nullptr || list2 != nullptr)
    {
        if (list1 != nullptr)
        {
            if (list2 != nullptr)
            {
                if (list1->val == list2->val)
                {
                    current->next = new ListNode(list1->val);
                    current = current->next;
                    list1 = list1->next;

                    current->next = new ListNode(list2->val);
                    current = current->next;
                    list2 = list2->next;
                }
                else if (list1->val < list2->val)
                {
                    current->next = new ListNode(list1->val);
                    current = current->next;
                    list1 = list1->next;
                }
                else if (list1->val > list2->val)
                {
                    current->next = new ListNode(list2->val);
                    current = current->next;
                    list2 = list2->next;
                }
            }
            else
            {
                current->next = new ListNode(list1->val);
                current = current->next;
                list1 = list1->next;
            }
        }
        else
        {
            current->next = new ListNode(list2->val);
            current = current->next;
            list2 = list2->next;
        }
    }
    return result;
}

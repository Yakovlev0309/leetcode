#include "../leetcode.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
    
void printList(ListNode *head)
{
    cout << "ListNode:" << endl;
    while (head != nullptr)
    {
        cout << head->val << endl;
        head = head->next;
    }
}

void reorderList(ListNode *head)
{
    ListNode *h2 = head;
    vector<int> vec;
    while (head != nullptr)
    {
        vec.push_back(head->val);
        head = head->next;
    }

    cout << "vector<int>:" << endl;
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << endl;
    }

    head = h2;

    int index = -1;
    int len = vec.size();
    int add = len - 1;
    while (head != nullptr)
    {
        index++;
        if (index % 2 == 1)
        {
            ListNode *next = head->next;
            head = new ListNode(vec[add]);
            head->next = next;
            add--;
        }
        head = head->next;
    }
}

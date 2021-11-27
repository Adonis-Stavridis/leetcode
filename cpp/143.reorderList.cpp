using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  void reorderList(ListNode *head)
  {
    if (!head->next || !head->next->next)
      return;

    ListNode *slow = head->next;
    ListNode *fast = head->next->next;
    while (slow->next && fast->next && fast->next->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *tmp = slow;
    slow = slow->next;
    tmp->next = nullptr;

    ListNode *prev = slow;
    ListNode *next = slow->next;
    prev->next = nullptr;
    while (next)
    {
      ListNode *tmp = next;
      next = next->next;
      tmp->next = prev;
      prev = tmp;
    }

    ListNode *index = head;
    ListNode *l1 = head->next;
    ListNode *l2 = prev;
    while (l1 || l2)
    {
      if (l2)
      {
        index->next = l2;
        l2 = l2->next;
        index = index->next;
      }
      if (l1)
      {
        index->next = l1;
        l1 = l1->next;
        index = index->next;
      }
    }
  }
};

// You are given the head of a singly linked-list. The list can be represented
// as:

// L0 → L1 → … → Ln - 1 → Ln

// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

// You may not modify the values in the list's nodes. Only nodes themselves may
// be changed.

// Example 1:

// Input: head = [1,2,3,4]
// Output: [1,4,2,3]

// Example 2:

// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]

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

using namespace std;

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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    ListNode *sol = new ListNode();
    ListNode *tail = sol;

    if (!l1)
      return l2;
    if (!l2)
      return l1;

    ListNode *l1Temp = l1;
    ListNode *l2Temp = l2;
    while (l1Temp && l2Temp)
    {
      if (l1Temp->val <= l2Temp->val)
      {
        tail->next = new ListNode(l1Temp->val);
        tail = tail->next;
        l1Temp = l1Temp->next;
      }
      else
      {
        tail->next = new ListNode(l2Temp->val);
        tail = tail->next;
        l2Temp = l2Temp->next;
      }
    }

    while (l1Temp)
    {
      tail->next = new ListNode(l1Temp->val);
      tail = tail->next;
      l1Temp = l1Temp->next;
    }

    while (l2Temp)
    {
      tail->next = new ListNode(l2Temp->val);
      tail = tail->next;
      l2Temp = l2Temp->next;
    }

    return sol->next;
  }
};

// Merge two sorted linked lists and return it as a sorted list. The list
// should be made by splicing together the nodes of the first two lists.

// Example 1:

// Input: l1 = [1,2,4], l2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:

// Input: l1 = [], l2 = []
// Output: []

// Example 3:

// Input: l1 = [], l2 = [0]
// Output: [0]

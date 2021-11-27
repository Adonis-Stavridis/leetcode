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
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *before = head;
    ListNode *after = head;

    while (n > 0 && after)
    {
      after = after->next;
      --n;
    }

    if (!after)
      return head->next;

    while (after->next)
    {
      after = after->next;
      before = before->next;
    }

    before->next = before->next->next;

    return head;
  }
};

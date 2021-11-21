#include <stack>

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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode *l1Temp = l1;
    ListNode *l2Temp = l2;
    int remaining = 0;

    ListNode *sol = new ListNode();
    ListNode *tail = sol;

    while (l1Temp || l2Temp || remaining)
    {
      int l1TempVal = (l1Temp ? l1Temp->val : 0);
      int l2TempVal = (l2Temp ? l2Temp->val : 0);
      int sum = l1TempVal + l2TempVal + remaining;
      int toAdd = sum % 10;
      remaining = sum / 10;
      tail->next = new ListNode(toAdd);
      tail = tail->next;
      l1Temp = (l1Temp ? l1Temp->next : nullptr);
      l2Temp = (l2Temp ? l2Temp->next : nullptr);
    }

    return sol->next;
  }
};

// class Solution
// {
// public:
//   ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
//   {
//     if (!l1)
//       return l2;
//     if (!l2)
//       return l1;

//     ListNode *sol = new ListNode();
//     ListNode *tail = sol;

//     ListNode *l1Temp = l1;
//     ListNode *l2Temp = l2;
//     int remaining = 0;

//     while (l1Temp && l2Temp)
//     {
//       int sum = l1Temp->val + l2Temp->val + remaining;
//       int toAdd = sum % 10;
//       remaining = sum / 10;
//       tail->next = new ListNode(toAdd);
//       tail = tail->next;
//       l1Temp = l1Temp->next;
//       l2Temp = l2Temp->next;
//     }

//     while (l1Temp)
//     {
//       int sum = l1Temp->val + remaining;
//       int toAdd = sum % 10;
//       remaining = sum / 10;
//       tail->next = new ListNode(toAdd);
//       tail = tail->next;
//       l1Temp = l1Temp->next;
//     }

//     while (l2Temp)
//     {
//       int sum = l2Temp->val + remaining;
//       int toAdd = sum % 10;
//       remaining = sum / 10;
//       tail->next = new ListNode(toAdd);
//       tail = tail->next;
//       l2Temp = l2Temp->next;
//     }

//     while (remaining > 0)
//     {
//       int toAdd = remaining % 10;
//       remaining = remaining / 10;
//       tail->next = new ListNode(toAdd);
//       tail = tail->next;
//     }

//     return sol->next;
//   }
// };

// You are given two non-empty linked lists representing two non-negative
// integers. The digits are stored in reverse order, and each of their nodes
// contains a single digit. Add the two numbers and return the sum as a linked
// list.

// You may assume the two numbers do not contain any leading zero, except the
// number 0 itself.

// Example 1:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]

// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

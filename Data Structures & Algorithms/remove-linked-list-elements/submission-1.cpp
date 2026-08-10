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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
       ListNode * dummy = new ListNode(0,head);

       ListNode * cur = head;
       ListNode * prev = dummy;
       ListNode * nxt;

       while(cur != nullptr)
       {
        nxt = cur->next;
        if(cur->val == val)
        {
            prev->next = nxt;
        }
        else
        {
            prev = prev->next;
        }
        cur = cur->next;
       } 
        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};
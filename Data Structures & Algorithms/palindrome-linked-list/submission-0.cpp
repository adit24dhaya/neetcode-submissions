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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode *p1, *p2;

        //finding the middle

        while(fast != nullptr and fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        p1 = head;
        //reversing the second list
        ListNode* second = slow->next;
        ListNode* previous = nullptr;
        ListNode* temp;
        
        while(second!= nullptr)
        {
            temp = second->next;
            second->next = previous;
            previous = second;
            second = temp;
        }
        p2 = previous;
        
        while(p2 != nullptr){
        if (p1->val == p2->val)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->val != p2->val)
        {
            return false;
        }
        }
        return true;
    }
};
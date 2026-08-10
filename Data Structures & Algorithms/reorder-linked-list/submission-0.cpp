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
    void reorderList(ListNode* head) {
        //find middle
        //reverse the second list
        //merge the list


        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=nullptr and fast->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;

        //reversing the second list

        ListNode* temp;
        ListNode* previous = nullptr;

        while(second!=nullptr)
        {
            temp = second->next;
            second->next = previous;
            previous = second;
            second = temp;
        }

        ListNode* first = head;
        second = previous;
        ListNode *temp1, *temp2;

        while(second!=nullptr)
        {
            temp1 = first->next;
            temp2 = second->next;
            first->next = second;
            second->next = temp1;

            //update first and second
            first = temp1;
            second = temp2;
        }
    }
};

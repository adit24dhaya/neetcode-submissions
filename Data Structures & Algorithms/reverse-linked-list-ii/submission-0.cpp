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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode * leftPrevious = &dummy;
        ListNode * current = head;

        //moving previous and current until left
        for(int i = 0; i <left-1; i++)
        {
            leftPrevious = current;
            current = current->next;
        }

        //reversing the list
        ListNode* previous = nullptr;
        for(int i =0; i < right-left+1; i++)
        {
            ListNode * tempNext = current->next;
            current->next = previous;
            previous = current;
            current = tempNext;
        }
        //fixing the leftPrevious->next and last node in the list
        leftPrevious ->next ->next = current;
        leftPrevious ->next = previous;

        return dummy.next;  
    }
};
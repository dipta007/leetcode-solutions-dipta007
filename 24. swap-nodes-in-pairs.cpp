/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode * swapPairs(ListNode * head) {
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode * curr = head;
        ListNode * prev = dummy;
        while(curr != NULL && (curr)->next != NULL)
        {
            ListNode* tmp1 = curr;
            ListNode* tmp2 = tmp1->next;
            
            tmp1->next = tmp2->next;
            tmp2->next = tmp1;
            
            prev->next = tmp2;
            prev = tmp1;
            curr = (tmp1->next);
        }
        return dummy->next;
    }
};
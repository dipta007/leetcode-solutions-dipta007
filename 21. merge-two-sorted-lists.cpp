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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        
        if(cur1 == NULL && cur2 == NULL) return NULL;
        
        ListNode *cur, *ret;
        int f = 1;
        while(cur1 != NULL || cur2 != NULL)
        {
            if(cur1 != NULL && (cur2==NULL || cur2->val > cur1->val))
            {
                if(f)
                {
                    cur = new ListNode(cur1->val);
                    f = 0;
                    ret = cur;
                }
                else
                {
                    cur->next = new ListNode(cur1->val);
                    cur = cur->next;
                }
                cur1 = cur1->next;
            }
            else
            {
                if(f)
                {
                    cur = new ListNode(cur2->val);
                    f = 0;
                    ret = cur;
                }
                else
                {
                    cur->next = new ListNode(cur2->val);
                    cur = cur->next;
                }
                cur2 = cur2->next;
            }
        }
        return ret;
    }
};
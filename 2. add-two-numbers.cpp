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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *l;
        ListNode *ret;
        int flg = 1;
        int re = 0;
        
        int len1 = 0, len2 = 0;
        
        ListNode *root = l1;
        while(root != NULL)
        {
            len1 ++;
            root = root -> next;
        }
        
        root = l2;
        while(root != NULL)
        {
            len2 ++;
            root = root -> next;
        }
        
        if(len1 > len2)
        {
            while(l1 != NULL && len2!=0)
            {
                int now = l1->val + l2->val + re;
                if(flg)
                    l = new ListNode(now%10);
                else
                {
                    l->next = new ListNode(now%10);
                    l = l->next;
                }
                if(flg)
                {
                    ret = l;
                    flg = 0;
                }
                re = now/10;
                l1 = l1->next;
                l2 = l2->next;
                len1--;
                len2--;
            }         
            while(len1)
            {
                int now = re + l1->val;
                l->next = new ListNode(now%10);
                re = now/10;
                l=l->next;
                l1=l1->next;
                len1--;
            }
            if(re)
            {
                l->next = new ListNode(re);
                l = l->next;
            }
        }
        else
        {   
            while(l2!=NULL && len1!=0)
            {
                int now = l1->val + l2->val + re;
                if(flg)
                    l = new ListNode(now%10);
                else
                {
                    l->next = new ListNode(now%10);
                    l = l->next;
                }
                if(flg)
                {
                    //ret = new ListNode(0);
                    ret = (l);
                    flg = 0;
                }
                re = now/10;
                l1 = l1->next;
                l2 = l2->next;
                len1--;
                len2--;
            }    
            while(len2)
            {
                int now = re + l2->val;
                l->next = new ListNode(now%10);
                re = now/10;
                l=l->next;
                l2=l2->next;
                len2--;
            }
            if(re)
            {
                l->next = new ListNode(re);
                l = l->next;
            }
        }
        
        return ret;
    }
};
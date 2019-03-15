/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
    int call(ListNode *l1, ListNode *l2)
    {
        if (l1 && l2)
        {
            int carry = call(l1->next, l2->next);

            int tmp = l1->val + l2->val + carry;

            cout << tmp << endl;

            l1->val = tmp % 10;
            return tmp / 10;
        }
        return 0;
    }

  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *curr = l1;
        int len1 = 0, len2 = 0;
        while (curr)
        {
            curr = curr->next;
            len1++;
        }

        curr = l2;
        while (curr)
        {
            curr = curr->next;
            len2++;
        }

        if (len1 < len2)
        {
            swap(l1, l2);
            swap(len1, len2);
        }

        ListNode *l22 = l2;
        while (len2 < len1)
        {
            ListNode *tmp = new ListNode(0);
            tmp->next = l22;
            l22 = tmp;
            len2++;
        }

        int cc = call(l1, l22);
        if (cc)
        {
            ListNode *tmp = new ListNode(cc);
            tmp->next = l1;
            l1 = tmp;
        }

        return l1;
    }
};
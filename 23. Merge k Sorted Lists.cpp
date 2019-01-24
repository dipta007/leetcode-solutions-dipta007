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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *root = new ListNode(0);
        ListNode *curr = root;
        
        priority_queue < pair<int, int>, vector <pair<int,int> >, greater<pair<int, int> > > pq;
        for(int i=0; i<lists.size(); i++) {
            if(lists[i]) {
                pq.push(make_pair(lists[i]->val, i));
            }
        }
        
        while(!pq.empty()) {
            pair <int, int> p = pq.top(); pq.pop();
            
            curr->next = new ListNode(p.first);
            curr = curr->next;
            
            // cout << p.first << endl;
            lists[p.second] = lists[p.second]->next;
            if(lists[p.second]) {
                pq.push(make_pair(lists[p.second]->val, p.second));    
            }
        }
        
        return root->next;
    }
};
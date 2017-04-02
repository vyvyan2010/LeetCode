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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = new ListNode(0);
        
        pre->next = head;
        ListNode *start = pre->next;
        
        if(NULL == start)
        {
            return NULL;
        }
        
        while(start->next != NULL)
        {
            ListNode *p = start->next;
            start->next = p->next;
            p->next = pre->next;
            pre->next = p;
        }
        
        return pre->next; 
    }
};

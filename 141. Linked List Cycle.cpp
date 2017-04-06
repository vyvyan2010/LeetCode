class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return False;
        
        ListNode *l = head;
        ListNode *p = head;
        
        while(p->next != NULL && p->next->next != NULL)
        {
            l = l->next;
            p = p->next->next;
            if(p->next == l)
            {
                break;
            }
        }
        
        if(p->next == NULL || p->next->next == NULL)
        {
            return False;
        }
        
        return True;
    }
};
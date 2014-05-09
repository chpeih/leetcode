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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
            return NULL;
        ListNode * pFast = head,*pSlow = head;
        while(pFast!=NULL){
            pFast = pFast->next;
            if(pFast==NULL)
                return NULL;
            pFast = pFast->next;
            pSlow = pSlow->next;
            if(pFast == pSlow){
                break;
            }
        }
        if (pFast == NULL)
            return NULL;
        pFast = head;
        while(pFast!=pSlow){
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
        return pFast;
        
    }
};

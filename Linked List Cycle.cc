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
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;
        ListNode *pFast = head, *pSlow = head;
        while(pFast != NULL){
            pFast = pFast->next;
            if(pFast == NULL)
                return false;
            pFast = pFast->next;
            pSlow = pSlow->next;
            if(pFast == pSlow)return true;
        }
        return pFast!=NULL;
    }
};

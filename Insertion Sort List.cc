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
    ListNode *insertionSortList(ListNode *head) {
         if (head==NULL ||head->next==NULL)return head;
         ListNode* pNewHead = head;
         head = head->next;
         pNewHead->next = NULL;
         while(head){
             ListNode* cur = pNewHead,*pre = NULL;
             while(cur && cur->val<=head->val){
                 pre = cur;
                 cur = cur->next;
             }
             if(pre==NULL){
                 ListNode* tmp = head;
                 head = head->next;
                 tmp->next = pNewHead;
                 pNewHead = tmp;
             }else{
                 ListNode *tmp = head;
                 head = head->next;
                 pre->next = tmp;
                 tmp->next = cur;
             }
         }
         return pNewHead;
    }
};

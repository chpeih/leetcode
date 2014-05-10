/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL)return head;
        RandomListNode *cur = head;
        while(cur!=NULL){
            RandomListNode *node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        cur = head;
        while(cur!=NULL){
            if(cur->random==NULL)cur->next->random = NULL;
            else
                cur->next->random = cur->random->next;
            cur = cur->next->next;    
        }
        RandomListNode *newhead = head->next,*newcur = head->next;
        cur = head;
        while(cur!=NULL){
            newcur = cur->next;
            cur->next = newcur->next;
            if(cur->next==NULL)newcur->next = NULL;
            else
                newcur->next = cur->next->next;
            cur = cur->next;
        }
        return newhead;
    }
};

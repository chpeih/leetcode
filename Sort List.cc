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
    ListNode *sortList(ListNode *head) {
		if(head==NULL || head->next==NULL)return head;
		ListNode *slow = head,*fast = head;
		while(fast!=NULL){
			fast = fast->next;
			if(fast==NULL)break;
			fast = fast->next;
			if(fast==NULL)break;
			slow = slow->next;
		}
		fast = slow->next;
		slow->next = NULL;
		fast = sortList(fast);
		slow = sortList(head);
		if(slow->val<fast->val){
			head = slow;
			slow = slow->next;
		}else{
			head = fast;
			fast = fast->next;
		}
		ListNode* cur = head;
		while(slow!=NULL &&fast!=NULL){
			if(slow->val<fast->val){
				cur->next = slow;
				slow = slow->next;
			}else{
				cur->next = fast;
				fast = fast->next;
			}
			cur = cur->next;
		}
		while(slow!=NULL){
			cur->next = slow;
			slow = slow->next;
			cur = cur->next;
		}
		while(fast!=NULL){
			cur->next = fast;
			fast = fast->next;
			cur = cur->next;
		}
		return head;
	}
};

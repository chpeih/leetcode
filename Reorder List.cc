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
    void reorderList(ListNode *head) {
       if(head==NULL ||head->next==NULL)return head;
	   ListNode *fast = head, *slow = head;
	   while( fast!=NULL){
			fast = fast->next;
			if(fast==NULL)break;
			fast = fast->next;
			if(fast==NULL)break;
			slow = slow->next;
	   }
		mid = slow->next;
		slow->next = NULL;
		mid = revertList(mid);
		while(head!=NULL && mid!=NULL){
			if (fast==NULL){
				fast = head;
			}else
				fast->next = head,fast = head;
			head = head->next;
			fast->next = mid;
			mid = mid->next;
			fast = fast->next;
		}
		if (head!=NULL)fast->next = head;

    }
private:
	ListNode* revertList(ListNode *head){
		ListNode* pre = NULL,*cur = head;
		while(cur!=NULL){
			ListNode *tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}
		return pre;
	}
};

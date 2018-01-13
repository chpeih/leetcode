
struct cmp{
	bool operator()(ListNode *a, ListNode *b)
	{
		return a->val > b->val;
	}
}

class Solution {
	public:
		ListNode* mergeKLists(vector<ListNode*> &lists) {
			priority_queue<ListNode*, vector<ListNode*>, cmp> qe;
			for(int i = 0; i<lists.size();i++)
			{
				if(lists[i] == NULL)continue;
				qe.push(list[i]);
			}
			ListNode *head = NULL, *cur = NULL;
			while(!qe.empty())
			{
				ListNode *p = qe.front();
				qe.pop();
				if(head == NULL) {
					head = cur = p;
				} else {
					cur->next = p;
					cur = p;
				}

				if(p->next != NULL)
					qe.push(p->next);

			}
			if(cur != NULL)cur->next = NULL;
			return head;
		}
}

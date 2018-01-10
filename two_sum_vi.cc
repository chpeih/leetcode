/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *         */
class Solution {
public:
	bool findTarget(TreeNode* root, int k) {
		if(root == NULL) return false;
		vector<int> arr;
		dfs(root, arr);		
		int i = 0, j = arr.size() - 1;
		while(i<j)
		{
			int sum = arr[i] + arr[j] - k;
			if(sum == 0) return true;
			else if(sum < 0) i++;
			else
				j--;

		}
		return false;
	}

	void dfs(TreeNode *root, vector<int> &arr)
	{
		if(root == NULL) return;
		dfs(root->left);
		arr.push_back(root->val);
		dfs(root->right);
	}
};

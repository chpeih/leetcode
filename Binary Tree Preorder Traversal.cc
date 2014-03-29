/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        if(root==NULL)return ans;
        solve(ans,root);
        return ans;
    }
private:
    void solve(vector<int > &ans,const TreeNode* root){
        ans.push_back(root->val);
        if(root->left)solve(ans,root->left);
        if(root->right)solve(ans,root->right);
    }
};
///non recursive
class Solution{
	public:
		vector<int>  preorderTraversal(TreeNode *root){
			vector<int> ans;
			if (root ==  NULL)return ans;
			stack<TreeNode *>  st;
			while(!st.empty() || root!=NULL){
				
				while(root != NULL){
					ans.push_back(root->val);
					st.push(root);
					root = root->left;
				}
				if(!st.empty()){
					root = st.top();
					st.pop();
					root = root->right;
				}

			}
			return ans;

		}
};

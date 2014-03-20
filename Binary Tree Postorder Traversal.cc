/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*recursive solution*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
		vector<int> ans;
		if(root==NULL)return ans;
		recursive_solve(root,ans);
		return ans;
    }
private:
	void recursive_solve(const TreeNode *root, vector<int> &ans){
		if (root==NULL)return ;
		recursive_solve(root->left, ans);
		recursive_solve(root->right, ans);
		ans.push_back(root->val);
		return ;
	}
};


/*nonrecursive solution*/
class Solution{
public:
	vector<int>  postorderTraversal(TreeNode *root){
		vector<int > ans;
		if(root==NULL)return ans;
		stack<pair<TreeNode,bool> > st;
		pair<TreeNode*,bool>  p;
		p.first = root;
		p.second = true;

		while(!st.empty() || p.first!=NULL){
			while(p.first!=NULL && p.second==true){
				st.push(p);
				p.first = p.first->left;
			}
			if(p.first!=NULL){
				ans.push_back(p.first->val);
			}
			if(!st.empty()){
				p = st.top();
				st.pop();
				if(p.second==true){
					p.second = false;
					st.push(p);
					p.second = true;
					p.first = p.first->right;
				}
			}else p.first = NULL;
		}
		return ans;
	}
};

/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/

class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		std::queue<TreeNode*> q;
		std::vector<int> result;
        if (root == NULL)
            return result;
		TreeNode* temp = root;
		q.push(root);

		while (!q.empty())
		{
			temp = q.front();

			if (temp->left != NULL)
				q.push(temp->left);
			if (temp->right != NULL)
				q.push(temp->right);

			result.push_back(temp->val);
			q.pop();
		}
		return result;
	}
};


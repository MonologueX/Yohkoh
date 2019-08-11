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
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		TreeNode* root = new TreeNode(pre[0]);
		std::stack<TreeNode*> s;
		s.push(root);
		int size = pre.size();
		TreeNode* cur = root;
		for (int i = 1; i < size; i++)
		{
			cur = s.top();
			auto index = find(vin.begin(), vin.end(), cur->val);
			TreeNode* temp = new TreeNode(pre[i]);

			auto pos = find(vin.begin(), vin.end(), pre[i]);
			if (pos < index)
				cur->left = temp;
			else
			{
				while (s.size() > 1)
				{
					s.pop();
					TreeNode* preNode = s.top();
					index = find(vin.begin(), vin.end(), preNode->val);
					if (pos < index)
					{
						cur->right = temp;
						s.push(temp);
						break;
					}
					cur = preNode;
				}
				if (s.size() == 1)
				{
					s.pop();
					cur->right = temp;
				}
			}
			if (i != size-1)
				s.push(temp);
		}
		return root;
	}
};

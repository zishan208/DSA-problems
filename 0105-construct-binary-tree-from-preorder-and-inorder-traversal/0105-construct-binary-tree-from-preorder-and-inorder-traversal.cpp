/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */class Solution {
private:
    TreeNode* make_tree(vector<int>& preorder, vector<int>& inorder, int& index) {
        if (inorder.empty()) return nullptr;

        TreeNode* current = new TreeNode(preorder[index]);

        auto pos = find(inorder.begin(), inorder.end(), preorder[index]);
        int rootIndex = pos - inorder.begin();

        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex);
        vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());

        index++;
        current->left = make_tree(preorder, leftInorder, index);
        current->right = make_tree(preorder, rightInorder, index);

        return current;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() != inorder.size() || preorder.empty()) return nullptr;
        int index = 0;
        return make_tree(preorder, inorder, index);
    }
};

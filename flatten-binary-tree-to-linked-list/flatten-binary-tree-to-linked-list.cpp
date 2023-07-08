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
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL || (root->left == NULL and root->right == NULL)) return;

        //flattening the left subtree and attaching it to the right
        TreeNode* temp = root->right;
        flatten(root->left);
        root->right = root->left;
        root->left = NULL;

        //attaching the right subtree to the end of the flattened left subtree and repeating the process
        TreeNode* treeEnd = root;
        while(treeEnd->right != NULL) treeEnd = treeEnd->right;
        flatten(temp);
        treeEnd->right = temp;

    }
};
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
    int ans = 0;

    // Helper function to compute the sum of a subtree and check if it's a valid BST
    pair<int, bool> isBSTUtil(TreeNode* root) {
        if (root == nullptr)
            return {0, true};

        pair<int, bool> left = isBSTUtil(root->left);
        pair<int, bool> right = isBSTUtil(root->right);

        int total_sum = left.first + right.first + root->val;
        bool is_bst = left.second && right.second &&
                      (root->left == nullptr || root->val > getMaxValue(root->left)) &&
                      (root->right == nullptr || root->val < getMinValue(root->right));

        ans = max(ans, is_bst ? total_sum : ans);

        return {total_sum, is_bst};
    }

    int getMaxValue(TreeNode* root) {
        while (root->right != nullptr)
            root = root->right;
        return root->val;
    }

    int getMinValue(TreeNode* root) {
        while (root->left != nullptr)
            root = root->left;
        return root->val;
    }

    int maxSumBST(TreeNode* root) {
        isBSTUtil(root);
        return ans;
    }
};

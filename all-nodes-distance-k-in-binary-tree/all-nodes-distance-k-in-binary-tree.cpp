/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<int> ans;
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_set<TreeNode*>visit;
    
    void findparent(TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left){
            parent[root->left]=root;
            findparent(root->left);
        }
        if(root->right){
            parent[root->right]=root;
            findparent(root->right);
        }
    }
    
    void dfs(TreeNode* root, int K){
        if(root==NULL){
            return;
        }
        if(visit.count(root)>0){
            return;
        }
        visit.insert(root);
        if(K==0){
            ans.push_back(root->val);
            return;
        }
        dfs(root->left, K-1);
        dfs(root->right, K-1);
        dfs(parent[root], K-1); //to go up this is what i was missing
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL){
            return ans;
        }
        findparent(root);
        dfs(target, k);
        return ans;
    }
};
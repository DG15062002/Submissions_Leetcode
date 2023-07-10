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
int count =0;    
void levelOrderTraversal(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* temp= q.front();
       
        q.pop();
        if(temp==NULL){//previous level has been traversed
            count++;
        if(!q.empty()){//queue still has some child nodes
        q.push(NULL);
        }
        }
        else
        {
            if(temp->left==NULL && temp->right==NULL)
                return;
            if(temp ->left){
            q.push(temp->left);
        }
        if(temp ->right){
            q.push(temp->right);
        }
        }
        }
    }
    
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        levelOrderTraversal(root);
        return count+1;
        
    }
};
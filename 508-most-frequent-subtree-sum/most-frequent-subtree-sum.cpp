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
map<int,int> mp;
int dfs(TreeNode* node, vector<int>subtree_sums){
    if (node== NULL)
        return 0;
    int left_sum = dfs(node->left, subtree_sums);
    int right_sum = dfs(node->right, subtree_sums);
    int total_sum = left_sum + right_sum + node->val;
    mp[total_sum]++;
    subtree_sums.push_back(total_sum);
    return total_sum;
}
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        vector<int> subtree_sums;
        dfs(root,subtree_sums);
        int maxfreq = 1;
        for(auto i = mp.begin(); i != mp.end(); i++){
            maxfreq = max(maxfreq,i->second);
        }
        for(auto i = mp.begin(); i != mp.end(); i++){
            if(i->second == maxfreq)
            ans.push_back(i->first);
        }
        return ans;
    }
};
// def dfs(node, subtree_sums):
//     if not node:
//         return 0

//     left_sum = dfs(node.left, subtree_sums)
//     right_sum = dfs(node.right, subtree_sums)
//     total_sum = left_sum + right_sum + node.val

//     subtree_sums.add(total_sum)
//     return total_sum

// def find_subtree_sums(root):
//     subtree_sums = set()
//     dfs(root, subtree_sums)
//     return subtree_sums
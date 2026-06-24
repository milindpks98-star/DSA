/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

    
 bool checksum(struct TreeNode* root,int sum,int targetSum)
 {
   if(root==NULL)return false;
   sum+=root->val;
   if(root->left==NULL && root->right==NULL)
   return targetSum==sum?true:false;

    return checksum(root->left,sum,targetSum) || checksum(root->right,sum,targetSum);
    
    

}
bool hasPathSum(struct TreeNode* root, int targetSum) {

    
    
    return checksum(root,0,targetSum);
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int deg=0;
 int height(struct TreeNode* root)
 {
    
    if(root==NULL)return 0;
    int x=height(root->left);
    int y=height(root->right);
    if(abs(x-y)>deg)
    deg=abs(x-y);
    if(x>y)
    return x+1;
    else
    return y+1;

   
 }
bool isBalanced(struct TreeNode* root) {
    deg=0;
   height(root);
   if(deg<2)
   return true;
   else
   return false;
    
}
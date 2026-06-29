/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxdiameter=0;
int height(struct TreeNode* root)
{
     
    if(root==NULL)return 0;
    
    int x=height(root->left);
    int y=height(root->right);

    if(x+y>maxdiameter)
    {
        maxdiameter=x+y;
    }
    if(x>y)
    return x+1;
    else
   return y+1;

}
int diameterOfBinaryTree(struct TreeNode* root) {
    maxdiameter=0;
    height(root);
    return maxdiameter;
     
    
}
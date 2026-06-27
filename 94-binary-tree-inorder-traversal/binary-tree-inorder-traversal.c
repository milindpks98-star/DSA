/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int inorder(struct TreeNode *root,int *r,int index)
{
    if(root==NULL)return index;

    index=inorder(root->left,r,index);
    r[index++]=root->val;
    index=inorder(root->right,r,index);
    
    return index;
}


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    
    
    int *result=malloc(100*sizeof(int));
    *returnSize=inorder(root,result,0);
    return result;
}
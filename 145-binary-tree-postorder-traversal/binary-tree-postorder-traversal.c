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
 int postorder(struct TreeNode *root,int *r,int index)
 {
    if(root==NULL)return index;

    index=postorder(root->left,r,index);
    index=postorder(root->right,r,index);
    r[index++]=root->val;
    return index;
 }
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int *result=malloc(100*sizeof(int));
    *returnSize=postorder(root,result,0);

    return result;
}
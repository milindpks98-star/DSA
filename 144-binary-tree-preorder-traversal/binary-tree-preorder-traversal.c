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
 int preorder(struct TreeNode* root,int *r,int index)
 {
    if(root==NULL)return index;

    r[index++]=root->val;
    index=preorder(root->left,r,index);
    index=preorder(root->right,r,index);

    return index;
 }
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    
    int *result=malloc(100*sizeof(int));
    *returnSize=preorder(root,result,0);

    return result;
}
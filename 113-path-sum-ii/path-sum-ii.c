/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 void dfs(struct TreeNode* root,int path[],int targetSum,int index,int sum,int **result, int* returnSize, int** returnColumnSizes)
 {
    if(root==NULL)return;
    
    
    path[index]=root->val;
    index++;
    sum+=root->val;
    
    if(root->left==NULL && root->right==NULL)
    {
        if(targetSum==sum)
        {
        result[*returnSize]=malloc(1000*sizeof(int *));
        memcpy(result[*returnSize],path,index*sizeof(int));
        (*returnColumnSizes)[*returnSize]=index;
        (*returnSize)++;
        
        }return;
    }
    dfs(root->left,path,targetSum,index,sum,result,returnSize,returnColumnSizes);
    dfs(root->right,path,targetSum,index,sum,result,returnSize,returnColumnSizes);

 }
int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {
    int **result=malloc(1000*sizeof(int *));
    *returnColumnSizes=malloc(1000*sizeof(int));
    *returnSize=0;
    int path[1000]={0};
    dfs(root,path,targetSum,0,0,result,returnSize,returnColumnSizes);
    return result;
}
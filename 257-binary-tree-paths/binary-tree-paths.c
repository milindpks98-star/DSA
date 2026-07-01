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

 void  dfs(struct TreeNode* root,char *path,char** result,int *count)
 {
    if(root==NULL)return;
    char temp[1000]="";
    if(strlen(path)==0)
    sprintf(temp,"%d",root->val);
    else
    {
        sprintf(temp,"%s->%d",path,root->val);
    }
    if(root->left==NULL && root->right==NULL)
    {
        result[*count]=malloc(strlen(temp)+1);
        strcpy(result[*count],temp);
        (*count)++;
        return;
    }
    dfs(root->left,temp,result,count);
    dfs(root->right,temp,result,count);
    
 }
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char ** result=malloc(100*sizeof(char *));
    char path[1000]="";
    *returnSize=0;
    dfs(root,path,result,returnSize);
    return result;
}
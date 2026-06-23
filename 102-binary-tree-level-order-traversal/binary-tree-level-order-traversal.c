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
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if(root==NULL)
    {
        *returnSize=0;
        *returnColumnSizes=NULL;
        return NULL;

    }
    int maxsize=2000;
    int **result=(int **)malloc(maxsize*sizeof(int *));
    *returnColumnSizes=(int *)malloc(maxsize*sizeof(int *));

    struct TreeNode **queue=(struct TreeNode **)malloc(maxsize*sizeof(struct TreeNode*));
    int front=0;
    int rear=0;
    int levelcount=0;

    queue[rear++]=root;
    while(front<rear)
    {
        int levelsize=rear-front;

        (*returnColumnSizes)[levelcount]=levelsize;
        result[levelcount]=malloc(levelsize*sizeof(int *));

        for(int i=0;i<levelsize;i++)
        {
            struct TreeNode *cur=queue[front++];
            
            result[levelcount][i]=cur->val;
            if(cur->left!=NULL)
            {
                queue[rear++]=cur->left;
            }
            if(cur->right!=NULL)
            {
                queue[rear++]=cur->right;
            }
        }
        levelcount++;

    }
    *returnSize=levelcount;
    free(queue);
    return result;

}
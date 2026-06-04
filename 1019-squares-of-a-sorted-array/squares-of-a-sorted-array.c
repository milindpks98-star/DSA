/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int *result=calloc(numsSize,sizeof(int));
    for(int i=0;i<numsSize;i++)
    {
        result[i]=nums[i]*nums[i];
    }
   
    int j=1;
    int temp=0;
    for(int i=0;i<numsSize;i++)
    {
        for(j=i+1;j<numsSize;j++)
        {
            if(result[i]>result[j])
            {
                temp=result[i];
                result[i]=result[j];
                result[j]=temp;
            }
        }
    }

    *returnSize=numsSize;
    return result;
}
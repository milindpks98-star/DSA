/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *result=malloc(2*sizeof(int));
    memset(result,-1,2*sizeof(int));
    int left=0;
    int right=numsSize-1;
    //for first occurrence
    while(left<=right)
    {
        int mid=(left+right)/2;
        
        
        
        if(target==nums[mid])
        {
            result[0]=mid;
           right=mid-1;
        }
        if(target<nums[mid])
        {
            right=mid-1;
        }
        if(target>nums[mid])
        {
            left=mid+1;
        }
       
        
    }
//for second occurrence
    left = 0;
    right = numsSize - 1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        
        
        
        if(target==nums[mid])
        {
            result[1]=mid;
           left=mid+1;
        }
        if(target<nums[mid])
        {
            right=mid-1;
        }
        if(target>nums[mid])
        {
            left=mid+1;
        }
       
        
    }
    *returnSize=2;
    return result;
}
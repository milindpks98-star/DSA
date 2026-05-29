/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //////milind////
 int find(int i,int x,int *nums,int size)
{
    for(int j=i+1;j<size;j++)
    {
        if(x==nums[j])
        {
            return j;
        }
    }
    return -1;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *result=(int *)malloc(2*sizeof(int *));
int diff=0,j=0;
    for(int i=0;i<numsSize;i++)
    {    //int sum=0;
         diff=target-nums[i];
          j=find(i,diff,nums,numsSize);
          if(j!=-1)
          {
        //  for(int j=i+1;j<numsSize;j++)
        //  {
        //  sum=nums[i]+nums[j];
        //  if(sum==target)
        //   {
            result[0]=i;
            result[1]=j;
            *returnSize=2;
            return result;
          }
        //   }
        //  }
    }return NULL;



}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//////milind/////
//  int find(int i,int x,int *nums,int size)
// {
//     for(int j=i+1;j<size;j++)
//     {
//         if(x==nums[j])
//         {
//             return j;
//         }
//     }
//     return -1;
// }
struct hashmap {
  int val;
  int index;
};
int * twoSum(int * nums, int numsSize, int target, int * returnSize) {
  int * result = (int * ) malloc(2 * sizeof(int * ));
  struct hashmap * hp = (struct hashmap * ) malloc((numsSize + 2) * sizeof(struct hashmap * ));
  int diff = 0;
  int num;
  for (int i = 0; i < numsSize; i++) { //int sum=0;
    int j = 0;
    num = nums[i];
    diff = target - nums[i];
    //if (num != diff) 
    {
      hp[i].val = nums[i];
      hp[i].index = i;
    }
    while (i > 0 && j < i) {
      if (diff == hp[j].val) {
        result[0] = hp[j].index;
        result[1] = i;
        * returnSize = 2;
        return result;
      }
      j++;
    }

    //   j=find(i,diff,nums,numsSize);
    //   if(j!=-1)
    //   {
    // //  for(int j=i+1;j<numsSize;j++)
    // //  {
    // //  sum=nums[i]+nums[j];
    // //  if(sum==target)
    // //   {
    //     result[0]=i;
    //     result[1]=j;
    //     *returnSize=2;
    //     return result;
    //   }
    // //   }
    // //  }
  }
  return NULL;

}
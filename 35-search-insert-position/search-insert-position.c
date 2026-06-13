int searchInsert(int* nums, int numsSize, int target) {
    int left=0;
    int right=numsSize;

    for(int i=0;i<=numsSize;i++)
    {
        int mid=(left+right)/2;
        if(target==nums[mid])
        {
            return mid;
        }
        if(target<nums[mid])
        {
            right=mid;
        }
        if(target>nums[mid])
        {
            left=mid;
        }
    }return right;
}
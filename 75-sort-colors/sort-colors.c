void sortColors(int* nums, int numsSize) {
    int left=0;int right=numsSize-1;
    int mid=0;
    while(mid<=right)
    {
        if(nums[mid]==0)
        {
            int temp=nums[left];
            nums[left]=nums[mid];
            nums[mid]=temp;
            mid++;
            left++;
        }
        else if(nums[mid]==1)
        {
            mid++;
        }
        else
        {
            int temp=nums[mid];
            nums[mid]=nums[right];
            nums[right]=temp;
            right--;
        }
    }
}
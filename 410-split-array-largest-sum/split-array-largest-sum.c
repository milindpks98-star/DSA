
int splitArray(int* nums, int numsSize, int k) {
    int left=0;
    int right=0;
    
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]>left)
        left=nums[i];

        right+=nums[i];
    }
    int i=0;
    
    while(left<right)
    {
        int sum=0;
        int count=1;
        int mid=left+(right-left)/2;
        for(int i=0;i<numsSize;i++)
        {
            if(sum+nums[i]>mid)
            {
            
                count++;
                sum=nums[i];
            }
            else
            {
                sum+=nums[i];
            }
        }
        if(count<=k)
        {
            right=mid;
        }
        else
        {
            left=mid+1;
        }    
    }
    return left;
}
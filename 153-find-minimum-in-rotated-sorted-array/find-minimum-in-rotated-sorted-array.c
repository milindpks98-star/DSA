int findMin(int* nums, int numsSize) {
    int left=0;
    int right=numsSize-1;
    // int min1=INT_MAX;

    while(left<right)
    {
        int mid=left+(right-left)/2;
        // if(nums[mid]<min1)
        // {
        //     min1=nums[mid];
        // }
        if(nums[mid]>nums[right])
        {
            
            left=mid+1;
        }
        else
        {
            right=mid;
        }
        
    }
    

 
    
    
    return nums[left];
}
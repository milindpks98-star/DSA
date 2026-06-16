int findMin(int* nums, int numsSize) {
    int left=0;
    int right=numsSize-1;
    int min1=INT_MAX;

    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(nums[mid]<min1)
        {
            min1=nums[mid];
        }
        if(nums[mid]<nums[right])
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
        
    }
    

 
    
    
    return min1;
}
int longestOnes(int* nums, int numsSize, int k) {
    int left=0;
    int zerocount=0;
    int maxsize=0;
    for(int right=0;right<numsSize;right++)
    {
        if(nums[right]==0)
        {
            zerocount++;
            
        }
    
        
        while(zerocount>k)
        {
           if(nums[left]==0)
            zerocount--;
            
            left++;
        }
      int size=right-left+1;
       if(size>maxsize)
       maxsize=size;
    }
    return maxsize;
}
//////milind////
//-DBL_MAX: Lowest finite negative value (approx. -1.79 × 10³⁰⁸).
//-DBL_MIN: Closest negative value to zero (normalized).
//0.0: Cente
//DBL_MIN: Closest positive value to zero (normalized).
//DBL_MAX: Highest finite positive value (approx. 1.79 × 10³⁰⁸)



double findMaxAverage(int* nums, int numsSize, int k) {
    int left=0,right=0;
    double sum=0;
    double maxavg=-DBL_MAX;  //
    int len=1;
    for(right=0;right<numsSize;right++)
    {
         sum+=nums[right];
        len=right-left+1;
        if(len==k)
        {
            double avg=sum/k;
            if(avg>maxavg)
            maxavg=avg;

            sum-=nums[left];
            left++;
        }
    }return maxavg;
}
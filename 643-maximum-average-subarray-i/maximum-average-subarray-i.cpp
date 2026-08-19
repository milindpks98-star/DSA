class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0;
        int r=0;int sum=0;int maxsum=0;
        for(int i=0;i<k;i++)
        {
            sum+=nums[i];
        }
        maxsum=sum;
        for(int r=k;r<nums.size();r++)
        {
            sum+=nums[r];
            sum-=nums[r-k];
            maxsum=max(sum,maxsum);
        }
      return  (double)maxsum/k;

    }
};
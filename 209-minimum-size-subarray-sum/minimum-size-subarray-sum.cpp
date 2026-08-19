class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;int sum=0;int minlen=INT_MAX;int len=0;
        for(int right=0;right<nums.size();right++)
        {
            sum+=nums[right];
           while(sum>=target)
            {
                int len=right-left+1;
                sum-=nums[left];
                left++;
                minlen=min(minlen,len);
            }

        }return (minlen==INT_MAX)?0:minlen;
    }
};
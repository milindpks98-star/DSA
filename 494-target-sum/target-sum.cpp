class Solution {
public:
    int solve(int index,int sum,int target,int off,vector<vector<int>> &dp,vector<int> &nums)
    {
        if(index==nums.size())
        {
            return (sum==target)?1:0;
        }
        if(dp[index][sum+off]!=-1)return dp[index][sum+off];
        int add=solve(index+1,sum+nums[index],target,off,dp,nums);
        int diff=solve(index+1,sum-nums[index],target,off,dp,nums);

        return dp[index][sum+off]=add+diff;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int num:nums)
        sum+=num;
        int offset=sum;
        if(abs(target)>sum)return 0;
        vector<vector<int>> dp(nums.size(),vector<int>(2*sum+1,-1));
        return solve(0,0,target,offset,dp,nums);

    }
};
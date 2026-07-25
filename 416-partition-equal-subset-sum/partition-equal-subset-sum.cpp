class Solution {
public:
    bool solve(int index,vector<int>&nums,vector<vector<int>>&dp,int target)
    {
        
        if(target==0)return true;
        if(index==nums.size())return false;
        if(dp[index][target]!=-1)return dp[index][target];
        bool take=false;
        if(nums[index]<=target)
        {
            take=solve(index+1,nums,dp,target-nums[index]);

        }
        bool skip=solve(index+1,nums,dp,target);
       return dp[index][target]=(take||skip);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums)
        sum+=i;
        if(sum%2!=0)return false;
        int n=nums.size();
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(0,nums,dp,target);
    }
};
class Solution {
public:
    int solve(int i,vector<int>&nums,vector<int>&dp,int end)
    {
        if(i>end)return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i]=max(nums[i]+solve(i+2,nums,dp,end),solve(i+1,nums,dp,end));
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int n=nums.size();
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        int case1=solve(0,nums,dp1,n-2);//ignoring last house
        int case2=solve(1,nums,dp2,n-1);//ignoring first house
        return max(case1,case2);
        
    }
};
//top down approach
class Solution {
public:
const int INF=1e9;
    int solve(int index,vector<int>&coins,int amount,vector<vector<int>>&dp)
    {
        int take=INF;
        if(amount==0)return 0;
        if(index==coins.size())return INF;
        if(dp[index][amount]!=-1)return dp[index][amount];

        if(coins[index]<=amount)
        {
           
                 take=1+solve(index,coins,amount-coins[index],dp);
           
        }
        int skip=solve(index+1,coins,amount,dp);
        dp[index][amount]=min(take,skip);
        
        return dp[index][amount];    
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans= solve(0,coins,amount,dp);
        if(ans>=INF)
        return -1;

        return ans;
    }
};
//top down approach
class Solution {
public:
const int INF=1e9;
    int solve(vector<int>&coins,int amount,vector<int>&dp)
    {
        
        
        if(amount==0)
        return 0;
        if(amount<0)
        return INF;
        int ans=INF;
        if(dp[amount]!=-1)
        return dp[amount];
            for(int coin:coins)
            {  
                     ans=min(ans,1+solve(coins,amount-coin,dp));
            }
        
       return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans= solve(coins,amount,dp);
        if(ans>=INF)
        return -1;

        return ans;
    }
};
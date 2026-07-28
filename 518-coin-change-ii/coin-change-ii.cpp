class Solution {
public:
    int solve(int index,int amount,vector<int>&coins,vector<vector<int>>&dp)
    {
        if(amount==0)return 1;
        if(index>=coins.size() )return 0;
       // ||amount<coins[index])return 0;
        if(dp[index][amount]!=-1)return dp[index][amount];

        int take=0;
        //  int skip;
        if(coins[index]<=amount)
        {
            take=solve(index,amount-coins[index],coins,dp);
        }
        int skip=0;
          skip=solve(index+1,amount,coins,dp);

        dp[index][amount]=(take+skip);
        return dp[index][amount];
        

    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans=solve(0,amount,coins,dp);
        // if(ans==0)return 0;
        return ans;
    }
};
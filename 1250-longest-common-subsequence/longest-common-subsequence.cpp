class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &dp,string &A,string &B)
    {
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(A[i]==B[j])
        {
            return dp[i][j]= 1+solve(i-1,j-1,dp,A,B);
        }
        else
        {
            return dp[i][j]= max(solve(i-1,j,dp,A,B),solve(i,j-1,dp,A,B));
        }

    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,dp,text1,text2);
    }
};
class Solution {
public:
    int solve(int index,string &s,vector<int>&dp)
    {
        if(index==s.size())return 1;
        if(s[index]=='0')return 0;
        if(dp[index]!=-1)return dp[index];
        int take_one_digit=solve(index+1,s,dp);
        int take_two_digit=0;
        if(index+1<s.size())
        {
            int num=(s[index]-'0')*10 + s[index+1]-'0';
            if(num>=10 && num<=26)
            {
                take_two_digit=solve(index+2,s,dp);
            }
        }
        return dp[index]=take_one_digit+take_two_digit;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return solve(0,s,dp);
    }
};
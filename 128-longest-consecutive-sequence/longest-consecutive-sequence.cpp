class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_set<int> st(nums.begin(),nums.end());
        for(int num:st)
        {
            if(st.find(num-1)==st.end())
            {
                int start=num;
                int count=1;

            
            while(st.find(start+1)!=st.end())
            {
                start++;
                count++;
            }
            
            ans=max(ans,count);
            }
        }return ans;
    }
};
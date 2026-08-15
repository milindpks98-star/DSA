class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0;
        int l=nums.size()-1;
        while(s<=l)
        {
            int mid=(s+l)/2;
            if(target==nums[mid])return mid;
            if(target<nums[mid])
            {
                l=mid-1;
            }
            else if(target>nums[mid])
            {
                s=mid+1;
            }
           
            
        }return s;
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int l=nums.size()-1;
        while(s<=l)
        {
            int mid=(s+l)/2;
            if(target==nums[mid])return mid;
            if(nums[s]<=nums[mid])
            {
                if(target>=nums[s] && target<nums[mid])
                {
                    l=mid-1;
                }
                else s=mid+1;
            }
            else 
            {
                if(target>nums[mid] && target<=nums[l])
                {
                    s=mid+1;
                }
                else l=mid-1;

            
            }
        }
        return -1;
    }
};
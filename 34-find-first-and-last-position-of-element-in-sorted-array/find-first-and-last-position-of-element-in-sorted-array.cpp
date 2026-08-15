class Solution {
public:
    int firstPos(vector<int> &nums,int target)
    {
        int s=0;
        int l=nums.size()-1;
        int first=-1;
        while(s<=l)
        {
            int mid=(s+l)/2;
            if(target==nums[mid])
            {
                first=mid;
                l=mid-1;

            }
            else if(target<nums[mid])
            l=mid-1;
            else s=mid+1;
        }return first;
    }
    int lastPos(vector<int>&nums,int target)
    {
        int s=0;
        int l=nums.size()-1;
        int last=-1;
        while(s<=l)
        {
            int mid=(s+l)/2;
            if(target==nums[mid])
            {
                last=mid;
                s=mid+1;
            }
            else if(target<nums[mid]) l=mid-1;
            else s=mid+1;
        }return last;

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstPos(nums,target);
        int last=lastPos(nums,target);
        return {first,last};
    }
};
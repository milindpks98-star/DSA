double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    // CHANGE 1
if(nums1Size > nums2Size)
    return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    int m=nums1Size;
    int n=nums2Size;

    int left=0;
    int right=m;
    while(left<=right)
    {
        int mid1=left+(right-left)/2;
        int mid2=(m+n+1)/2 - mid1;

        int maxleft1=(mid1==0)?INT_MIN:nums1[mid1-1];
        int minright1=(mid1==m)?INT_MAX:nums1[mid1];
        int maxleft2=(mid2==0)?INT_MIN:nums2[mid2-1];
        int minright2=(mid2==n)?INT_MAX:nums2[mid2];

        if(maxleft1<=minright2 && maxleft2<=minright1)
        {
            if((m+n)%2==1)
            {
                return (double)(maxleft1>maxleft2?maxleft1:maxleft2);
            }

            int maxleft=maxleft1>maxleft2?maxleft1:maxleft2;
            int minright=minright1<minright2?minright1:minright2;
            return (maxleft+minright)/2.0;
        }
        else if(maxleft1>minright2)
        {
            right=mid1-1;
        }
        else
        left=mid1+1;

    }return 0.0;
}
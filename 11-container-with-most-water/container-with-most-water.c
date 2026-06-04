int maxArea(int* height, int heightSize) {
    int left=0;int right=heightSize-1;
    int max=-1;
    int area1=-2,area2=-2;
    while(left<=right)
    {
        if(height[left]<height[right])
        {
            area1=height[left]*abs(right-left) ;
            left++;
        }
        else
        {
            area2=height[right]*abs(right-left);
            right--;
        }
        if(area1>max)
        {
            max=area1;

        }
        else if(area2>max)
        {
            max=area2;
        }
    }return max;
}
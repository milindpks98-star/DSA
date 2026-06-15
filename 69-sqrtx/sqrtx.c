int mySqrt(int x) {
    int sqrt=0;
    int left=1;
    int right=x;
    while(left<=right)
    {
        long long mid=left + (right - left)/2;
        long long square=mid*mid;
        if(square==x)
        {
        return mid;
        }
        else if(square<x)
        {
            sqrt=mid;
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return sqrt;
}
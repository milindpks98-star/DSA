#define max(a,b) (a>b?a:b) 
int lengthOfLongestSubstring(char* s) {
 
    int lastseen[256];
    int left=0;
    int maxlen=0;
    memset(lastseen,-1,256*sizeof(int));
    for(int right=0;s[right]!='\0';right++)
    {
        unsigned char current=(unsigned char)s[right];

        if(lastseen[current]>=left)
        {
            left=lastseen[current]+1;
        }

        lastseen[current]=right;
        maxlen=max(maxlen,right-left+1);

    }return maxlen;
}
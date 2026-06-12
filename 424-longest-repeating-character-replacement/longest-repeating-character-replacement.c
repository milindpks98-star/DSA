int characterReplacement(char* s, int k) {
    int left=0;
    int maxcount=0;
    int len=strlen(s);
    int count[26]={0};
    for(int right=0;right<len;right++)
    {
        count[s[right]-65]++;

        if(count[s[right]-65]>maxcount)
        {
            maxcount=count[s[right]-65];
        }

        int current_window_size=right-left+1;
        if(current_window_size-maxcount>k)
        {
            count[s[left]-65]--;
            left++;
        }
    }return len-left;
}
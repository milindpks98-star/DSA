class Solution {
public:
    int maxVowels(string s, int k) {
        int left=0;
        int maxvo=0;
        int vow=0;
        for(int right=0;right<s.size();right++)
        {
            if(s[right]=='a'||s[right]=='e'|| s[right]=='i' || s[right]=='o'||s[right]=='u')
            vow++;



            while(right-left+1>k)
            {
                 if(s[left]=='a'||s[left]=='e'||s[left]=='i'||s[left]=='o'||s[left]=='u')
                  vow--;
                left++;
               
            }
             maxvo=max(maxvo,vow);
        }
        return maxvo;
    }
};
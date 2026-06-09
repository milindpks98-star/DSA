int maxVowels(char* s, int k) {
   int maxvo=0;
   int max=0;
   int len=strlen(s);
   for(int i=0;i<k;i++)
   {
    if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
    {
        max++;
    }
   }
   maxvo=max;
   for(int i=k;s[i]!='\0';i++)
   {
    if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
    {
        max++;
    }
    if(s[i-k]=='a' || s[i-k]=='e' || s[i-k]=='i' || s[i-k]=='o' || s[i-k]=='u')
    {
        max--;
    }
    if(max>maxvo)
    {
        maxvo=max;
    }
   }

    return maxvo;
} 
      
   
    


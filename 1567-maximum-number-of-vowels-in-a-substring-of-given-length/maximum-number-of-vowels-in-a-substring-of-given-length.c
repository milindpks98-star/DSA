int maxVowels(char* s, int k) {
    int left=0;int right=0;
    int len=strlen(s);
            int max=0;
           for(int i=0;i<k;i++) 
           {
                if(s[i]=='a' || s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                {
                 max++;
           
                }
           } 
            int maxvo=max;
            for(int i=k;s[i]!='\0';i++)
            {
              if(s[i]=='a' || s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                {
                 max++;
           
                }

                if(s[i-k]=='a' || s[i-k]=='e'||s[i-k]=='i'||s[i-k]=='o'||s[i-k]=='u')
                {
                    max--;
                }
                if(max>maxvo)
                maxvo=max;
            }
            
            return (maxvo==-1?0:maxvo);
            
} 
      
   
    


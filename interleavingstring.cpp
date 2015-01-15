bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(),n=s2.length(),l=s3.length();
     //   int dp[m][n];
        vector<vector<bool> > dp(m+1,vector<bool>(n+1,false));
        if(m+n!=l) return false;
        if(m==0) return (s2.compare(s3)==0);
        if(n==0) return (s1.compare(s3)==0);
        dp[0][0]=1;
        int i,j;
        for(i=0;i<m;i++)
            dp[i+1][0]= s1[i]==s3[i];
        for(j=0;j<n;j++)
            dp[0][j+1]= s2[j]==s3[j];
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(s1[i]==s3[i+j+1] && dp[i][j+1])
                    dp[i+1][j+1]= true;
                if(s2[j]==s3[i+j+1] && dp[i+1][j])
                    dp[i+1][j+1]=true;
            }
        }
        return dp[m][n];
    //    return ((dp[m][n-1] && s2[n-1]==s3[l-1] )|| (dp[m-1][n] && s1[m-1]==s3[l-1])) ;
        
    }

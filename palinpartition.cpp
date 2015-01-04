class Solution {
public:
    int min(int a,int b)
    {
        return a<b?a:b;
    }
    int minCut(string s) {
        int len = s.length(),i,j,l,temp,var;
        if(len==1)
            return 0;
        vector<int> A(len);
        A[0]=0;
        vector<vector<int> > palin(len,vector<int>(len,-1));
        //int palin[len][len];
        for(i=0;i<len;i++)
            palin[i][i]=1;
        for(l=2;l<=len;l++)
        {
            for(i=0;i<len-l+1;i++)
            {
                j = i + l - 1;
                if(s[i]==s[j] && l==2)
                    palin[i][j] = 1;
                else if(s[i]==s[j] )
                    palin[i][j] = palin[i+1][j-1];
            }
        }
        for(i=1;i<len;i++)
        {
            A[i]=A[i-1]+1;
            if(palin[0][i]==1)
                A[i]=0;
            for(j=0;j<i;j++)
            {
                if(palin[j+1][i]==1)
                {
                    A[i] = min(A[j]+1,A[i]);
                }
            }
        }
        return A[len-1];
        
    }
};

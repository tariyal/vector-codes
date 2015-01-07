class Solution {
public:
     static bool comp(const int a , const int b)
    {
        return a<b;
    }
    vector<vector<int> > subsetsWithDup(vector<int> &s) {
        sort(s.begin(),s.end(),comp);
        vector<vector<int> >ans;
        vector<int>k;
        int i,j,size,count,l;
        ans.push_back(k);
        if(s.size()==0)
            return ans;
        for(i=0;i<s.size();i++)
        {
            size = ans.size();
            count=1;
            while(i+1<s.size() && s[i]==s[i+1])
                count++,i++;
            
            for(j=0;j<size;j++)
            {
                k = ans[j];
                l = count;
                while(l>0)
                {
                    l--;
                    k.push_back(s[i]);
                    ans.push_back(k);
                }
                    
            }
        }
        return ans;
    }
};

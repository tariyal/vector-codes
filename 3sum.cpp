class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
        if(num.size()<3)
            return ans;
        sort(num.begin(),num.end());
        for(int i=0;i<num.size()-2;i++)
        {
            if(i>0 && num[i]==num[i-1]) continue;
            mysum(num,i,ans);
        }
        return ans;
    }
    void mysum(vector<int> &a,int index,vector<vector<int> > &ans)
    {
        if(a[index]>0)
            return ;
        int j = a.size()-1,i=index+1,sum;
        while(i<j)
        {
            sum = a[index]+a[i]+a[j];
            if(sum>0)  j--;
            else if(sum<0)  i++;
            else 
            {
                pushans(a[index],a[i],a[j],ans),i++,j--;
                while(j>0 && a[j]==a[j+1])
                    j--;
                while(i<a.size()-1 && a[i]==a[i-1])
                    i++;
            }    
        }
    }
    void pushans(int &i ,int &j,int &k,vector<vector<int> > &ans)
    {
        vector<int> s;
        s.push_back(i);
        s.push_back(j);
        s.push_back(k);
        ans.push_back(s);
    }
};

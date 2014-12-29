class Solution {
public:
    static bool comparator(const int a , const int b)
    {
        return a<b;
    }
    vector<vector<int> > subsets(vector<int> &s) {
        sort(s.begin(),s.end(),comparator);
        vector<vector<int> > ans;
        int i,j,size;
        vector<int> k;
        ans.push_back(k);
        for(i=0;i<s.size();i++)
        {
            size = ans.size();
            for(j=0;j<size;j++)
            {
                k = ans[j];
                k.push_back(s[i]);
                ans.push_back(k);
            }
        }
        return ans;
    }
};

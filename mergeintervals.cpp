class Solution {
public:
    static bool comp(const Interval a,const Interval b )
    {
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval> &val) {
        std::sort(val.begin(),val.end(),comp);
        vector<Interval> ans;
        if(val.size()==0)
            return ans;
        ans.push_back(val[0]);
        int j=0,i;
        for(i=1;i<val.size();i++)
        {
            if(ans[j].end >= val[i].start)
                    ans[j].end =    val[i].end > ans[j].end ? val[i].end : ans[j].end;
            else
            {
                ans.push_back(val[i]);
                j++;
            }
            
        }
        return ans;
    }
};

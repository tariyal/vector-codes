class Solution {
public:
         int lengthOfLongestSubstring(string s) {
    //    unordered_map<char,int> mymap;
        vector<int> mymap(256,-1);
        int i,ans=0,start=-1;
        for(i=0;i<s.length();i++)
        {
            if( mymap[s[i]] != -1 && (mymap[s[i]]>start))
            {
                start=mymap[s[i]];
                mymap[s[i]]=i;
            }
            else
            {
                mymap[s[i]]=i;
                ans = max(i-start,ans);
            }
            
        }
        return ans;
    }
    
};

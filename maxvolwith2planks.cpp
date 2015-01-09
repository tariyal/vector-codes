class Solution {
public:
    int maxArea(vector<int> &a) {
        int i=0,j=a.size()-1;
        int ans=0,var;
        while(j>i)
        {
            if(a[i]>a[j]){
                var = a[j]*(j-i);
                j--;
            }
            else
            {
                var = a[i]*(j-i);
                i++;
            }
            ans=max(var,ans);
        }
        return ans;
    }
};

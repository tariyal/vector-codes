class Solution {
public:
    
    int longestConsecutive(vector<int> &a) {
        unordered_map< int ,bool > mymap; 
        int m,n,max =INT_MIN,i,count,k;
        for(i=0;i<a.size();i++)
            mymap[a[i]]=true;
        for(i=0;i<a.size();i++)
        {
            k = a[i];
            m = k-1,n= k+1;
            mymap.erase(k);
            count = 0;
            while(mymap.find(m)!=mymap.end())
            {
                mymap.erase(m);
                count++,m--;
            }
            while(mymap.find(n)!=mymap.end())
            {
                mymap.erase(n);
                count++,n++;
            }
            if(max<count)
                max = count;
        }
        return max+1;

    }
};

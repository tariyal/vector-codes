//my best code till date too
class Solution {
public:
    
    int longestConsecutive(vector<int> &a) {
        map< int , pair<int,int> > mymap;  
        pair<int,int> k;
        int m,n,max =INT_MIN;
        for(int i=0;i<a.size();i++)
        {
            if(mymap.find(a[i])!=mymap.end())
                continue;
            
            if(mymap.find(a[i]+1) == mymap.end() && mymap.find(a[i]-1)==mymap.end() )
            {
                m = a[i] , n = a[i];
            }
            else if(mymap.find(a[i]+1)==mymap.end())
            {
                 m = mymap[a[i]-1].first,n=a[i];
                 mymap[m].second = a[i];
            }
            else if(mymap.find(a[i]-1)==mymap.end())
            {
                 m = a[i],n = mymap[a[i]+1].second;
                 mymap[n].first = a[i];
            }
            else
            {
                 m = mymap[a[i]-1].first,n = mymap[a[i]+1].second;
                 mymap[m].second = n;
                 mymap[n].first = m;
            }
            k.first = m,k.second = n;
            mymap[a[i]] = k;
            if(max<n-m)
                max = n-m;
        }
        return max+1;
    }
        
};

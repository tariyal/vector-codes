class Solution {
public:
    struct comparator1
    {
        bool operator()(pair<int,int> a,pair<int,int> b)
           { return a.first >= b.first;}
    };
    struct comparator2
    {
        bool operator()(pair<int,int> a,pair<int,int> b)
            {return a.first <= b.first;}
    };
    vector<int> twoSum(vector<int> &numbers, int sum) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparator1> min;
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparator2> max;
        pair<int,int> k;
        int mysum,a,b;
        vector<int> ans;
        int size =numbers.size();
        if(size<2)
            return ans;
        for(int i=0;i<size;i++)
        {
            k = make_pair(numbers[i],i+1);
            min.push(k);
            max.push(k);
        }
        while(!min.empty() && !max.empty())
        {
            mysum = min.top().first + max.top().first;
            if(mysum > sum)
                max.pop();
            else if( mysum < sum)
                min.pop();
            else
            {
                a = min.top().second ;
                b = max.top().second ;
                if(a>b)
                    ans.push_back(b),ans.push_back(a);
                else
                    ans.push_back(a),ans.push_back(b);
                break;
            }
        }
        return ans;
        
    }

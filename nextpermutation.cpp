class Solution {
public:
    void rev(vector<int> &num,int start,int end)
    {
        int temp;
        while(start<end)
        {
            temp = num[start];
            num[start]=num[end];
            num[end]=temp;
            start++,end--;
        }
    }
    void nextPermutation(vector<int> &num) {
        int n=num.size();
        int i,j,temp,start;
        for(i=n-2;i>=0;i--)
        {
            if(num[i]<num[i+1])
                break;
        }
        if(i<0)
            start=0;
        else
        {
            start=i+1;
            for(j=n-1;j>i;j--)
            {
                if(num[j]>num[i])
                {
                    temp = num[i];
                    num[i]=num[j];
                    num[j]=temp;
                    break;
                }    
                
            }
        }
        rev(num,start,n-1);
        //sort(num.begin()+start,num.end());
        return ;
    }
};

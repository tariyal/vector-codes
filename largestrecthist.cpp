    int largestRectangleArea(vector<int> &a) {
        int n = a.size(),ans=0,i,var;
        stack<int> st;
        vector<int> front(n,0);
        st.push(0);        
        for(i=1;i<n;i++)
        {
               while(!st.empty() && a[st.top()] >= a[i])
                    st.pop();

                if(!st.empty())
                    front[i]=i-st.top()-1;
                else
                    front[i]=i;
                st.push(i);   
            
        }
        while(!st.empty())
            st.pop();
        st.push(n-1);
        for(i=n-2;i>=0;i--)
        {
               while(!st.empty() && a[st.top()] >= a[i])
                    st.pop();
                if(!st.empty())
                    front[i]= front[i]+ (st.top()-i-1);
                else
                    front[i]= front[i]+ (n-i-1);
                st.push(i);
        }
        for(i=0;i<n;i++)
            ans=max(ans,(front[i]+1)*a[i]);
        return ans;
    }
